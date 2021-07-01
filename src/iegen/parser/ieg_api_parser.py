"""
Implements ieg api parser on cxx comment
"""
import distutils.util
import re
import yaml

from collections import defaultdict
from collections import OrderedDict
from jinja2.exceptions import UndefinedError as JinjaUndefinedError
from types import SimpleNamespace

from iegen import default_config
from iegen.common import JINJA_ENV
from iegen.common.error import Error
from iegen.common.yaml_process import UniqueKeyLoader, yaml_info_struct_to_dict
from iegen.ir.ast import Node
from iegen.utils.clang import extract_pure_comment


class APIParser(object):
    """
    A class which is responsible for parsing/validating API annotation section.
    """

    API_START_KW = default_config.api_start_kw

    ALL_LANGUAGES = ('java', 'kotlin', 'python', 'swift')
    ALL_PLATFORMS = ('android', 'ios', 'linux', 'mac', 'win')

    def __init__(self, ctx_desc, languages=None, platforms=None):
        self.ctx_desc = ctx_desc
        self.var_def = self.ctx_desc.var_def
        self.languages = languages or APIParser.ALL_LANGUAGES
        self.platforms = platforms or APIParser.ALL_PLATFORMS

    @staticmethod
    def separate_pure_and_api_comment(raw_comment, index=None):
        """
        A method to separate user defined 'api' related and not related parts from the whole pure doxygen comment.
        """
        index = index or raw_comment.find(APIParser.API_START_KW)
        if index == -1:
            return raw_comment, None
        return extract_pure_comment(raw_comment, index), raw_comment[index + len(APIParser.API_START_KW)::]

    def parse_comments(self, api_section, ctx, location=None):
        """
        Parse comment to extract API actions and their variables
        """
        if api_section is None:
            return None, OrderedDict()
        api_section = JINJA_ENV.from_string(api_section).render(ctx)
        skip_regex = r'^[\s*/]*$'

        lines = api_section.splitlines()
        filtered = list(filter(lambda x: not re.match(skip_regex, x), lines))

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
            return self.parse_api_attrs(attrs, location)
        except yaml.YAMLError as e:
            Error.critical("Error while scanning yaml style comments: {e}",
                           location.file_name if location else None,
                           location.line_number if location else None)

    def parse_api(self, name, api_section, location, ctx=None):
        if api_section:
            return self.parse_comments(api_section, ctx, location)
        else:
            return self.parse_yaml_api(name, ctx, location)

    def parse_yaml_api(self, name, ctx=None, location=None):
        """
        A method to parse api comments from separate yaml file.
        """
        ctx = ctx or {}
        attrs = self.ctx_desc.ctx_def_map.get(name)
        if attrs:
            # for dir api pass yaml file path
            location = location or SimpleNamespace(file_name=attrs.file,
                                                   line_number=None)
            try:
                api_attrs = APIParser.eval_attr_template(attrs, ctx)
            except JinjaUndefinedError as e:
                Error.critical(f"Jinja evaluation error: {e}", location.file_name, location.line_number)
            return self.parse_api_attrs(api_attrs, location)

    def parse_api_attrs(self, attrs, location):
        """
        Parsing api comment rows and extracting an action and its corresponding variables.
        """

        curr_lang = self.ctx_desc.language
        curr_plat = self.ctx_desc.platform

        attr_dict = OrderedDict()
        attr_key_regex = rf"[\s*/]*(?:({'|'.join(self.platforms)})\.)?(?:({'|'.join(self.languages)})\.)?([^\d\W]\w*)\s*$"

        # Data structure to keep previous priorities
        prev_priors = defaultdict(lambda: [0])
        api = Node.API_NONE
        for attr_key, value in attrs.items():
            m = re.match(attr_key_regex, attr_key)
            if not m:
                Error.critical({attr_key: value},
                               location.file_name if location else None,
                               location.line_number if location else None)
            platform, language, attr = m.groups()

            if (language and language != curr_lang) or (platform and platform != curr_plat):
                continue

            prior = APIParser.get_priority(platform, language)

            if attr == 'action':
                api = value

            if attr not in self.var_def:
                Error.critical(f"Variable {attr} is not specified. It should be one of {set(self.var_def)}.",
                               location.file_name if location else None,
                               location.line_number if location else None)

            array = self.var_def[attr].get('array', False)
            value = self.parse_attr(attr, value)

            if array:
                if not isinstance(value, list):
                    value = [value]
            elif isinstance(value, list):
                Error.critical(f"Wrong variable type: {attr} cannot be array",
                               location.file_name if location else None,
                               location.line_number if location else None)

            curr_max_prior = max(prev_priors[attr])
            # overwrite the value only if the current option has higher priority than all previous ones.
            if prior > curr_max_prior:
                attr_dict[attr] = value
            # If we have this case it means we have a conflict of options: plat.lang and lang.plat
            if prior in prev_priors[attr]:
                Error.error(f"Conflicting variables definition: variables like platform.attr and "
                            f"language.attr cannot be defined together: {curr_lang + '.' + attr, curr_plat + '.' + attr}",
                            location.file_name, location.line_number)
            prev_priors[attr].append(prior)

        return api, attr_dict

    def parse_attr(self, attr_name, attr_value):
        """
        Evaluate the value of variable depending on its type.
        """
        attr_type = self.var_def[attr_name].get('type', None)

        if isinstance(self.var_def[attr_name].get('default'), bool) or attr_type == 'bool':
            return bool(distutils.util.strtobool(str(attr_value)))

        if attr_type == 'dict':
            if not isinstance(attr_value, dict):
                raise Exception(f"Wrong variable type: {type(attr_value)}, it must be dictionary")
            if attr_name == 'template':
                for attrs in attr_value.values():
                    for attr in attrs:
                        if not isinstance(attr, dict) or not 'type' in attr:
                            raise Exception(
                                f"Wrong template variable style: {attr_value}, template must have mandatory 'type' variable")
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
        A method to get priority of platform/language specific variable:
        Priorities sorted descending: platform.language.attr, [language|platform].attr, attr
        """
        if plat is None and lang is None:
            return 1
        if plat is None or lang is None:
            return 2
        return 3

    @staticmethod
    def eval_attr_template(attrs, ctx):
        """
        Evaluate jinja expressions in current yaml section.
        """

        # if the whole section is pure string, we just need to eval it
        if attrs.isinstance(str):
            return yaml.load(JINJA_ENV.from_string(attrs.value).render(ctx), Loader=UniqueKeyLoader)
        # if the section is not a string, i.e. values can contain jinja expressions, we need to dump it to the string, then evaluate it.
        return yaml.load(JINJA_ENV.from_string(yaml.dump(yaml_info_struct_to_dict(attrs))).render(ctx), Loader=UniqueKeyLoader)
