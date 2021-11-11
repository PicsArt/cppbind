"""
Module is responsible for context variables evaluating for current node.
"""
from collections import OrderedDict

from iegen import default_config
from iegen.common.error import Error
from iegen.context_manager.var_eval import VariableEvaluator
from iegen.ir.ast import (
    Node,
    RootNode,
    ROOT_KIND_NAME,
    DIR_KIND_NAME,
    FILE_KIND_NAME
)
from iegen.parser.ieg_api_parser import APIParser

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
        self.ieg_api_parser = APIParser(ctx_desc, platform, language)

    def eval_root_attrs(self, ctx, var_values, location=None):
        """Eval context variables for root node"""
        args = None
        api = Node.API_NONE

        # update context with var values to use them during evaluation
        ctx.update(var_values)

        parsed_api = self.ieg_api_parser.parse_yaml_api(RootNode.ROOT_KEY, ctx)
        if parsed_api:
            api, args = parsed_api

        args = args or {}
        # overwrite parsed variables with command line values (it has higher priority)
        args.update(var_values)

        return api, self.__process_attrs(ROOT_KIND_NAME, args, location, ctx)

    def eval_dir_attrs(self, name, ctx, location=None):
        """Eval context variables for dir node"""
        api = args = None
        parsed_api = self.ieg_api_parser.parse_yaml_api(name, ctx)
        if parsed_api:
            api, args = parsed_api
        return api, self.__process_attrs(DIR_KIND_NAME, args, location, ctx)

    def eval_file_attrs(self, name, ctx, location=None):
        """Eval context variables for file node"""
        parsed_api = self.ieg_api_parser.parse_yaml_api(name, ctx)
        if parsed_api:
            api, args = parsed_api
            return api, self.__process_attrs(FILE_KIND_NAME, args, location, ctx)
        return None

    def eval_clang_attrs(self, name, kind, api_section, ctx, location):
        """Eval context variables for clang node"""
        parsed_api = self.ieg_api_parser.parse_api(name, api_section, location, ctx)
        if parsed_api:
            api, args = parsed_api
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
                            new_att_val = VariableEvaluator.eval_var_value(properties,
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

                new_att_val = VariableEvaluator.eval_var_value(properties,
                                                               new_att_val,
                                                               ctx,
                                                               att_name,
                                                               location)

            # now we need to process variables of value and set value
            if new_att_val not in (None, undefined):
                if isinstance(new_att_val, str):
                    # vars can have different types than string,
                    # so we need to parse it to get correct type
                    new_att_val = self.ieg_api_parser.parse_attr(att_name, new_att_val)

            if new_att_val is not undefined:
                # add attr to current node context so that it can be used for coming attributes
                ctx[att_name] = new_att_val
                res[att_name] = new_att_val

        return res

    @staticmethod
    def get_attr_default_value(prop, plat, lang, default=None):
        """
        Retrieve language/platform specific default value for current variable.
        """

        # detect illegal specification of plat/lang option
        if plat + '.default' in prop and lang + '.default' in prop:
            Error.critical(
                f"Conflict of attributes in attributes definition file: {plat}.default and {lang}.default: "
                f"only one of them must be defined separately, or they must be both specified")

        # if plat/lang specific key is preset, return corresponding section
        # we search for specific key by descending order of priority
        for key in (plat + '.' + lang + '.default', plat + '.default', lang + '.default', 'default'):
            if key in prop:
                return prop[key].value

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
