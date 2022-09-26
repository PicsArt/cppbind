# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Module is responsible for context variables evaluating for current node.
"""
from collections import OrderedDict

from cppbind import default_config
from cppbind.common.error import Error
from cppbind.common.yaml_process import to_value
from cppbind.context_manager.var_eval import VariableEvaluator
from cppbind.ir.ast import (
    Node,
    RootNode,
    ROOT_KIND_NAME,
    DIR_KIND_NAME,
    FILE_KIND_NAME
)
from cppbind.parser.cppbind_api_parser import APIParser
from cppbind.utils import init_jinja_env

ALL_PLATFORMS = sorted(list(default_config.platforms))


class ContextManager:
    """
    A class for evaluating current context variables
    using current context to assign the result to the current node.
    """

    def __init__(self, ctx_desc, platform, language):
        self.ctx_desc = ctx_desc
        self.platform = platform
        self.language = language
        jinja_env = init_jinja_env(language)
        self.cppbind_api_parser = APIParser(ctx_desc, jinja_env, platform, language)
        self.var_evaluator = VariableEvaluator(jinja_env)

    def eval_root_attrs(self, ctx, var_values, location=None):
        """Eval context variables for root node"""
        args = None
        api = Node.API_NONE

        # update context with var values to use them during evaluation
        ctx.update(var_values)

        parsed_api = self.cppbind_api_parser.parse_yaml_api(RootNode.ROOT_KEY, ctx)
        if parsed_api:
            api, args = parsed_api

        args = args or {}
        # overwrite parsed variables with command line values (it has higher priority)
        args.update(var_values)

        return api, self.__process_attrs(ROOT_KIND_NAME, args, location, ctx)

    def eval_dir_attrs(self, name, ctx, location=None):
        """Eval context variables for dir node"""
        api = args = None
        parsed_api = self.cppbind_api_parser.parse_yaml_api(name, ctx)
        if parsed_api:
            api, args = parsed_api
        return api, self.__process_attrs(DIR_KIND_NAME, args, location, ctx)

    def eval_file_attrs(self, name, ctx, location=None):
        """Eval context variables for file node"""
        parsed_api = self.cppbind_api_parser.parse_yaml_api(name, ctx)
        if parsed_api:
            api, args = parsed_api
            if api:
                return api, self.__process_attrs(FILE_KIND_NAME, args, location, ctx)
        return None

    def eval_clang_attrs(self, name, kind, api_section, ctx, location):
        """Eval context variables for clang node"""
        parsed_api = self.cppbind_api_parser.parse_api(name, api_section, location, ctx)
        if parsed_api:
            api, args = parsed_api
            if api:
                return api, self.__process_attrs(kind, args, location, ctx)
        return None

    def __process_attrs(self, kind, args, location, ctx=None):
        """
        Evaluate/calculate current context variables values by its' kind and current context.
        """
        ctx = ctx or OrderedDict()
        args = args or OrderedDict()
        res = OrderedDict()

        # dummy object for identifying undefined and null value defined variables 
        undefined = object()

        # add all missing attributes
        for att_name, properties in self.ctx_desc.get_var_def().items():
            new_att_val = args.get(att_name, undefined)

            allowed = kind in properties["allowed_on"]
            if new_att_val is undefined:
                # check mandatory attribute existence
                if kind in properties["required_on"]:
                    Error.error(f"Attribute '{att_name}' is mandatory attribute on {kind}.",
                                location.file_name if location else None,
                                location.line_number if location else None)
                    break

                # inherit from parent or add default value
                if properties.get('inheritable'):
                    # directory based nodes may not have parent
                    if ctx:
                        new_att_val = ctx.get(att_name, undefined)

                if allowed:
                    if new_att_val is undefined:
                        # use default value
                        new_att_val = ContextManager.get_attr_default_value(
                            properties, self.platform, self.language, undefined)

                        if new_att_val is not undefined:
                            new_att_val = self.var_evaluator.eval_var_value(properties,
                                                                            new_att_val,
                                                                            ctx,
                                                                            att_name,
                                                                            location)
            else:
                # attribute is set check weather or not it is allowed.
                if not allowed:
                    Error.error(f"Attribute {att_name} is not allowed on {kind}.",
                                location.file_name if location else None,
                                location.line_number if location else None)
                    break

                new_att_val = self.var_evaluator.eval_var_value(properties,
                                                                new_att_val,
                                                                ctx,
                                                                att_name,
                                                                location)

            # validate variable values
            if new_att_val not in (None, undefined):
                self.cppbind_api_parser.validate_attr(att_name, new_att_val)

            options = to_value(ContextManager.get_var_property_value(properties, self.platform, self.language, 'options'))

            if new_att_val not in (None, undefined) and options is not None:
                if new_att_val not in options:
                    Error.error(f"Value mismatch for '{att_name}' variable: "
                                f"value {new_att_val} is not in list of allowed options",
                                location.file_name if location else None,
                                location.line_number if location else None)

            if new_att_val is not undefined:
                # add attr to current node context so that it can be used for coming attributes
                ctx[att_name] = new_att_val
                res[att_name] = new_att_val

        return res

    @staticmethod
    def get_attr_default_value(props, plat, lang, default=None):
        return ContextManager.get_var_property_value(props, plat, lang, 'default', default)

    @staticmethod
    def get_var_property_value(props, plat, lang, prop, default=None):
        """
        Retrieve language/platform specific default value for current variable.
        """

        # detect illegal specification of plat/lang option
        if plat + f'.{prop}' in props and lang + f'.{prop}' in props:
            Error.critical(
                f"Conflict of attributes in attributes definition file: {plat}.default and {lang}.default: "
                f"only one of them must be defined separately, or they must be both specified")

        # if plat/lang specific key is preset, return corresponding section
        # we search for specific key by descending order of priority
        for key in (plat + '.' + lang + f'.{prop}', plat + f'.{prop}', lang + f'.{prop}', prop):
            if key in props:
                return props[key]

        return default

    def filter_by_plat_lang(self, var_values):
        """
        Filter current platform/language specific values from initial context provided via command line arguments
        """
        res = {}

        if var_values is None:
            return res

        # convert argparse.Namespace into dict be able to lookup and iterate over it
        var_values = var_values.__dict__

        # pick those variable names which are present in variable definitions
        var_def = self.ctx_desc.get_var_def()
        var_names = set(name.split('.')[-1] for name in var_values if name in var_def)

        for name in var_names:
            prop = var_def[name]
            if 'cmd_line' not in prop['allowed_on']:
                continue

            plat_lang_opt = f"{self.platform}.{self.language}.{name}"
            plat_opt = f"{self.platform}.{name}"
            lang_opt = f"{self.language}.{name}"

            # search for value from highest to lowest priority (plat+lang+name, plat+name, lang+name, name)
            for opt in (plat_lang_opt, plat_opt, lang_opt, name):
                if opt in var_values and var_values[opt] is not None:
                    res[name] = var_values[opt]
                    # no need for later searching since we already found an option with the highest possible priority
                    break

        return res
