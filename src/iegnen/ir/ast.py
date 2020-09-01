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
        self._children = children or []

    def add_children(self, node):
        """TODO: Docstring for add_children.

        :node: TODO
        :returns: TODO

        """
        node.parent = self
        self._children.append(node)

    @property
    def children(self):
        return self._children

    def __repr__(self):
        return f"Node(api={self.api}, args={self.args} children={self.children})"

    @property
    def kind_name(self):
        assert self.clang_cursor, "cursor is not provided"
        cl_kind = self.clang_cursor.kind.name.lower().replace("_decl", "")
        return cl_kind

    @property
    def displayname(self):
        assert self.clang_cursor, "cursor is not provided"
        return self.clang_cursor.displayname

    @property
    def spelling(self):
        assert self.clang_cursor, "cursor is not provided"
        return self.clang_cursor.spelling

    @property
    def type_name(self):
        assert self.clang_cursor, "cursor is not provided"
        return self.clang_cursor.type.spelling

    @property
    def ancestor_with_api(self):
        node = self.parent
        while(node):
            if node.api:
                return node
            node = node.parent
        return node

    @property
    def file_name(self):
        file_name = self.clang_cursor.extent.start.file.name
        return file_name


class IEG_Ast(object):

    def __init__(self):
        self.roots = []

    def __repr__(self):
        return f"IEG_Ast({self.__dict__})"

    def walk(self):
        """
        """
        for root in self.roots:
            for node in self.cursor_walk(root):
                yield node

    def cursor_walk(self, cursor):
        """
        """

        # processor current cursor
        yield cursor

        # now if needed dive into children
        for child in cursor.children:
            for descendant in self.cursor_walk(child):
                yield descendant
