"""
Processor module provides various processor for ieg parser
"""

from iegnen import (
    default_config as default_config,
)
from iegnen.parser.ieg_api_parser import APIParser
from iegnen.ir.ast import IEG_Ast, Node


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
        self.ieg_api_parser = APIParser(attributes, api_start_kw)
        self.ir = IEG_Ast()
        self.node_stack = []

    def start_tu(self, tu, *args, **kwargs):
        current_node = Node(tu.cursor)
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
            current_node.api,\
                current_node.args =\
                self.ieg_api_parser.parse(cursor.raw_comment)

    def end_cursor(self, cursor, *args, **kwargs):
        node = self.node_stack.pop()
        if node.api or node.children:  # node has API call or child whit API call
            parent_node = self.node_stack[-1]
            parent_node.add_children(node)


cxx_ieg_processor = CXXIEGIRBuilder()
