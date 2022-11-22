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
import cppbind.utils.clang as cutil
from cppbind.ir.cxx_element import CXXElement
from cppbind.ir.cxx_type import CXXType
from . import ElementKind
from .utils import allowed_after_build, available_on


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

    @abstractmethod
    def __iter__(self):
        # each node is an iterator and defines its iteration order
        pass

    @abstractmethod
    def __next__(self):
        # each node is an iterator and defines its iteration order
        pass

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
        # existence of unexposed cursor types can be dependent on platform (we have many of them on linux)
        if node.signature:
            # keep the node with template_type_name (type name without template parameters) for lookups
            if node.type == NodeType.CLANG_NODE and node.is_class_or_struct and node.cxx_element.is_templated:
                template_type_name = cutil.template_type_name(node.signature)
                if template_type_name in node.root._node_map:
                    # a template specialization, add it to template nodes map
                    template_node = node.root._node_map[template_type_name]
                    template_node._template_spec_node_map[node.signature] = node
                else:
                    # a template node add it to root node_map
                    node.root._node_map[cutil.template_type_name(node.signature)] = node
            else:
                node.root._node_map[node.signature] = node

    @cached_property
    @allowed_after_build
    def ancestor_with_api(self):
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
        for child in self:
            for descendant in child.walk_preorder():
                yield descendant


class DirectoryNode(Node):

    def __init__(self, name, file_name=None, api=None, args=None, root=None, parent=None, children=None,
                 pure_comment=None):
        super().__init__(api, args, root, parent, children, pure_comment)
        self.name = name
        self._file_name = file_name

    def __iter__(self):
        # directory nodes are skipped from further iteration
        # root provides iteration on files by their processing order
        return self

    def __next__(self):
        # directory nodes are skipped from further iteration
        # root provides iteration on files by their processing order
        raise StopIteration

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
        # IR keeps the order of processed files to provide an iterator with correct order
        self.__ordered_nodes = []

    def __repr__(self):
        return f"RootNode({self.__dict__})"

    def __iter__(self):
        # root node is an iterator and keeps all directories and files by their processing order
        self.idx = 0
        self.__length = len(self.__ordered_nodes)
        return self

    def __next__(self):
        # root node is an iterator and keeps all directories and files by their processing order
        # directories are iterated first and then files in their processing order
        if self.idx < self.__length:
            next_node = self.__ordered_nodes[self.idx]
            self.idx += 1
            return next_node
        raise StopIteration

    def walk(self):
        for node in self.walk_preorder():
            yield node

    def find_node(self, node_signature, match_template=True):
        """Returns node in IR by its unique signature"""
        node = self._node_map.get(node_signature)
        if node:
            return node
        if cutil.is_templated(node_signature):
            template_node = self._node_map.get(cutil.template_type_name(node_signature))
            if template_node:
                return template_node._template_spec_node_map.get(node_signature, None if match_template else template_node)
        return None

    def find_node_by_type(self, type_, match_template=True):
        """Find node by cursor Type, CXXType or string"""

        search_name = type_
        if isinstance(type_, (cli.Type, CXXType)):
            # decl is None for the types which are invalid or unexposed
            decl = cutil.get_declaration(type_) if isinstance(type_, cli.Type) else type_.get_declaration()
            return self.find_node(cutil.get_signature(decl), match_template) if decl else None
        return self.find_node(search_name, match_template)

    def _get_all_nodes(self):
        """Returns map of all nodes"""
        return self._node_map.values()

    def _is_built(self):
        """Protected method to check whether IR is built or not"""
        return self.__is_ir_built

    def _finalize_ir_build(self, processed_files):
        """Protected method to set IR built flag to true and to define ir nodes by correct order."""
        self.__is_ir_built = True
        dir_nodes = []
        self.__get_directory_nodes(self, dir_nodes)
        self.__ordered_nodes = dir_nodes + [self._node_map[file] for file in processed_files]
        self.__length = len(self.__ordered_nodes)

    def __get_directory_nodes(self, node, nodes):
        for child in node.children:
            if child.type == NodeType.DIRECTORY_NODE:
                nodes.append(child)
                self.__get_directory_nodes(child, nodes)

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
        self.cxx_element = CXXElement.create_cxx_element(clang_cursor)

    def __iter__(self):
        # clang node is an iterator and gives its child nodes by their processing order
        self.idx = 0
        self.__length = len(self._children)
        return self

    def __next__(self):
        # clang node is an iterator and gives its child nodes by their processing order
        if self.idx < self.__length:
            next_node = self._children[self.idx]
            self.idx += 1
            return next_node
        raise StopIteration

    @property
    def kind(self):
        return self.cxx_element.kind

    @property
    def displayname(self):
        return self.cxx_element.displayname

    @property
    def spelling(self):
        return self.cxx_element.spelling

    @cached_property
    def full_displayname(self):
        return self.cxx_element.get_full_displayname()

    @cached_property
    def signature(self):
        return self.cxx_element.get_signature()

    @property
    def file_name(self):
        return self.cxx_element.extent.start.file.name

    @property
    def line_number(self):
        return self.cxx_element.extent.start.line


