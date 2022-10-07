# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Implements cppbind api parser on cxx comment
"""

import re
from collections import OrderedDict
from collections import defaultdict
from types import SimpleNamespace

import yaml
from jinja2.exceptions import TemplateSyntaxError

from cppbind import default_config
from cppbind.common.error import Error
from cppbind.common.yaml_process import has_type, to_value, UniqueKeyLoader
from cppbind.context_manager.var_eval import VariableEvaluator
from cppbind.ir.ast import Node
from cppbind.utils.clang import extract_pure_comment

TEMPLATE_NON_TYPE_PARAMETER_KEY = 'value'
TEMPLATE_TYPE_PARAMETER_KEY = 'type'
TEMPLATE_NAME_KEY = 'name'
TEMPLATE_INSTANCE_KEY = 'template_instance'
TEMPLATE_INSTANCE_ARGS_KEY = 'args'
TEMPLATE_KEY = 'template'


class APIParser:
    """
    A class which is responsible for parsing/validating API annotation section.
    """

    API_START_KW = default_config.api_start_kw
    ALL_PLATFORMS = sorted(default_config.platforms)

    def __init__(self, ctx_desc, jinja_env, platform, language):
        self.ctx_desc = ctx_desc
        self.var_def = self.ctx_desc.get_var_def()
        self.platform = platform
        self.language = language
        self.var_evaluator = VariableEvaluator(jinja_env)

    @staticmethod
    def separate_pure_and_api_comment(raw_comment, index=None):
        """
        A method to separate user defined 'api' related and not related parts
        from the whole pure doxygen comment.
        """
        index = index or raw_comment.find(APIParser.API_START_KW)
        if index == -1:
            return extract_pure_comment(raw_comment), None
        return (extract_pure_comment(raw_comment, index),
                raw_comment[index + len(APIParser.API_START_KW)::])

    def parse_comments(self, api_section, location=None):
        """
        Parse comment to extract API actions and their variables
        """
        if api_section is None:
            return None, OrderedDict()

        # skip comment end
        skip_pattern = r'^\s*(/\*|\*+/|\/+|//!)\s*$'

        # keep empty lines or empty comments
        comment_pattern = r'^\s*(\*|/{3,}|\//!)\s*'

        lines = api_section.splitlines()
        yaml_lines = []

        for line in lines:
            # continue if line contains is only multiline comment begin/end sign
            if re.match(skip_pattern, line):
                continue

            # search for comment prefix
            comment_prefix = re.search(comment_pattern, line)
            if comment_prefix:
                pattern_len = comment_prefix.end()
                yaml_lines.append(' ' * pattern_len + line[pattern_len:])
            else:
                # if no any comment sign found just save the line
                yaml_lines.append(line)

        try:
            attrs = yaml.load('\n'.join(yaml_lines), Loader=UniqueKeyLoader) or {}
            return self.parse_api_attrs(attrs, location)
        except yaml.YAMLError as err:
            Error.critical(f"Error while scanning yaml style comments: {err}",
                           location.file_name if location else None,
                           location.line_number if location else None)

        return None

    def parse_api(self, name, api_section, location, ctx=None):
        """
        Parse api annotations: either comments in source file
        or in separate yaml config files.
        """
        if api_section:
            return self.parse_comments(api_section, location)
        return self.parse_yaml_api(name, ctx, location)

    def parse_yaml_api(self, name, ctx=None, location=None):
        """
        A method to parse api comments from separate yaml file.
        """
        ctx = ctx or {}
        attrs = self.ctx_desc.get_yaml_api(name)
        if attrs:
            # for dir api pass yaml file path
            location = location or SimpleNamespace(file_name=attrs.file, line_number=None)
            try:
                api_attrs = self.var_evaluator.eval_attr_template(attrs, ctx)
                return self.parse_api_attrs(api_attrs, location)
            except TemplateSyntaxError as e:
                Error.critical(
                    f"Jinja syntax error - {str(e)}",
                    file=attrs.file,
                    line=attrs.line_number)
            except Exception as e:
                Error.critical(f"Jinja render error while evaluating yaml api - {e}", attrs.file, attrs.line_number)

        return None

    def parse_api_attrs(self, attrs, location):
        """
        Parsing api comment rows and extracting an action and its corresponding variables.
        """

        curr_lang = self.language
        curr_plat = self.platform

        attr_dict = OrderedDict()
        attr_key_regex = rf"[\s*/]*(?:({'|'.join(APIParser.ALL_PLATFORMS)})\.)?(?:({'|'.join(self.ctx_desc.get_all_languages())})\.)?([^\d\W]\w*)\s*$"

        # Data structure to keep previous priorities
        prev_priors = defaultdict(lambda: [0])
        api = Node.API_NONE
        for attr_key, value in attrs.items():
            match = re.match(attr_key_regex, attr_key)
            if not match:
                Error.critical(f"Wrong variable specification: '{attr_key}'",
                               location.file_name if location else None,
                               location.line_number if location else None)
            platform, language, attr = match.groups()

            if (language and language != curr_lang) or (platform and platform != curr_plat):
                continue

            prior = APIParser.get_priority(platform, language)

            if attr == 'action':
                api = to_value(value)

            if attr not in self.var_def:
                Error.critical(f"Variable {attr} is not specified. "
                               f"It should be one of {set(self.var_def)}.",
                               location.file_name if location else None,
                               location.line_number if location else None)

            curr_max_prior = max(prev_priors[attr])
            # overwrite the value only if the current option
            # has higher priority than all previous ones.
            if prior > curr_max_prior:
                attr_dict[attr] = value
            # If we have this case it means we have a conflict of options: plat.lang and lang.plat
            if prior in prev_priors[attr]:
                Error.error(f"Conflicting variables definition: variables like platform.attr and "
                            f"language.attr cannot be defined together: "
                            f"{curr_lang + '.' + attr, curr_plat + '.' + attr}",
                            location.file_name, location.line_number)
            prev_priors[attr].append(prior)

        return api, attr_dict

    def validate_attr(self, attr_name, attr_value, location=None):
        """Validate attributes"""

        attr_type = self.var_def[attr_name].get('type')
        # TODO: remove these validations when there'll be a mechanism to validate complex variables like list, dict
        if attr_type == 'list':
            if not has_type(attr_value, list):
                Error.critical(f"Wrong variable type: {type(attr_value)}, it must be a list",
                               location.file_name if location else None,
                               location.line_number if location else None)
            if attr_name == TEMPLATE_INSTANCE_KEY:
                for template_instance in attr_value:
                    if not isinstance(template_instance, dict):
                        Error.critical(
                            f"Wrong {TEMPLATE_INSTANCE_KEY} variable style: {attr_value}, "
                            f"items of {TEMPLATE_INSTANCE_KEY} must be of dictionary type.",
                            location.file_name if location else None,
                            location.line_number if location else None
                        )
                    if TEMPLATE_INSTANCE_ARGS_KEY not in template_instance:
                        Error.critical(
                            f"Wrong {TEMPLATE_INSTANCE_KEY} variable style: {attr_value}, "
                            f"{TEMPLATE_INSTANCE_KEY} must have mandatory '{TEMPLATE_INSTANCE_ARGS_KEY}' variable.",
                            location.file_name if location else None,
                            location.line_number if location else None
                        )
        if attr_type == 'dict':
            if not has_type(attr_value, dict):
                Error.critical(f"Wrong variable type: {type(attr_value)}, it must be a dictionary",
                               location.file_name if location else None,
                               location.line_number if location else None)
            if attr_name == TEMPLATE_KEY:
                for attrs in attr_value.values():
                    for attr in attrs:
                        if not isinstance(attr, dict) or TEMPLATE_TYPE_PARAMETER_KEY not in attr \
                                and TEMPLATE_NON_TYPE_PARAMETER_KEY not in attr:
                            Error.critical(
                                f"Wrong template variable style: {attr_value}, "
                                f"template must have mandatory '{TEMPLATE_NON_TYPE_PARAMETER_KEY}'"
                                f" or '{TEMPLATE_TYPE_PARAMETER_KEY}' variable",
                                location.file_name if location else None,
                                location.line_number if location else None
                            )
        # default string type
        return attr_value

    @staticmethod
    def has_api(raw_comment):
        """
        Tests whether the comment has an API section.
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
