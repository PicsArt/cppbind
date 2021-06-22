"""
Implements ieg api parser on cxx comment
"""
import distutils.util
import glob
import os
import re
from collections import defaultdict
from collections import OrderedDict
from types import SimpleNamespace

import yaml
from jinja2.exceptions import UndefinedError as JinjaUndefinedError

from iegen.common import JINJA_ENV
from iegen.common.error import Error
from iegen.common.yaml_process import UniqueKeyLoader, YamlKeyDuplicationError
from iegen.ir.ast import Node, RootNode
from iegen.utils.clang import extract_pure_comment, join_type_parts
from iegen import default_config


class APIParser(object):
    API_START_KW = default_config.api_start_kw

    ALL_LANGUAGES = ['swift', 'java', 'python', 'kotlin']
    ALL_PLATFORMS = ['android', 'ios', 'linux', 'mac', 'win']

    ROOT_SECTION_KEY = 'vars'
    DIR_SECTION_KEY = 'dir_vars'
    FILE_SECTION_KEY = 'file_vars'
    TYPE_SECTION_KEY = 'type_vars'

    VARS_RULE_KEY = 'vars'
    TYPE_RULE_KEY = 'type'
    DIR_RULE_KEY = 'dir'
    FILE_RULE_KEY = 'file'
    SUB_RULE_KEY = ':'

    def __init__(self, attributes, languages=None, platforms=None, parser_config=None):
        self.attributes = attributes
        self.languages = list(languages or APIParser.ALL_LANGUAGES)
        self.platforms = platforms or APIParser.ALL_PLATFORMS
        self.api_type_attributes = APIParser.build_api_type_attributes(parser_config)

    @staticmethod
    def separate_pure_and_api_comment(raw_comment, index=None):
        index = index or raw_comment.find(APIParser.API_START_KW)
        if index == -1:
            return raw_comment, None
        return extract_pure_comment(raw_comment, index), raw_comment[index + len(APIParser.API_START_KW)::]

    def parse_comments(self, api_section, ctx, location=None):
        """
        Parse comment to extract API command and its attributes
        """
        if api_section is None:
            return None, OrderedDict()
        api_section = JINJA_ENV.from_string(api_section).render(ctx)
        SKIP_REGEXPR = r'^[\s*/]*$'

        lines = api_section.splitlines()
        filtered = list(filter(lambda x: not re.match(SKIP_REGEXPR, x), lines))

        if not filtered:
            Error.critical("API comments are empty",
                           location.file_name if location else None,
                           location.line_number if location else None)

        comment_prefix = re.search(r'\s*\*?\s*', filtered[0])
        yaml_indent_cnt = comment_prefix.end()

        yaml_lines = []
        for line in filtered:
            if len(line) <= yaml_indent_cnt:
                Error.critical("Invalid yaml format",
                               location.file_name if location else None,
                               location.line_number if location else None)
            yaml_lines.append(line[yaml_indent_cnt:])
        yaml_lines = '\n'.join(yaml_lines)

        try:
            attrs = yaml.load(yaml_lines, Loader=UniqueKeyLoader)
        except yaml.YAMLError as e:
            Error.critical("Error while scanning yaml style comments: {e}",
                           location.file_name if location else None,
                           location.line_number if location else None)

        return self.parse_api_attrs(attrs, location)

    def parse_api(self, name, api_section, location, ctx=None):
        if api_section:
            return self.parse_comments(api_section, ctx, location)
        else:
            return self.parse_yaml_api(name, ctx, location)

    def parse_yaml_api(self, name, ctx=None, location=None):
        ctx = ctx or {}
        attrs = self.api_type_attributes.get(name)
        if attrs:
            api_attrs = attrs.attr
            if api_attrs:
                # for dir api pass yaml file path
                location = location or SimpleNamespace(file_name=attrs.file,
                                                       line_number=None)
                try:
                    api_attrs = APIParser.eval_attr_template(api_attrs, ctx)
                except JinjaUndefinedError as e:
                    Error.critical(f"Jinja evaluation error: {e}", location.file_name, location.line_number)
                return self.parse_api_attrs(api_attrs, location)


    def parse_api_attrs(self, attrs, location):
        api = None
        attr_dict = OrderedDict()
        ATTR_KEY_REGEXPR = rf"[\s*/]*(?:({'|'.join(self.platforms)})\.)?(?:({'|'.join(self.languages)})\.)?([^\d\W]\w*)\s*$"

        # Data structure to keep previous priorities
        prev_priors = defaultdict(lambda: defaultdict(lambda: [0]))
        for attr_key, value in attrs.items():
            m = re.match(ATTR_KEY_REGEXPR, attr_key)
            if not m:
                Error.critical({attr_key: value},
                               location.file_name if location else None,
                               location.line_number if location else None)
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

            if attr == 'action':
                api = value
                attr_plat_dict = attr_dict.setdefault(attr, OrderedDict())
                for plat in platform:
                    attr_lang_dict = attr_plat_dict.setdefault(plat, OrderedDict())
                    for lang in language:
                        attr_lang_dict[lang] = value
            else:
                api = api or Node.API_NONE
                # now check attribute
                # attribute should be in attributes
                if attr not in self.attributes:
                    Error.critical(f"Attribute {attr} is not specified. It should be one of {set(self.attributes)}.",
                                   location.file_name if location else None,
                                   location.line_number if location else None)

                array = self.attributes[attr].get('array', False)
                value = self.parse_attr(attr, value)

                if array:
                    if not isinstance(value, list):
                        value = [value]
                elif isinstance(value, list):
                    Error.critical(f"Wrong attribute type: {attr} cannot be array",
                                   location.file_name if location else None,
                                   location.line_number if location else None)

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

        return api, attr_dict

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

    @staticmethod
    def has_api(raw_comment):
        """
        Tests whether or not comment has API section.
        """
        return raw_comment and APIParser.API_START_KW in raw_comment

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
        def flatten_dict(src_dict, section_key, ancestors):
            APIParser.validate_section_keys(src_dict, section_key)
            APIParser.TYPE_RULE_KEY in src_dict and ancestors.append(src_dict[APIParser.TYPE_RULE_KEY])
            try:
                if APIParser.VARS_RULE_KEY in src_dict:
                    flat_key = APIParser._get_key(current_file=current_file,
                                                  src_dict=src_dict,
                                                  ancestors=ancestors)
                    if flat_key in api_type_attributes:
                        raise YamlKeyDuplicationError(
                            f"Definition with duplicate '{flat_key}' key in {current_file},\n"
                            f"which already has been previously defined in {api_type_attributes[flat_key].file}")
                    api_type_attributes[flat_key] = SimpleNamespace(attr=src_dict[APIParser.VARS_RULE_KEY],
                                                                    file=current_file)
                if APIParser.SUB_RULE_KEY in src_dict:
                    for sub in src_dict[APIParser.SUB_RULE_KEY]:
                        flatten_dict(sub, section_key, ancestors)
            finally:
                APIParser.TYPE_RULE_KEY in src_dict and ancestors.pop()

        if APIParser.ROOT_SECTION_KEY in attrs:
            if RootNode.ROOT_KEY in api_type_attributes:
                raise YamlKeyDuplicationError(f"Redefinition of '{APIParser.ROOT_SECTION_KEY}' section in {current_file} file, "
                                              f"which must be uniquely specified only in one file.\n"
                                              f"It was previously defined in {api_type_attributes[RootNode.ROOT_KEY].file} file.")
            api_type_attributes[RootNode.ROOT_KEY] = SimpleNamespace(attr=attrs[APIParser.ROOT_SECTION_KEY],
                                                                     file=current_file)

        for section_key in (APIParser.DIR_SECTION_KEY, APIParser.FILE_SECTION_KEY, APIParser.TYPE_SECTION_KEY):
            if section_key in attrs:
                for item in attrs[section_key]:
                    flatten_dict(item, section_key, [])

    @staticmethod
    def _get_key(src_dict, current_file, ancestors):
        # dir
        if APIParser.DIR_RULE_KEY in src_dict:
            dir_name = src_dict[APIParser.DIR_RULE_KEY]
            if os.path.isabs(dir_name):
                # if an absolute path is specified then we assume it's absolute to current dir
                return dir_name.replace('/', '', 1) or '.'
            else:
                return os.path.relpath(
                    os.path.abspath(os.path.join(os.path.dirname(current_file), dir_name)),
                    os.getcwd())
        # file
        elif APIParser.FILE_RULE_KEY in src_dict:
            file_name = src_dict[APIParser.FILE_RULE_KEY]
            if os.path.isabs(file_name):
                # if an absolute path is specified then we assume it's absolute to current dir
                flat_key = file_name.replace('/', '', 1)
                return os.path.join(flat_key, os.getcwd())
            else:
                return os.path.abspath(os.path.join(os.path.dirname(current_file), file_name))
        # type
        elif APIParser.VARS_RULE_KEY in src_dict:
            return join_type_parts(ancestors)

    @classmethod
    def validate_section_keys(cls, src_dict, section_key):
        if section_key == cls.FILE_SECTION_KEY and (cls.DIR_RULE_KEY in src_dict or cls.TYPE_RULE_KEY in src_dict):
            Error.critical(f"API file section definition can only contain '{cls.FILE_RULE_KEY}' key")
        elif section_key == cls.DIR_SECTION_KEY and (cls.FILE_RULE_KEY in src_dict or cls.TYPE_RULE_KEY in src_dict):
            Error.critical(f"API dir section definition can only contain '{cls.DIR_RULE_KEY}' key")
        elif section_key == cls.TYPE_SECTION_KEY and (cls.DIR_RULE_KEY in src_dict or cls.FILE_RULE_KEY in src_dict):
            Error.critical(f"API type section definition can only contain '{cls.TYPE_RULE_KEY}' key")

    @staticmethod
    def eval_attr_template(attrs, ctx):
        if isinstance(attrs, dict):
            return yaml.load(JINJA_ENV.from_string(yaml.dump(attrs)).render(ctx), Loader=UniqueKeyLoader)
        return yaml.load(JINJA_ENV.from_string(attrs).render(ctx), Loader=UniqueKeyLoader)