class FileNode(Node):

    def __init__(self, file_path, api=None, args=None, root=None, parent=None, children=None, pure_comment=None):
        super().__init__(api, args, root, parent, children, pure_comment)
        self.file_path = file_path

    def __iter__(self):
        self.idx = 0
        self.__length = len(self._children)
        return self

    def __next__(self):
        if self.idx < self.__length:
            next_node = self._children[self.idx]
            self.idx += 1
            return next_node
        raise StopIteration

    @property
    def displayname(self):
        return self.file_path

    @property
    def spelling(self):
        return self.file_path

    @property
    def line_number(self):
        return None

    @cached_property
    def signature(self):
        return self.file_path

    @property
    def file_name(self):
        return self.file_path

    @property
    def type(self):
        return NodeType.FILE_NODE

    @property
    def kind_name(self):
        return FILE_KIND_NAME

    @property
    def full_displayname(self):
        return self.file_path


class CXXNode(ClangNode):

    def __init__(self, clang_cursor, api=None, args=None, root=None, parent=None, children=None, pure_comment=None):
        super().__init__(clang_cursor, api, args, root, parent, children, pure_comment)
        # keep direct descendants in sorted set to have deterministic order of nodes
        self.direct_descendants = SortedSet()
        self._template_spec_node_map = {}

    @property
    def type(self):
        return NodeType.CLANG_NODE

    @property
    def kind_name(self):
        return self.cxx_element.kind_name

    @property
    def is_class_or_struct(self):
        return self.cxx_element.kind in (ElementKind.STRUCT_DECL,
                                         ElementKind.CLASS_DECL,
                                         ElementKind.CLASS_TEMPLATE,
                                         ElementKind.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION)

    @cached_property
    @allowed_after_build
    def _base_type_specifier_nodes(self):
        if not self.is_class_or_struct:
            return None

        base_type_specifier_nodes = []
        for base_specifier in self.cxx_element.get_children():
            if base_specifier.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
                base_type = base_specifier.type
                # lookup with type spelling, then with canonical type name spelling
                # (to support template usages with namespace)
                base_node = self.root.find_node(base_type.spelling, match_template=False)
                if base_node is None:
                    # canonical type spelling is used in case of typedefs
                    base_node = self.root.find_node(base_type.get_canonical().spelling, match_template=False)

                if base_node:
                    base_type_specifier_nodes.append(base_node)

        return base_type_specifier_nodes

    @cached_property
    @allowed_after_build
    def descendants(self):
        """List of all descendants of struct/class node"""

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

    @allowed_after_build
    def find_adjacent_nodes(self, search_names, search_api=None):
        """Search for adjacent nodes by name/api"""
        return (self.root.find_node_by_type(node.signature) for node in self.parent.children
                if (search_api is None or node.api == search_api) and node.spelling in search_names)

    def find_adjacent_node(self, search_names, search_api=None):
        """Search for an adjacent node by search name/api"""
        return next(self.find_adjacent_nodes(search_names, search_api), None)

    @cached_property
    @available_on(cli.CursorKind.CXX_METHOD,
                  cli.CursorKind.FUNCTION_DECL,
                  cli.CursorKind.CONSTRUCTOR,
                  cli.CursorKind.FUNCTION_TEMPLATE)
    def overloading_index(self):
        """Find overloading index of the given function/method/ctor node"""

        search_api = self.api
        name = self.spelling
        search_names = {name}
        overloads = self.find_adjacent_nodes(search_names, search_api)
        for i, ctx in enumerate(overloads):
            if ctx == self:
                return i

        return None
