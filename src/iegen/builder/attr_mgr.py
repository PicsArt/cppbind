from collections import OrderedDict
from jinja2.exceptions import UndefinedError as JinjaUndefinedError

from iegen.common import JINJA_ENV
from iegen.common.error import Error
from iegen import default_config

ALL_LANGUAGES = sorted(list(default_config.languages))
ALL_PLATFORMS = sorted(list(default_config.platforms))

NODE_GROUP_ALIASES = {
    'file_system': ('dir', 'file'),
    'cxx': (
        'class', 'class_template', 'struct', 'struct_template', 'constructor',
        'function', 'function_template', 'cxx_method', 'enum', 'field'
    )
}


class AttributeManager:
    def __init__(self, builder, attributes):
        self.builder = builder
        self.attributes = AttributeManager.resolve_attr_aliases(attributes)

    def eval_root_attrs(self, node, ctx):
        args = pure_comment = None
        api = node.api
        parsed_api = self.builder.ieg_api_parser.parse_yaml_api(node.name, ctx)
        if parsed_api:
            api, args, pure_comment = parsed_api
        self.process_attrs(node, args, api, pure_comment, ctx)

    def eval_dir_attrs(self, node, ctx):
        parsed_api = self.builder.ieg_api_parser.parse_yaml_api(node.name, ctx)
        if parsed_api:
            api, args, pure_comment = parsed_api
            self.process_attrs(node, args, api, pure_comment, ctx)

    def eval_file_attrs(self, node, ctx, name):
        parsed_api = self.builder.ieg_api_parser.parse_yaml_api(name, ctx)
        if parsed_api:
            api, args, pure_comment = parsed_api
            self.process_attrs(node, args, api, pure_comment, ctx)

    def eval_clang_attrs(self, node, cursor, ctx):
        parsed_api = self.builder.ieg_api_parser.parse_api(cursor, ctx)
        if parsed_api:
            api, args, pure_comment = parsed_api
            self.process_attrs(node, args, api, pure_comment, ctx)

    def process_attrs(self, current_node, args, api, pure_comment, ctx=None):
        args = args or OrderedDict()
        context = ctx or self.builder.get_ctx(pure_comment)
        parent_args = self.builder.get_parent_args()

        # add all missing attributes
        for plat in ALL_PLATFORMS + ["__all__"]:
            for lang in ALL_LANGUAGES + ["__all__"]:
                context.update(self.builder.get_ctx_by_plat_lang(plat, lang, parent_args))
                for att_name, properties in self.attributes.items():
                    att_val = args.get(
                        att_name,
                        {}
                    ).get(plat, {}).get(lang)

                    new_att_val = att_val
                    node_kind = current_node.kind_name
                    allowed = node_kind in properties["allowed_on"]
                    if new_att_val is None:
                        # check mandatory attribute existence
                        if node_kind in properties["required_on"]:
                            Error.error(f"Attribute '{att_name}' is mandatory attribute on {node_kind}.",
                                        current_node.file_name,
                                        current_node.line_number)
                            break

                        # inherit from parent or add default value
                        if properties["inheritable"]:
                            # directory based nodes may not have parent
                            _parent_args = self.builder.get_parent_args()
                            if _parent_args:
                                new_att_val = _parent_args.get(att_name, {}).get(plat, {}).get(lang)

                        if allowed:
                            if new_att_val is None:
                                # use default value
                                new_att_val = AttributeManager.get_attr_default_value(properties, plat, lang)
                                if isinstance(new_att_val, str):
                                    try:
                                        new_att_val = JINJA_ENV.from_string(new_att_val).render(context)
                                    except JinjaUndefinedError as e:
                                        Error.critical(
                                            f"Jinja evaluation error in attributes definition file {default_config.attr_file}: {e}")
                    else:
                        # attribute is set check weather or not it is allowed.
                        if not allowed:
                            Error.error(f"Attribute {att_name} is not allowed on {node_kind}.",
                                        current_node.file_name,
                                        current_node.line_number)
                            break

                    # now we need to process variables of value and set value
                    if new_att_val is not None:
                        if isinstance(new_att_val, str):
                            # sys vars can have different types than string parse to get correct type
                            new_att_val = self.builder.ieg_api_parser.parse_attr(att_name, new_att_val)
                        # add attr to current node context so that it can be used for coming attributes
                        context[att_name] = new_att_val
                        args.setdefault(att_name, OrderedDict()).setdefault(plat, OrderedDict())[lang] = new_att_val

        assert args is not None
        current_node.api = api
        current_node.pure_comment = pure_comment
        current_node.args = args

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
