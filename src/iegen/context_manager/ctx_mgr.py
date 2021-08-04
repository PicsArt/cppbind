"""
Module is responsible for context variables evaluating for current node.
"""

from collections import OrderedDict
from collections.abc import MutableMapping
from jinja2.exceptions import UndefinedError as JinjaUndefinedError

from iegen.common.error import Error
from iegen import default_config
from iegen.parser.ieg_api_parser import APIParser
from iegen.ir.ast import (
    Node,
    ROOT_KIND_NAME,
    DIR_KIND_NAME,
    FILE_KIND_NAME
)
from iegen.utils import JINJA2_ENV

ALL_LANGUAGES = sorted(list(default_config.languages))
ALL_PLATFORMS = sorted(list(default_config.platforms))


class ContextManager:
    """
    A class for evaluating current context variables
    using current context to assign the result to the current node.
    """
    def __init__(self, ctx_desc):
        self.ctx_desc = ctx_desc
        self.ieg_api_parser = APIParser(ctx_desc,
                                        ALL_LANGUAGES,
                                        ALL_PLATFORMS)

    def eval_root_attrs(self, name, ctx, location=None):
        """Eval context variables for root node"""
        args = None
        api = Node.API_NONE
        parsed_api = self.ieg_api_parser.parse_yaml_api(name, ctx)
        if parsed_api:
            api, args = parsed_api
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

        # add all missing attributes
        for att_name, properties in self.ctx_desc.var_def.items():
            new_att_val = args.get(att_name)

            allowed = kind in properties["allowed_on"]
            if new_att_val is None:
                # check mandatory attribute existence
                if kind in properties["required_on"]:
                    Error.error(f"Attribute '{att_name}' is mandatory attribute on {kind}.",
                                location.file_name if location else None,
                                location.line_number if location else None)
                    break

                # inherit from parent or add default value
                if properties["inheritable"]:
                    # directory based nodes may not have parent
                    if ctx:
                        new_att_val = ctx.get(att_name)

                if allowed:
                    if new_att_val is None:
                        # use default value
                        new_att_val = ContextManager.get_attr_default_value(
                            properties, self.ctx_desc.platform, self.ctx_desc.language)
                        if isinstance(new_att_val, str):
                            try:
                                new_att_val = JINJA2_ENV.from_string(new_att_val).render(ctx)
                            except JinjaUndefinedError as err:
                                Error.critical(
                                    f"Jinja evaluation error in attributes definition file: {err}")
            else:
                # attribute is set check weather or not it is allowed.
                if not allowed:
                    Error.error(f"Attribute {att_name} is not allowed on {kind}.",
                                location.file_name if location else None,
                                location.line_number if location else None)
                    break

            # now we need to process variables of value and set value
            if new_att_val is not None:
                if isinstance(new_att_val, str):
                    # vars can have different types than string,
                    # so we need to parse it to get correct type
                    new_att_val = self.ieg_api_parser.parse_attr(att_name, new_att_val)
                # add attr to current node context so that it can be used for coming attributes
                ctx[att_name] = new_att_val
                res[att_name] = new_att_val

        return res

    @staticmethod
    def get_attr_default_value(prop, plat, lang):
        """
        Retrieve language/platform specific default value for current variable.
        """
        def_val = prop.get("default")

        if not def_val.is_of_type(MutableMapping):
            return def_val.value

        if plat in def_val and lang in def_val:
            Error.critical(
                f"Conflict of attributes in attributes definition file: {plat} and {lang}: "
                f"only one of them must be defined separately, or they must be both specified")

        for key in (plat + '.' + lang, plat, lang, 'else'):
            if key in def_val:
                return def_val[key].value

        return None

    def has_yaml_api(self, name):
        """
        Check whether current name is present in context definition map
        """
        return name in self.ctx_desc.ctx_def_map

    def get_api_def_filename(self, name):
        """
        Method to get yaml config file name in which file/dir api is defined
        """
        return self.ctx_desc.ctx_def_map[name].file
