"""
Implements ieg api parser on cxx comment
"""
import distutils.util
import glob
import re
import os
import yaml
from collections import defaultdict
from collections import OrderedDict
from types import SimpleNamespace
from jinja2.exceptions import UndefinedError as JinjaUndefinedError

from iegen.common import JINJA_ENV
from iegen.common.error import Error
from iegen.common.yaml_process import UniqueKeyLoader, YamlKeyDuplicationError
from iegen.utils.clang import extract_pure_comment, get_full_displayname, join_type_parts


class APIParser(object):
    ALL_LANGUAGES = ['swift', 'java', 'python', 'kotlin']
    ALL_PLATFORMS = ['android', 'ios', 'linux', 'mac', 'win']
    RULE_TITLE_KEY = 'gen_actions'
    RULE_TYPE_KEY = 'type'
    RULE_DIR_KEY = 'dir'
    RULE_RULE_KEY = 'rule'
    RULE_SUB_KEY = ':'

    def __init__(self, attributes, api_start_kw, languages=None, platforms=None, parser_config=None):
        self.attributes = attributes
        self.api_start_kw = api_start_kw
        self.languages = list(languages or APIParser.ALL_LANGUAGES)
        self.platforms = platforms or APIParser.ALL_PLATFORMS
        self.api_type_attributes = APIParser.build_api_type_attributes(parser_config)

    def parse_comments(self, raw_comment, location=None):
        """
        Parse comment to extract API command and its attributes
        """
        index = raw_comment.find(self.api_start_kw)
        if index == -1:
            return None, OrderedDict()
        pure_comment = extract_pure_comment(raw_comment, index)
        SKIP_REGEXPR = r'^[\s*/]*$'

        api_section = raw_comment[index + len(self.api_start_kw)::]
        lines = api_section.splitlines()
        filtered = list(filter(lambda x: not re.match(SKIP_REGEXPR, x), lines))

        if not filtered:
            raise Exception("API comments are empty")
        comment_prefix = re.search(r'\s*\*?\s*gen:', filtered[0])
        if not comment_prefix:
            raise Exception("API comments must start with 'gen' attribute")
        yaml_indent_cnt = comment_prefix.end() - len('gen:')

        yaml_lines = []
        for line in filtered:
            if len(line) <= yaml_indent_cnt:
                raise Exception("Invalid yaml format")
            yaml_lines.append(line[yaml_indent_cnt:])
        yaml_lines = '\n'.join(yaml_lines)

        try:
            attrs = yaml.load(yaml_lines, Loader=UniqueKeyLoader)
        except yaml.YAMLError as e:
            raise Exception(f"Error while scanning yaml style comments: {e}")

        return self.parse_api_attrs(attrs, location, pure_comment)


    def parse_api(self, cursor, ctx=None):
        location = SimpleNamespace(file_name=cursor.extent.start.file.name,
                                   line_number=cursor.extent.start.line)
        if self.has_api(cursor.raw_comment):
            return self.parse_comments(JINJA_ENV.from_string(cursor.raw_comment).render(ctx), location)
        else:
            return self.parse_yaml_api(get_full_displayname(cursor), ctx, location)

    def parse_yaml_api(self, name, ctx, location=None):
        attrs = self.api_type_attributes.get(name)
        if attrs:
            api_attrs = attrs.attr
            if api_attrs:
                # for dir api pass file and the first line
                location = location or SimpleNamespace(file_name=attrs.file,
                                                       line_number=None)
                try:
                    api_attrs = APIParser.eval_attr_template(api_attrs, ctx)
                except JinjaUndefinedError as e:
                    Error.critical(f"Jinja evaluation error: {e}", location.file_name, location.line_number)
                return self.parse_api_attrs(api_attrs, location)

    def yaml_api_file_name(self, name):
        attrs = self.api_type_attributes.get(name)
        if attrs:
            return attrs.file
        return None

    def parse_api_attrs(self, attrs, location, pure_comment=None):
        api = None
        attr_dict = OrderedDict()
        ATTR_KEY_REGEXPR = rf"[\s*/]*(?:({'|'.join(self.platforms)})\.)?(?:({'|'.join(self.languages)})\.)?([^\d\W]\w*)\s*$"

        # Data structure to keep previous priorities
        prev_priors = defaultdict(lambda: defaultdict(lambda: [0]))
        for attr_key, value in attrs.items():
            m = re.match(ATTR_KEY_REGEXPR, attr_key)
            if not m:
                # error
                raise Exception({attr_key: value})
            platform, language, attr = m.groups()

            prior = APIParser.get_priority(platform, language)

            if language:
                language = [language]
            else:
                language = self.languages + ['__all__']

            if platform:
                platform = [platform]
            else:
                platform = self.platforms + ['__all__']

            if api is None and attr == 'gen':
                api = value
            else:
                # now check attribute
                # attribute should be in attributes
                if attr not in self.attributes:
                    raise Exception(f"Attribute {attr} is not specified. It should be one of {set(self.attributes)}.")

                array = self.attributes[attr].get('array', False)
                value = self.parse_attr(attr, value)

                if array:
                    if not isinstance(value, list):
                        value = [value]
                elif isinstance(value, list):
                    raise Exception(f"Wrong attribute type: {attr} cannot be array")

                attr_plat_dict = attr_dict.setdefault(attr, OrderedDict())
                for plat in platform:
                    attr_lang_dict = attr_plat_dict.setdefault(plat, OrderedDict())
                    for lang in language:
                        curr_max_prior = max(prev_priors[attr][(plat, lang)])
                        # overwrite the value only if the current option has higher priority than all previous ones.
                        if prior > curr_max_prior:
                            attr_lang_dict[lang] = value
                        # If we have this case it means we have a conflict of options: plat.lang and lang.plat
                        if prior in prev_priors[attr][(plat, lang)]:
                            Error.error(f"Conflicting attributes: attributes like platform.attr and "
                                        f"language.attr cannot be defined together: {lang + '.' + attr, plat + '.' + attr}",
                                        location.file_name, location.line_number)
                        prev_priors[attr][(plat, lang)].append(prior)

        return api, attr_dict, pure_comment

    def parse_attr(self, attr_name, attr_value):
        attr_type = self.attributes[attr_name].get('type', None)
        if isinstance(self.attributes[attr_name].get('default'), bool) or attr_type == 'bool':
            return bool(distutils.util.strtobool(str(attr_value)))

        if attr_type == 'dict':
            if not isinstance(attr_value, dict):
                raise Exception(f"Wrong attribute type: {type(attr_value)}, it must be dictionary")
            if attr_name == 'template':
                for attrs in attr_value.values():
                    for attr in attrs:
                        if not isinstance(attr, dict) or not 'type' in attr:
                            raise Exception(
                                f"Wrong template attribute style: {attr_value}, template must have mandatory 'type' attribute")
        # default string type
        return attr_value

    def has_api(self, raw_comment):
        """
        Tests whether or not comment has API section.
        """
        return raw_comment and self.api_start_kw in raw_comment


    @staticmethod
    def get_priority(plat, lang):
        """
        A method to get priority of platform/language specific attribute:
        Priorities sorted descending: platform.language.attr, [language|platform].attr, attr
        """
        if plat is None and lang is None:
            return 1
        if plat is None or lang is None:
            return 2
        return 3

    @staticmethod
    def build_api_type_attributes(parser_config):
        if not hasattr(parser_config, 'api_type_attributes_glob'):
            return {}

        files = set()
        for file in parser_config.api_type_attributes_glob.split(','):
            files_glob = glob.glob(file.strip(), recursive=True)
            for fp in files_glob:
                files.add(os.path.abspath(fp))

        api_type_attributes = {}
        for current_file in list(files):
            try:
                attrs = yaml.load(open(current_file), Loader=UniqueKeyLoader)
            except yaml.YAMLError as e:
                raise yaml.YAMLError(f"Wrong yaml format: {current_file}: {e}")

            APIParser.update_api_type_attributes(attrs, current_file, api_type_attributes)

        return api_type_attributes

    @staticmethod
    def update_api_type_attributes(attrs, current_file, api_type_attributes):
        _title = APIParser.RULE_TITLE_KEY
        _type = APIParser.RULE_TYPE_KEY
        _rule = APIParser.RULE_RULE_KEY
        _sub = APIParser.RULE_SUB_KEY
        _dir = APIParser.RULE_DIR_KEY

        def flatten_dict(src_dict, ancestors):
            assert (_type in src_dict) ^ (_dir in src_dict), f'{_dir} and {_type} are mutually exclusive.'
            if _type in src_dict or _dir in src_dict:
                _type in src_dict and ancestors.append(src_dict[_type])
                _dir in src_dict and ancestors.append(src_dict[_dir])
                try:
                    if _rule in src_dict:
                        if _type in src_dict:
                            flat_key = join_type_parts(ancestors)
                        else:
                            _dir_name = src_dict[_dir]
                            if os.path.isabs(_dir_name):
                                # if an absolute path is specified then we assume it's absolute to current dir
                                flat_key = _dir_name.replace('/', '', 1)
                            else:
                                flat_key = os.path.relpath(
                                    os.path.abspath(os.path.join(os.path.dirname(current_file), _dir_name)),
                                    os.getcwd())
                        if flat_key in api_type_attributes:
                            raise YamlKeyDuplicationError(
                                f"Definition with duplicate '{flat_key}' key in {current_file},\n"
                                f"which already has been previously defined in {api_type_attributes[flat_key].file}")
                        api_type_attributes[flat_key] = SimpleNamespace(attr=src_dict[_rule],
                                                                        file=current_file)
                    if _sub in src_dict:
                        for sub in src_dict[_sub]:
                            flatten_dict(sub, ancestors)
                finally:
                    ancestors.pop()

        if not _title in attrs:
            return

        for item in attrs[_title]:
            flatten_dict(item, [])

    @staticmethod
    def eval_attr_template(attrs, ctx):
        if isinstance(attrs, dict):
            return yaml.load(JINJA_ENV.from_string(yaml.dump(attrs)).render(ctx), Loader=UniqueKeyLoader)
        return yaml.load(JINJA_ENV.from_string(attrs).render(ctx), Loader=UniqueKeyLoader)
