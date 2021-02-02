"""
Implements ieg api parser on cxx comment
"""
import distutils.util
import json
import re
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
        ATTR_REGEXPR =\
            rf"[\s*/]*(?:({'|'.join(self.languages)})\.)?([^\d\W]\w*)\s*:\s*(.+)$"
        SKIP_REGEXPR = r'^[\s*/]*$'

        api_section = raw_comment[index + len(self.api_start_kw)::]
        lines = api_section.splitlines()
        filtered = filter(lambda x: not re.match(SKIP_REGEXPR, x), lines)
        for line in filtered:

            m = re.match(ATTR_REGEXPR, line)
            if not m:
                # error
                raise Exception(line)
            language, attr, value = m.groups()
            value = value.strip()

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

                if attr in attr_dict and not array:
                    # redefinition or array
                    raise Exception(f"Attribute {attr} is defined in multiple places.")

                attr_type = self.attributes[attr].get('type', None)
                if isinstance(self.attributes[attr]['default'], bool) or attr_type == 'bool':
                    value = bool(distutils.util.strtobool(value))

                if attr_type == 'json':
                    value = json.loads(value)

                for lang in language:
                    att_lang_dict = attr_dict.setdefault(attr, OrderedDict())
                    if array:
                        att_lang_dict.setdefault(lang, []).append(value)
                    else:
                        att_lang_dict[lang] = value

        return api, attr_dict, pure_comment

    def has_api(self, raw_comment):
        """
        Tests whether or not comment has API section.
        """
        return raw_comment and self.api_start_kw in raw_comment
