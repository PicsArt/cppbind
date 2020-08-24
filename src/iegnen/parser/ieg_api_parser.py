"""
Implements ieg api parser on cxx comment
"""
import re
from collections import OrderedDict


class APIParser(object):

    def __init__(self, attributes, api_start_kw):
        self.attributes = attributes
        self.api_start_kw = api_start_kw

    def parse(self, raw_comment):
        """
        Pares comment to extract API command and its attributes
        """
        api = None
        attr_dict = OrderedDict()

        index = raw_comment.find(self.api_start_kw)
        if index == -1:
            return api, attr_dict
        # else
        ALL_PLATFORMS = ['linux', 'windows', 'ios']
        ALL_LANGUAGES = ['swift', 'java', 'python']
        ATTR_REGEXPR =\
            rf"[\s*/]*(?:({'|'.join(ALL_LANGUAGES)})_)?(?:({'|'.join(ALL_PLATFORMS)})_)?([^\d\W]\w*)\s*:\s*(.+)$"
        SKIP_REGEXPR = r'^[\s*/]*$'

        api_section = raw_comment[index + len(self.api_start_kw)::]
        lines = api_section.splitlines()
        filtered = filter(lambda x: not re.match(SKIP_REGEXPR, x), lines)
        for line in filtered:

            m = re.match(ATTR_REGEXPR, line)
            if not m:
                # error
                raise Exception(line)
            language, platform, attr, value = m.groups()
            value = value.strip()

            if language:
                language = [language]
            else:
                language = ALL_LANGUAGES + ['__all__']

            if platform:
                platform = [platform]
            else:
                platform = ALL_PLATFORMS + ['__all__']

            if attr == 'gen':
                api = value
            else:
                for p in platform:
                    for lang in language:
                        attr_dict.setdefault((p, lang),
                                             OrderedDict())[attr] = value

        return api, attr_dict

    def has_api(self, raw_comment):
        """
        Tests whether or not comment has API section.
        """
        return raw_comment and self.api_start_kw in raw_comment
