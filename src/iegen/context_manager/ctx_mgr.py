from collections import OrderedDict
from jinja2.exceptions import UndefinedError as JinjaUndefinedError
from types import SimpleNamespace

from iegen.common import JINJA_ENV
from iegen.common.error import Error
from iegen import default_config
from iegen.parser.ieg_api_parser import APIParser
from iegen.ir.ast import (
    Node,
    ROOT_KIND_NAME,
    DIR_KIND_NAME,
    FILE_KIND_NAME
)

ALL_LANGUAGES = sorted(list(default_config.languages))
ALL_PLATFORMS = sorted(list(default_config.platforms))

NODE_GROUP_ALIASES = {
    'file_system': ('dir', 'file'),
    'cxx': (
        'class', 'class_template', 'struct', 'struct_template', 'constructor',
        'function', 'function_template', 'cxx_method', 'enum', 'field'
    )
}


class ContextManager:
    def __init__(self, attributes, platform, language):
        self.platform = platform
        self.language = language
        self.attributes = ContextManager.resolve_attr_aliases(attributes)
        self.ieg_api_parser = APIParser(default_config.attributes,
                                        ALL_LANGUAGES,
                                        ALL_PLATFORMS,
                                        default_config.languages[self.language])

    def eval_root_attrs(self, name, ctx, location=None):
        args = None
        api = Node.API_NONE
        parsed_api = self.ieg_api_parser.parse_yaml_api(name, ctx)
        if parsed_api:
            api, args = parsed_api
        return api, self.__process_attrs(ROOT_KIND_NAME, args, location, ctx)

    def eval_dir_attrs(self, name, ctx, location=None):
        api = args = None
        parsed_api = self.ieg_api_parser.parse_yaml_api(name, ctx)
        if parsed_api:
            api, args = parsed_api
        return api, self.__process_attrs(DIR_KIND_NAME, args, location, ctx)

    def eval_file_attrs(self, name, ctx, location=None):
        parsed_api = self.ieg_api_parser.parse_yaml_api(name, ctx)
        if parsed_api:
            api, args = parsed_api
            return api, self.__process_attrs(FILE_KIND_NAME, args, location, ctx)

    def eval_clang_attrs(self, name, kind, api_section, ctx, location):
        parsed_api = self.ieg_api_parser.parse_api(name, api_section, location, ctx)
        if parsed_api:
            api, args = parsed_api
            return api, self.__process_attrs(kind, args, location, ctx)

    def __process_attrs(self, kind, args, location, ctx=None):
        ctx = ctx or OrderedDict()
        args = args or OrderedDict()
        res = OrderedDict()

        # add all missing attributes
        for att_name, properties in self.attributes.items():
            att_val = args.get(att_name, {}).get(self.platform, {}).get(self.language)

            new_att_val = att_val
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
                        new_att_val = ContextManager.get_attr_default_value(properties, self.platform, self.language)
                        if isinstance(new_att_val, str):
                            try:
                                new_att_val = JINJA_ENV.from_string(new_att_val).render(ctx)
                            except JinjaUndefinedError as e:
                                Error.critical(
                                    f"Jinja evaluation error in attributes definition file {default_config.attr_file}: {e}")
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
                    # sys vars can have different types than string parse to get correct type
                    new_att_val = self.ieg_api_parser.parse_attr(att_name, new_att_val)
                # add attr to current node context so that it can be used for coming attributes
                ctx[att_name] = new_att_val
                res[att_name] = new_att_val

        assert res is not None
        return res

    @staticmethod
    def get_attr_default_value(prop, plat, lang):
        def_val = prop.get("default")

        if not isinstance(def_val, dict):
            return def_val

        if plat in def_val and lang in def_val:
            Error.critical(
                f"Conflict of attributes in {default_config.attr_file} attributes definiton file: {plat} and {lang}: "
                f"only one of them must be defined separately, or they must be both specified")

        for key in (plat + '.' + lang, plat, lang, 'else'):
            if key in def_val:
                return def_val[key]

    @staticmethod
    def resolve_attr_aliases(attrs):
        """
        A function to replace node group aliases with their actual values list
        """

        for field in ['allowed_on', 'required_on']:
            for key, val in attrs.items():
                if field not in val:
                    attrs[key][field] = NODE_GROUP_ALIASES['cxx'] if field == 'allowed_on' else []
                else:
                    res = []
                    for node in val[field]:
                        if node in NODE_GROUP_ALIASES:
                            res.extend(NODE_GROUP_ALIASES[node])
                        else:
                            res.append(node)
                    attrs[key][field] = res

        return attrs

    def has_yaml_api(self, name):
        return name in self.ieg_api_parser.api_type_attributes

    def get_yaml_api_file(self, name):
        return self.ieg_api_parser.api_type_attributes[name].file
