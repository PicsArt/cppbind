"""
Implements ieg api parser on cxx comment
"""
import distutils.util
import json
import re
import yaml
from collections import OrderedDict

from iegen.utils.clang import extract_pure_comment


class APIParser(object):
    ALL_LANGUAGES = ['swift', 'java', 'python', 'kotlin']

    def __init__(self, attributes, api_start_kw, languages=None):
        self.attributes = attributes
        self.api_start_kw = api_start_kw
        self.languages = languages or APIParser.ALL_LANGUAGES
        self.languages = list(self.languages)

    def parse(self, raw_comment):
        """
        Parse comment to extract API command and its attributes
        """
        api = None
        attr_dict = OrderedDict()

        index = raw_comment.find(self.api_start_kw)
        if index == -1:
            return api, attr_dict
        pure_comment = extract_pure_comment(raw_comment, index)
        # else
        ATTR_KEY_REGEXPR = rf"[\s*/]*(?:({'|'.join(self.languages)})\.)?([^\d\W]\w*)\s*$"
        SKIP_REGEXPR = r'^[\s*/]*$'

        api_section = raw_comment[index + len(self.api_start_kw)::]
        lines = api_section.splitlines()
        filtered = list(filter(lambda x: not re.match(SKIP_REGEXPR, x), lines))

        if not filtered:
            raise Exception("API comments must start with 'gen' attribute")
        comment_prefix = re.search(r'\s*\*?\s*gen:', filtered[0])
        if not comment_prefix:
            raise Exception("API comments must start with 'gen' attribute")
        yaml_indent_cnt = comment_prefix.end() - len('gen:')

        yaml_lines = '\n'.join([line[yaml_indent_cnt:] for line in filtered])

        try:
            attrs = yaml.load(yaml_lines, Loader=yaml.Loader)
        except yaml.YAMLError as e:
            raise Exception(f"Error while scanning yaml style comments: {e}")

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

                if attr in attr_dict and not array and len(language) != 1 and '__all__' in attr_dict[attr]:
                    # redefinition for all
                    raise Exception(f"Attribute {attr} is defined multiple times.")

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
