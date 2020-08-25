"""
Processor module provides various processor for ieg parser
"""

from collections import OrderedDict
from iegnen import (
    default_config as default_config,
)
from iegnen.parser.ieg_api_parser import APIParser
from iegnen.ir.ast import IEG_Ast, Node

ALL_LANGUAGES = list(default_config.languages)
ALL_LANGUAGES = sorted(ALL_LANGUAGES)


class CXXPrintProcsessor(object):

    def __call__(self, cursor, *args, **kwargs):
        print(f'Found {cursor.kind} Display name {cursor.displayname} \
              [line={cursor.location.line}, \
              col={cursor.location.column}]',
              f'Comments {cursor.raw_comment} Brief Comments {cursor.brief_comment}')


class CXXIEGIRBuilder(object):

    def __init__(self, attributes=None, api_start_kw=None):

        attributes = attributes or default_config.attributes
        api_start_kw = api_start_kw or default_config.api_start_kw
        self.attributes = attributes
        self.ieg_api_parser = APIParser(self.attributes, api_start_kw, ALL_LANGUAGES)
        self.ir = IEG_Ast()
        self.node_stack = []

    def start_tu(self, tu, *args, **kwargs):
        current_node = Node(tu.cursor)
        current_node.args = OrderedDict()
        self.node_stack.append(current_node)

    def end_tu(self, tu, *args, **kwargs):
        current_node = self.node_stack.pop()
        assert not self.node_stack, "stack should be empty"
        if current_node.children:  # node has child whit API call
            self.ir.roots.append(current_node)

    def start_cursor(self, cursor, *args, **kwargs):
        current_node = Node(cursor)
        self.node_stack.append(current_node)

        if self.ieg_api_parser.has_api(cursor.raw_comment):
            # todo: inheriting, error check, defaults and value parsing
            api, args =\
                self.ieg_api_parser.parse(cursor.raw_comment)

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
                        # inherit from parent or add default value
                        if properties["inheritable"]:
                            parrent_args = self.node_stack[-2].args
                            assert parrent_args is not None, f"Args missing for node {self.node_stack[-2]}"
                            new_att_val = parrent_args.get(
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

                    # now we need to process variables of value
                    if new_att_val is not None:
                        args.setdefault(att_name,
                                        OrderedDict())[lang] = new_att_val

            current_node.api = api
            assert args is not None
            current_node.args = args

    def end_cursor(self, cursor, *args, **kwargs):
        node = self.node_stack.pop()
        if node.api or node.children:  # node has API call or child whit API call
            parent_node = self.node_stack[-1]
            parent_node.add_children(node)


cxx_ieg_processor = CXXIEGIRBuilder()
