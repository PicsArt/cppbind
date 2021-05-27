"""
Implements ieg api parser on cxx comment
"""
import glob
import distutils.util
import re
import yaml
import os
from types import SimpleNamespace
from collections import OrderedDict
from iegen.common.yaml_process import UniqueKeyLoader, YamlKeyDuplicationError

from iegen.utils.clang import extract_pure_comment, get_full_displayname, join_type_parts
import clang.cindex as cli


class APIParser(object):
    ALL_LANGUAGES = ['swift', 'java', 'python', 'kotlin']
    RULE_TITLE_KEY = 'gen_actions'
    RULE_TYPE_KEY = 'type'
    RULE_RULE_KEY = 'rule'
    RULE_SUB_KEY = ':'

    def __init__(self, attributes, api_start_kw, languages=None, parser_config=None):
        self.attributes = attributes
        self.api_start_kw = api_start_kw
        self.languages = languages or APIParser.ALL_LANGUAGES
        self.languages = list(self.languages)
        self.api_type_attributes = APIParser.build_api_type_attributes(parser_config)

    def parse_comments(self, raw_comment):
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

        return self.parse_api_attrs(attrs, pure_comment)


    def parse_api(self, cursor):
        if self.has_api(cursor.raw_comment):
            return self.parse_comments(cursor.raw_comment)
        else:
            api_attrs = self.get_external_api_attrs(cursor)
            if api_attrs:
                return self.parse_api_attrs(api_attrs)


    def parse_api_attrs(self, attrs, pure_comment=None):
        api = None
        attr_dict = OrderedDict()
        ATTR_KEY_REGEXPR = rf"[\s*/]*(?:({'|'.join(self.languages)})\.)?([^\d\W]\w*)\s*$"

        for attr_key, value in attrs.items():
            m = re.match(ATTR_KEY_REGEXPR, attr_key)
            if not m:
                # error
                raise Exception({attr_key: value})
            language, attr = m.groups()

            if language:
                language = [language]
            else:
                language = self.languages + ['__all__']

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

                for lang in language:
                    att_lang_dict = attr_dict.setdefault(attr, OrderedDict())
                    if array or len(language) == 1 or lang not in att_lang_dict:
                        att_lang_dict[lang] = value

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
                            raise Exception(f"Wrong template attribute style: {attr_value}, template must have mandatory 'type' attribute")
        # default string type
        return attr_value

    def has_api(self, raw_comment):
        """
        Tests whether or not comment has API section.
        """
        return raw_comment and self.api_start_kw in raw_comment

    def get_external_api_attrs(self, cursor):
        if cursor.kind in [cli.CursorKind.CLASS_DECL, cli.CursorKind.STRUCT_DECL,
                           cli.CursorKind.CXX_METHOD, cli.CursorKind.FUNCTION_TEMPLATE,
                           cli.CursorKind.CONSTRUCTOR, cli.CursorKind.CLASS_TEMPLATE,
                           cli.CursorKind.ENUM_DECL]:
            attrs = self.api_type_attributes.get(get_full_displayname(cursor))
            if attrs:
                return attrs.attr

    @staticmethod
    def build_api_type_attributes(parser_config):
        if not hasattr(parser_config, 'api_type_attributes_dir'):
            return {}

        files = set()
        for file in parser_config.api_type_attributes_dir.split(','):
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

        def flatten_dict(src_dict, ancestors):
            if _type in src_dict:
                ancestors.append(src_dict[_type])
                try:
                    if _rule in src_dict:
                        flat_key = join_type_parts(ancestors)
                        if flat_key in api_type_attributes:
                            raise YamlKeyDuplicationError(f"Definition with duplicate '{flat_key}' key in {current_file},\n"
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
