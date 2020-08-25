"""
Implements ieg api parser on cxx comment
"""
import re
from collections import OrderedDict


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

                for lang in language:
                    attr_dict.setdefault(attr,
                                         OrderedDict())[lang] = value

        return api, attr_dict

    def has_api(self, raw_comment):
        """
        Tests whether or not comment has API section.
        """
        return raw_comment and self.api_start_kw in raw_comment
