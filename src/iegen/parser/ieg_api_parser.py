"""
Implements ieg api parser on cxx comment
"""
import distutils.util
import re
import yaml
import os
from types import SimpleNamespace
from collections import OrderedDict
from iegen.common.yaml_process import UniqueKeyLoader

from iegen.utils.clang import extract_pure_comment, get_full_displayname, join_type_parts
import clang.cindex as cli


class APIParser(object):
    ALL_LANGUAGES = ['swift', 'java', 'python', 'kotlin']
    RULE_KEYS = {
        'title': 'gen_actions',
        'node': 'type',
        'action': 'rule',
        'children': 'sub'
    }

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
            api_attrs = self.build_external_api_attrs(cursor)
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
        # default string type
        return attr_value

    def has_api(self, raw_comment):
        """
        Tests whether or not comment has API section.
        """
        return raw_comment and self.api_start_kw in raw_comment

    def build_external_api_attrs(self, cursor):
        if cursor.kind in [cli.CursorKind.CLASS_DECL, cli.CursorKind.STRUCT_DECL, cli.CursorKind.CXX_METHOD,
                           cli.CursorKind.FUNCTION_TEMPLATE, cli.CursorKind.CONSTRUCTOR]:
            attrs = self.api_type_attributes.get(get_full_displayname(cursor))
            if attrs:
                return attrs.attr

    @staticmethod
    def build_api_type_attributes(parser_config):
        if not hasattr(parser_config, 'api_type_attributes_dir'):
            return {}

        api_type_attributes_dir = parser_config.api_type_attributes_dir
        if not os.path.isdir(api_type_attributes_dir):
            raise Exception(f"Wrong api comment directory path: {api_type_attributes_dir}")

        api_type_attributes = {}
        for root, dirs, files, in os.walk(api_type_attributes_dir):
            for file in files:
                current_file = os.path.join(root, file)
                try:
                    attrs = yaml.load(open(current_file), Loader=UniqueKeyLoader)
                except yaml.YAMLError as e:
                    raise Exception(f"Wrong yaml format: {os.path.join(root, file)}: {e}")

                APIParser.update_api_type_attributes(attrs, current_file, api_type_attributes)

        return api_type_attributes

    @staticmethod
    def update_api_type_attributes(attrs, current_file, api_type_attributes):
        title = APIParser.RULE_KEYS['title']
        node = APIParser.RULE_KEYS['node']
        action = APIParser.RULE_KEYS['action']
        children = APIParser.RULE_KEYS['children']

        def flatten_dict(src_dict):
            res_dict = {}
            if node in src_dict:
                if action in src_dict:
                    res_dict[src_dict[node]] = SimpleNamespace(attr=src_dict[action],
                                                               file=current_file)
                if children in src_dict:
                    for sub in src_dict[children]:
                        for key, val in flatten_dict(sub).items():
                            flat_key = join_type_parts([src_dict[node], key])
                            if flat_key in res_dict:
                                raise Exception(f"Definition with duplicate '{key}' key in {current_file}")
                            res_dict[flat_key] = val
            return res_dict

        if not title in attrs:
            return

        for item in attrs[title]:
            flat_dict = flatten_dict(item)
            for key, val in flat_dict.items():
                if key in api_type_attributes:
                    raise Exception(f"Definition with duplicate '{key}' key in {current_file}, "
                                    f"which already has been previously defined in {api_type_attributes[key].file}")
                api_type_attributes[key] = val
