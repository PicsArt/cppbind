"""
"""
from abc import abstractmethod, ABC
from collections import OrderedDict
from enum import Enum
from sortedcontainers import SortedSet

import clang.cindex as cli
import iegen.utils.clang as cutil


class NodeType(Enum):
    CLANG_NODE = 1
    DIRECTORY_NODE = 2
    ROOT_NODE = 3
    FILE_NODE = 4


ROOT_KIND_NAME = "root"
DIR_KIND_NAME = "dir"
FILE_KIND_NAME = "file"


class Node(ABC):
    API_NONE = 'none'

    def __init__(self, api=None, args=None, root=None, parent=None, children=None, pure_comment=None):
        self.api = api
        self.pure_comment = pure_comment
        self.args = args or OrderedDict()
        self.root = root
        self.parent = parent
        self._children = children or []

    def __eq__(self, other):
        return self.full_displayname == other.full_displayname

    def __lt__(self, other):
        return self.full_displayname < other.full_displayname

    def __ne__(self, other):
        return not self.__eq__(other)

    def __hash__(self):
        return hash(self.full_displayname)

    def __repr__(self):
        return f"Node(api={self.api}, args={self.args} children={self.children})"

    @property
    @abstractmethod
    def type(self):
        pass

    @property
    @abstractmethod
    def full_displayname(self):
        pass

    @property
    @abstractmethod
    def kind_name(self):
        pass

    @property
    def children(self):
        return self._children

    def add_child(self, node):
        """Add child node to parent node"""
        node.parent = self
        self._children.append(node)

        # put node in node map to be able to find node by its name
        node.root._node_map[node.full_displayname] = node

    @property
    def ancestor_with_api(self):
        if not hasattr(self, '_ancestor_with_api'):
            node = self.parent
            while node:
                if node.api:
                    return node
                node = node.parent
            self._ancestor_with_api = node

        return self._ancestor_with_api

    def walk_preorder(self):

        # processor current node
        yield self

        # now if needed dive into children
        for child in self.children:
            for descendant in child.walk_preorder():
                yield descendant


class DirectoryNode(Node):

    def __init__(self, name, file_name=None, api=None, args=None, root=None, parent=None, children=None, pure_comment=None):
        super().__init__(api, args, root, parent, children, pure_comment)
        self.name = name
        self._file_name = file_name

    @property
    def file_name(self):
        return self._file_name

    @property
    def line_number(self):
        return None

    @property
    def type(self):
        return NodeType.DIRECTORY_NODE

    @property
    def kind_name(self):
        return DIR_KIND_NAME

    @property
    def displayname(self):
        return self.name

    @property
    def full_displayname(self):
        return self.name


class RootNode(Node):
    ROOT_KEY = '__root__'

    def __init__(self):
        super().__init__(api=Node.API_NONE, args=None, root=self, parent=None, children=None, pure_comment=None)
        self.name = RootNode.ROOT_KEY
        self._node_map = {}

    def __repr__(self):
        return f"RootNode({self.__dict__})"

    def walk(self):
        for node in self.walk_preorder():
            yield node

    def find_node(self, node_display_name):
        """Returns node in IR by its display name"""
        return self._node_map.get(node_display_name)

    def _get_all_nodes(self):
        """Returns map of all nodes"""
        return self._node_map.values()

    @property
    def type(self):
        return NodeType.ROOT_NODE

    @property
    def full_displayname(self):
        return "Root"

    @property
    def kind_name(self):
        return ROOT_KIND_NAME

    @property
    def displayname(self):
        return self.name


class ClangNode(Node, ABC):

    def __init__(self, clang_cursor, api=None, args=None, root=None, parent=None, children=None, pure_comment=None):
        super().__init__(api, args, root, parent, children, pure_comment)
        self.clang_cursor = clang_cursor

    @property
    def kind(self):
        assert self.clang_cursor, "cursor is not provided"
        return self.clang_cursor.kind

    @property
    def displayname(self):
        assert self.clang_cursor, "cursor is not provided"
        return self.clang_cursor.displayname

    @property
    def spelling(self):
        assert self.clang_cursor, "cursor is not provided"
        return self.clang_cursor.spelling

    @property
    def full_displayname(self):
        assert self.clang_cursor, "cursor is not provided"
        if not hasattr(self, '_full_displayname'):
            self._full_displayname = cutil.get_full_displayname(self.clang_cursor)

        return self._full_displayname

    @property
    def file_name(self):
        file_name = self.clang_cursor.extent.start.file.name
        return file_name

    @property
    def line_number(self):
        return self.clang_cursor.extent.start.line


class FileNode(ClangNode):

    def __init__(self, clang_cursor, api=None, args=None, root=None, parent=None, children=None, pure_comment=None):
        super().__init__(clang_cursor, api, args, root, parent, children, pure_comment)

    @property
    def type(self):
        return NodeType.FILE_NODE

    @property
    def kind_name(self):
        assert self.clang_cursor, "cursor is not provided"
        assert self.clang_cursor.kind == cli.CursorKind.TRANSLATION_UNIT
        return FILE_KIND_NAME

    @property
    def full_displayname(self):
        return self.clang_cursor.extent.start.file.name


class CXXNode(ClangNode):

    def __init__(self, clang_cursor, api=None, args=None, root=None, parent=None, children=None, pure_comment=None):
        super().__init__(clang_cursor, api, args, root, parent, children, pure_comment)
        # keep direct descendants in sorted set to have deterministic order of nodes
        self.direct_descendants = SortedSet()

    @property
    def type(self):
        return NodeType.CLANG_NODE

    @property
    def kind_name(self):
        assert self.clang_cursor, "cursor is not provided"
        cl_kind = self.clang_cursor.kind.name.lower().replace("_decl", "")
        return cl_kind

    @property
    def is_template(self):
        is_parent_template = self.parent and self.parent.type == NodeType.CLANG_NODE and self.parent.is_template
        return self.clang_cursor.kind in [cli.CursorKind.CLASS_TEMPLATE,
                                          cli.CursorKind.FUNCTION_TEMPLATE] or is_parent_template

    @property
    def is_function_template(self):
        return self.clang_cursor.kind == cli.CursorKind.FUNCTION_TEMPLATE

    @property
    def is_class_or_struct(self):
        return self.clang_cursor.kind in (cli.CursorKind.STRUCT_DECL,
                                          cli.CursorKind.CLASS_DECL,
                                          cli.CursorKind.CLASS_TEMPLATE)

    @property
    def base_type_specifier_nodes(self):
        if not self.is_class_or_struct:
            return None

        if not hasattr(self, '__base_type_specifier_nodes'):
            base_type_specifier_nodes = []
            for base_specifier in self.clang_cursor.get_children():
                if base_specifier.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
                    base_node = self.root.find_node(base_specifier.type.spelling)
                    if base_node:
                        base_type_specifier_nodes.append(base_node)

            self.__base_type_specifier_nodes = base_type_specifier_nodes

        return self.__base_type_specifier_nodes

    @property
    def descendants(self):
        """List of all descendants of struct/class node"""
        if not self.is_class_or_struct:
            return None

        # logic for caching
        if not hasattr(self, '__descendants'):
            descendants = []
            # recursively construct list of descendants
            for direct_desc in self.direct_descendants:
                for node in direct_desc.descendants:
                    if node not in descendants:
                        descendants.append(node)

            descendants.extend(self.direct_descendants)

            self.__descendants = descendants

        return self.__descendants
