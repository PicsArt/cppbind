"""
Processor module provides various processor for ieg parser
"""
import copy
import os
from collections import OrderedDict
from jinja2 import Template
from types import SimpleNamespace

from iegen import default_config as default_config
from iegen.common.error import Error
from iegen.ir.ast import DirectoryNode, ClangNode, NodeType
from iegen.ir.ast import IEG_Ast
from iegen.parser.ieg_api_parser import APIParser

ALL_LANGUAGES = sorted(list(default_config.languages))
ALL_PLATFORMS = sorted(list(default_config.platforms))


class CXXPrintProcsessor(object):

    def __call__(self, cursor, *args, **kwargs):
        print(f'Found {cursor.kind} Display name {cursor.displayname} \
              [line={cursor.location.line}, \
              col={cursor.location.column}]',
              f'Comments {cursor.raw_comment} Brief Comments {cursor.brief_comment}')


class CXXIEGIRBuilder(object):
    """
    Class to build intermediate representation.
    """

    def __init__(self, attributes=None, api_start_kw=None, parser_config=None):
        attributes = attributes or default_config.attributes
        api_start_kw = api_start_kw or default_config.api_start_kw
        self.attributes = attributes
        self.ieg_api_parser = APIParser(self.attributes, api_start_kw, ALL_LANGUAGES, ALL_PLATFORMS, parser_config)
        self.ir = IEG_Ast()
        self.node_stack = []
        self._sys_vars = {}
        self._processed_dirs = {}
        # cache for holding parent args
        self._parent_arg_mapping = {}

    def start_dir(self, dir_name):
        ctx = self.get_full_ctx()
        if dir_name not in self._processed_dirs:
            dir_node = DirectoryNode(dir_name, file_name=self.ieg_api_parser.yaml_api_file_name(dir_name))
            self.node_stack.append(dir_node)
            self.__update_internal_vars(dir_node)
            args = api = pure_comment = None
            parsed_api = self.ieg_api_parser.parse_yaml_api(dir_name, ctx)
            if parsed_api:
                api, args, pure_comment = parsed_api
            self.__process_attrs(dir_node, args, api, pure_comment)
        else:
            # directory is already processed
            dir_node = self._processed_dirs[dir_name]
            self.node_stack.append(dir_node)

    def end_dir(self, dir_name):
        assert self.node_stack, "stack should not be empty"
        node = self.node_stack.pop()
        assert node.name == dir_name
        # node is not processed and has an API call or child with API call
        if node.name not in self._processed_dirs and (node.api or node.children):
            if len(self.node_stack) > 0:
                parent_node = self.node_stack[-1]
                if node not in parent_node.children:
                    parent_node.add_children(node)
            elif node not in self.ir.roots:
                self.ir.roots.append(node)
        self._processed_dirs[dir_name] = node

    def start_tu(self, tu, *args, **kwargs):
        current_node = ClangNode(tu.cursor)
        current_node.args = OrderedDict()
        self.node_stack.append(current_node)
        self.__update_internal_vars(current_node)

    def end_tu(self, tu, *args, **kwargs):
        tu_node = self.node_stack.pop()
        if tu_node.api or tu_node.children:  # node has API call or child whit API call
            if len(self.node_stack) > 0:
                parent_node = self.node_stack[-1]
                parent_node.add_children(tu_node)
            else:
                # tu has no dir parent, add it to roots
                self.ir.roots.append(tu_node)
        # tu is processed it cannot be a parent anymore delete it's args if they're present
        self._parent_arg_mapping.pop(tu_node.full_displayname, None)

    def start_cursor(self, cursor, *args, **kwargs):
        current_node = ClangNode(cursor)
        self.node_stack.append(current_node)
        self.__update_internal_vars(current_node)

        ctx = self.get_full_ctx()

        api_parser_result = self.ieg_api_parser.parse_api(cursor, ctx)
        if not api_parser_result:
            return

        api, args, pure_comment = api_parser_result

        self.__process_attrs(current_node, args, api, pure_comment)

    def __process_attrs(self, current_node, args, api, pure_comment):
        args = args or OrderedDict()

        # add all missing attributes
        for att_name, properties in self.attributes.items():
            for plat in ALL_PLATFORMS + ["__all__"]:
                for lang in ALL_LANGUAGES + ["__all__"]:
                    att_val = args.get(
                        att_name,
                        {}
                    ).get(plat, {}).get(lang, None)

                    new_att_val = att_val
                    node_kind = current_node.kind_name
                    allowed = True
                    if "allowed_on" in properties:
                        allowed = node_kind in properties["allowed_on"]
                    if new_att_val is None:
                        # check mandatory attribute existence
                        node_kind = current_node.kind_name
                        if "required_on" in properties and node_kind in properties["required_on"]:
                            Error.error(f"Attribute '{att_name}' is mandatory attribute on {node_kind}.",
                                        current_node.file_name,
                                        current_node.line_number)
                            break

                        # inherit from parent or add default value
                        if properties["inheritable"]:
                            # directory based nodes may not have parent
                            self._parent_args = self._get_parent_args()
                            if self._parent_args:
                                new_att_val = self._parent_args.get(
                                    att_name,
                                    {}
                                ).get(plat, {}).get(lang, None)

                        if allowed:
                            if new_att_val is None:
                                # use default value
                                new_att_val = CXXIEGIRBuilder.get_attr_default_value(properties, plat, lang)
                                try:
                                    new_att_val = Template(new_att_val).render(self.get_sys_vars())
                                except TypeError:
                                    pass
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
                            new_att_val = self.ieg_api_parser.parse_attr(att_name, new_att_val)

                        args.setdefault(att_name, OrderedDict()).setdefault(plat, OrderedDict())[lang] = new_att_val

        current_node.api = api
        current_node.pure_comment = pure_comment
        assert args is not None
        current_node.args = args

    def _get_parent_args(self):
        if len(self.node_stack) < 2:
            return None
        direct_parent_name = self.node_stack[-2].full_displayname
        if direct_parent_name in self._parent_arg_mapping:
            return self._parent_arg_mapping[direct_parent_name]
        parents = reversed(self.node_stack[:-1])
        parent_args = None
        for parent in parents:
            if parent.api:
                parent_args = parent.args
                break
        self._parent_arg_mapping[direct_parent_name] = parent_args
        return parent_args

    def __update_internal_vars(self, node):
        sys_vars = {}
        if node.type == NodeType.DIRECTORY_NODE:
            sys_vars.update({
                '_is_operator': False,
                '_file_name': node.name,
                '_file_full_name': node.name,
                '_object_name': node.name
            })

        elif node.type == NodeType.CLANG_NODE:
            sys_vars.update({
                '_is_operator': node.clang_cursor.displayname.startswith('operator'),
                '_file_full_name': node.file_name,
                '_file_name': os.path.splitext(os.path.basename(node.file_name))[0],
                '_object_name': node.clang_cursor.spelling,
            })

        self._sys_vars.update(sys_vars)

    def get_sys_vars(self):
        sys_vars = copy.copy(self._sys_vars)
        return sys_vars

    def end_cursor(self, cursor, *args, **kwargs):
        node = self.node_stack.pop()
        if node.api or node.children:  # node has API call or child whit API call
            parent_node = self.node_stack[-1]
            if not node.api:
                self.__process_attrs(node, None, None, None)
            parent_node.add_children(node)
        # cursor is processed it cannot be a parent anymore delete it's args if they're present
        self._parent_arg_mapping.pop(node.full_displayname, None)

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

    def get_full_ctx(self):
        ctx = self.get_sys_vars()
        if len(self.node_stack) > 1:
            parent_args = self.node_stack[-2].args
            for attr_key, attr_val in parent_args.items():
                for plat_key, plat_val in attr_val.items():
                    ctx.setdefault(plat_key, SimpleNamespace())
                    for lang_key, val in plat_val.items():
                        ctx.setdefault(lang_key, SimpleNamespace())
                        if not hasattr(ctx[plat_key], lang_key):
                            setattr(ctx[plat_key], lang_key, SimpleNamespace())
                        if plat_key != '__all__' and lang_key != '__all__':
                            setattr(getattr(ctx[plat_key], lang_key), attr_key, val)
                        elif plat_key == '__all__' and lang_key == '__all__':
                            ctx[attr_key] = val
                        elif plat_key == '__all__':
                            setattr(ctx[lang_key], attr_key, val)
                        else:
                            setattr(ctx[plat_key], attr_key, val)
        return ctx
