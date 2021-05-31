"""
Processor module provides various processor for ieg parser
"""
import copy
import os
from collections import OrderedDict

from iegen import default_config as default_config
from iegen.ir.ast import IEG_Ast, DirectoryNode, ClangNode, NodeType
from iegen.parser.ieg_api_parser import APIParser

ALL_LANGUAGES = list(default_config.languages)
ALL_LANGUAGES = sorted(ALL_LANGUAGES)


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
        self.config = parser_config or default_config.parser
        attributes = attributes or default_config.attributes
        api_start_kw = api_start_kw or default_config.api_start_kw
        self.attributes = attributes
        self.ieg_api_parser = APIParser(self.attributes, api_start_kw, ALL_LANGUAGES, parser_config)
        self.ir = IEG_Ast()
        self.node_stack = []
        self._sys_vars = {}
        self.processed_dirs = {}

    def start_dir(self, dir_name):
        if dir_name not in self.processed_dirs:
            dir_node = DirectoryNode(dir_name)
            self.processed_dirs[dir_name] = dir_node
            if self.node_stack:
                parent_node = self.node_stack[-1]
                if parent_node:
                    parent_node.add_children(dir_node)

            parsed_api = self.ieg_api_parser.parse_yaml_api(dir_name)
            if parsed_api:
                api, args, pure_comment = self.ieg_api_parser.parse_yaml_api(dir_name)

                self.__add_missing_attributes(dir_node, args, api, pure_comment)
        else:
            # directory is already processed
            dir_node = self.processed_dirs[dir_name]
        self.__update_internal_vars(dir_node)
        self.node_stack.append(dir_node)

    def end_dir(self, dir_name):
        assert self.node_stack, "stack should not be empty"
        node = self.node_stack.pop()
        assert node.name == dir_name
        if not node.parent and node not in self.ir.roots:
            self.ir.roots.append(node)

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

    def start_cursor(self, cursor, *args, **kwargs):
        current_node = ClangNode(cursor)
        self.node_stack.append(current_node)
        self.__update_internal_vars(current_node)

        api_parser_result = self.ieg_api_parser.parse_api(cursor)
        if not api_parser_result:
            return

        api, args, pure_comment = api_parser_result

        self.__add_missing_attributes(current_node, args, api, pure_comment)

    def __add_missing_attributes(self, current_node, args, api, pure_comment):
        args = args or OrderedDict()

        # add all missing attributes
        for att_name, properties in self.attributes.items():
            for lang in ALL_LANGUAGES:
                att_val = args.get(
                    att_name,
                    {}
                ).get(lang, None)

                new_att_val = att_val
                if new_att_val is None:
                    # check mandatory attribute existence
                    node_kind = current_node.kind_name
                    if "required_on" in properties and node_kind in properties["required_on"]:
                        raise Exception(f"Attribute {att_name} is mandatory attribute on {node_kind}.")

                    # inherit from parent or add default value
                    if properties["inheritable"]:
                        if len(self.node_stack) > 1:
                            # directory based nodes might not have parent
                            parent_args = self.node_stack[-2].args
                            new_att_val = parent_args.get(
                                att_name,
                                {}
                            ).get(lang, None)

                    if new_att_val is None:
                        # use default value
                        new_att_val = properties.get("default", None)
                else:
                    # attribute is set check weather or not it is allowed.
                    if "allowed_on" in properties:
                        node_kind = current_node.kind_name
                        if node_kind not in properties["allowed_on"]:
                            raise Exception(f"Attribute {att_name} is not allowed on {node_kind}.")

                # now we need to process variables of value and set value
                if new_att_val is not None:
                    if isinstance(new_att_val, str):
                        new_att_val = new_att_val.format(**self.get_sys_vars(lang))
                        # sys vars can have different types than string parse to get correct type
                        new_att_val = self.ieg_api_parser.parse_attr(att_name, new_att_val)

                    args.setdefault(att_name,
                                    OrderedDict())[lang] = new_att_val
        current_node.api = api
        current_node.pure_comment = pure_comment
        assert args is not None
        current_node.args = args

    def __update_internal_vars(self, node):
        sys_vars = {}
        if node.type == NodeType.DIRECTORY_NODE:
            sys_vars = {
                'file_name': node.name,
                'file_full_name': node.name,
                'object_name': node.name
            }

        if node.type == NodeType.CLANG_NODE:
            sys_vars = {
                'is_operator': node.clang_cursor.displayname.startswith('operator'),
                'file_full_name': node.file_name,
                'file_name': os.path.splitext(os.path.basename(node.file_name))[0],
                'object_name': node.clang_cursor.spelling,
                'module_name': ''
            }

        self._sys_vars.update(sys_vars)

    def get_sys_vars(self, lang):
        sys_vars = copy.copy(self._sys_vars)
        module_name = self.get_module_name(lang)
        sys_vars['module_name'] = module_name
        return sys_vars

    def get_module_name(self, lang):
        module_att_name = 'module'
        if module_att_name not in self.attributes:
            return ''
        parent_module = []
        properties = self.attributes[module_att_name]
        allowed_on = properties.get('allowed_on', [])
        for node in reversed(self.node_stack[:-1]):
            if not allowed_on or node.kind_name in allowed_on:
                mod = node.args.get("module", None)
                if mod is not None:
                    parent_module = [mod.get(lang)]
                    break

        current_node = self.node_stack[-1]
        if not allowed_on or current_node.kind_name in allowed_on:
            parent_module.append(current_node.spelling)

        return '.'.join(parent_module)

    def end_cursor(self, cursor, *args, **kwargs):
        node = self.node_stack.pop()
        if node.api or node.children:  # node has API call or child whit API call
            parent_node = self.node_stack[-1]
            parent_node.add_children(node)
