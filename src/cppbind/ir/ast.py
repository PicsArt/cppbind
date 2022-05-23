# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
"""
from abc import abstractmethod, ABC
from collections import OrderedDict
from enum import Enum
from cached_property import cached_property
from sortedcontainers import SortedSet

import clang.cindex as cli
from cppbind.common.error import Error
import cppbind.utils.clang as cutil


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
        return self.signature == other.signature

    def __lt__(self, other):
        return self.signature < other.signature

    def __ne__(self, other):
        return not self.__eq__(other)

    def __hash__(self):
        return hash(self.signature)

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
    def signature(self):
        """Unique identifier of cursor"""
        return self.full_displayname

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

        # if signature is empty (e.g. for unexposed types) we assume the node to be not searchable/reusable
        # existence of unexposed cursor types can be dependant on platform (we have many of them on linux)
        if node.signature:
            # put node in node map to be able to find node by its name
            node.root._node_map[node.signature] = node

    @cached_property
    def ancestor_with_api(self):
        if not self.root._is_built():
            Error.internal("IR is not completely built. Access to 'ancestor_with_api' property is forbidden")

        node = self.parent
        while node:
            if node.api:
                return node
            node = node.parent
        return node

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
        self.__is_ir_built = False

    def __repr__(self):
        return f"RootNode({self.__dict__})"

    def walk(self):
        for node in self.walk_preorder():
            yield node

    def find_node(self, node_signature):
        """Returns node in IR by its unique signature"""
        return self._node_map.get(node_signature)

    def _get_all_nodes(self):
        """Returns map of all nodes"""
        return self._node_map.values()

    def _is_built(self):
        """Protected method to check whether IR is built or not"""
        return self.__is_ir_built

    def _set_built_flag(self):
        """Protected method to set IR built flag to true"""
        self.__is_ir_built = True

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

    @cached_property
    def full_displayname(self):
        assert self.clang_cursor, "cursor is not provided"
        return cutil.get_full_displayname(self.clang_cursor)

    @cached_property
    def signature(self):
        return cutil.get_signature(self.clang_cursor)

    @property
    def file_name(self):
        return self.clang_cursor.extent.start.file.name

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

    @cached_property
    def base_type_specifier_nodes(self):
        if not self.root._is_built():
            Error.internal("IR is not completely built. Access to 'base_type_specifier_nodes' property is forbidden")

        if not self.is_class_or_struct:
            return None

        base_type_specifier_nodes = []
        for base_specifier in self.clang_cursor.get_children():
            if base_specifier.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
                # used canonical type spelling to support typedef cases
                base_node = self.root.find_node(base_specifier.type.get_canonical().spelling)
                if base_node:
                    base_type_specifier_nodes.append(base_node)

        return base_type_specifier_nodes

    @cached_property
    def descendants(self):
        """List of all descendants of struct/class node"""

        if not self.root._is_built():
            Error.internal("IR is not completely built. Access to 'descendants' property is forbidden")

        if not self.is_class_or_struct:
            return None

        descendants = []
        # recursively construct list of descendants
        for direct_desc in self.direct_descendants:
            for node in direct_desc.descendants:
                if node not in descendants:
                    descendants.append(node)

        descendants.extend(self.direct_descendants)

        return descendants
