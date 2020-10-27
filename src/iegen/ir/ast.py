"""
"""
from collections import OrderedDict
import iegen.utils.clang as cutil


class Node(object):

    def __init__(self, clang_cursor, api=None, args=None,
                 parent=None, children=None, pure_comment=None):
        self.clang_cursor = clang_cursor
        self.api = api
        self.pure_comment = pure_comment
        self.args = args or OrderedDict()
        self.parent = parent
        self._children = children or []

    def __eq__(self, other):
        return self.full_displayname == other.full_displayname

    def __ne__(self, other):
        return not self.__eq__(other)

    def __hash__(self):
        return hash(self.full_displayname)

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
    def full_displayname(self):
        assert self.clang_cursor, "cursor is not provided"
        if not hasattr(self, '_full_displayname'):
            self._full_displayname = cutil.get_full_displayname(self.clang_cursor)

        return self._full_displayname

    @property
    def ancestor_with_api(self):
        if not hasattr(self, '_ancestor_with_api'):
            node = self.parent
            while(node):
                if node.api:
                    return node
                node = node.parent
            self._ancestor_with_api = node

        return self._ancestor_with_api

    @property
    def file_name(self):
        file_name = self.clang_cursor.extent.start.file.name
        return file_name

    def walk_preorder(self):
        """
        """

        # processor current node
        yield self

        # now if needed dive into children
        for child in self.children:
            for descendant in child.walk_preorder():
                yield descendant


class IEG_Ast(object):

    def __init__(self):
        self.roots = []

    def __repr__(self):
        return f"IEG_Ast({self.__dict__})"

    def walk(self):
        """
        """
        for root in self.roots:
            for node in root.walk_preorder():
                yield node
