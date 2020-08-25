"""
"""
from collections import OrderedDict


class Node(object):

    def __init__(self, clang_cursor, api=None, args=None,
                 parent=None, children=None):
        self.clang_cursor = clang_cursor
        self.api = api
        self.args = args or OrderedDict()
        self.parent = parent
        self.children = children or []

    def add_children(self, node):
        """TODO: Docstring for add_children.

        :node: TODO
        :returns: TODO

        """
        node.parent = self
        self.children.append(node)

    def __repr__(self):
        return f"Node(api={self.api}, args={self.args} children={self.children})"

    @property
    def kind_name(self):
        assert self.clang_cursor, "cursor is not provided"
        cl_kind = self.clang_cursor.kind.name.lower().replace("_decl", "")
        return cl_kind


class IEG_Ast(object):

    def __init__(self):
        self.roots = []

    def __repr__(self):
        return f"IEG_Ast({self.__dict__})"
