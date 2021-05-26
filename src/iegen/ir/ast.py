"""
"""
from collections import OrderedDict
import iegen.utils.clang as cutil
import clang.cindex as cli


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
    def ancestor_with_api(self):
        if not hasattr(self, '_ancestor_with_api'):
            node = self.parent
            while node:
                if node.api:
                    return node
                node = node.parent
            self._ancestor_with_api = node

        return self._ancestor_with_api

    @property
    def file_name(self):
        file_name = self.clang_cursor.extent.start.file.name
        return file_name

    @property
    def line_number(self):
        return self.clang_cursor.extent.start.line

    @property
    def is_interface(self):
        return self.api == 'interface'

    @property
    def is_template(self):
        is_parent_template = self.parent and self.parent.is_template
        return self.clang_cursor.kind in [cli.CursorKind.CLASS_TEMPLATE,
                                          cli.CursorKind.FUNCTION_TEMPLATE] or is_parent_template

    @property
    def is_function_template(self):
        return self.clang_cursor.kind == cli.CursorKind.FUNCTION_TEMPLATE

    def type_name(self, template_choice=None):
        """
        Returns cxx type name for node with the given template choice(if template).
        Args:
            template_choice (dict): Containing template current value, e.g. {"T": "a::Project", "V": "int"}
        Returns:
            str: Type name.
        """
        # in case of a template class - cursor type is TypeKind.INVALID, that´s why cant get type spelling from the
        # cursor using this approach instead
        # for example for the type a::Stack<T> full_displayname=a::Stack, spelling=Stack, displayname=Stack<T>
        template_choice = template_choice or {}
        if self.is_template:
            cxx_type_name = self.full_displayname.replace(self.spelling, self.displayname)
            return cutil.replace_template_choice(cxx_type_name, template_choice)
        else:
            return self.clang_cursor.type.spelling

    def root_type_name(self, template_choice=None):
        """
        Returns cxx root type name for node with the given template choice(if template).
        Args:
            template_choice (dict): Containing template current value, e.g. {"T": "a::Project", "V": "int"}
        Returns:
            str: Root type name.
        """
        template_choice = template_choice or {}
        _root_cursor = cutil.get_base_cursor(self.clang_cursor)
        # might not work for typedefs need a check
        # getting canonical to get full name(with namespace) in case of template bases
        cxx_root_type_name = _root_cursor.type.get_canonical().spelling

        # in case of a template class - cursor type is TypeKind.INVALID, that´s why cant get type spelling from the
        if self.is_template:
            # if has no base get its type name with current choice
            if self.clang_cursor == _root_cursor:
                cxx_root_type_name = self.type_name(template_choice)
            else:
                cxx_root_type_name = cutil.replace_template_choice(
                    _root_cursor.type.spelling, template_choice)
        return cxx_root_type_name

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
