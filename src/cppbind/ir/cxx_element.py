# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.


"""Module to define cxx related element class and its dependencies"""

import types

from cached_property import cached_property

import clang.cindex as cli
import cppbind.utils.clang as cutil
from cppbind.utils import DefaultValueKind
from .cxx_type import CXXType


class CXXElement:
    """Wrapper base type on clang cursor to provide unified access to cxx functionality/properties"""

    def __init__(self, clang_cursor):
        self._clang_cursor = clang_cursor

    @property
    def type(self):
        """Get the type of the current cursor"""
        return CXXType(self._clang_cursor.type)

    def get_full_displayname(self):
        """The full displayname of the cursor"""
        return cutil.get_full_displayname(self._clang_cursor)

    def get_signature(self):
        """The signature of the cursor"""
        return cutil.get_signature(self._clang_cursor)

    def get_template_parameter_cursors(self):
        """Returns the list of template parameter cursors for the clang cursor"""
        return cutil.get_template_parameter_cursors(self._clang_cursor)

    @property
    def kind_name(self):
        """Kind name of the cursor"""

        cl_kind = self._clang_cursor.kind.name.lower().replace("_decl", "").replace("cxx_", "")
        if self._clang_cursor.kind == cli.CursorKind.FUNCTION_TEMPLATE:
            if self._clang_cursor.lexical_parent.kind in (cli.CursorKind.STRUCT_DECL,
                                                          cli.CursorKind.CLASS_DECL,
                                                          cli.CursorKind.CLASS_TEMPLATE,
                                                          cli.CursorKind.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION):
                if self._clang_cursor.spelling == self._clang_cursor.lexical_parent.spelling:
                    return 'constructor_template'
                else:
                    return 'method_template'

        return cl_kind

    @property
    def name(self):
        """Spelling of the cursor"""
        return self._clang_cursor.spelling

    @property
    def displayname(self):
        """Display name of the cursor"""
        return self._clang_cursor.displayname

    @property
    def source_file_name(self):
        """The source file path of the cursor"""
        return self._clang_cursor.extent.start.file.name

    @property
    def is_public(self):
        """Whether the cursor accessibility is public"""
        return self._clang_cursor.access_specifier == cli.AccessSpecifier.PUBLIC

    @property
    def is_private(self):
        """Whether the cursor accessibility is private"""
        return self._clang_cursor.access_specifier == cli.AccessSpecifier.PRIVATE

    @property
    def is_protected(self):
        """Whether the cursor accessibility is protected"""
        return self._clang_cursor.access_specifier == cli.AccessSpecifier.PROTECTED

    @property
    def raw_comment(self):
        """Returns the raw comment text associated with the cursor"""
        return self._clang_cursor.raw_comment

    @cached_property
    def namespace(self):
        """The namespace of the cursor"""

        namespaces = []
        parent = self._clang_cursor.lexical_parent
        while parent and parent.kind == cli.CursorKind.NAMESPACE:
            if parent.spelling:
                namespaces.append(parent.spelling)
            parent = parent.lexical_parent

        return '::'.join(reversed(namespaces))

    @property
    def is_abstract(self):
        """Checks whether the cursor is an abstract record"""
        return self._clang_cursor.is_abstract_record()

    @property
    def is_open(self):
        """Checks whether the function cursor is open"""
        return not cutil.is_final_cursor(self._clang_cursor)

    @property
    def is_templated(self):
        """Checks whether the cursor is templated"""
        return cutil.is_templated(self._clang_cursor)

    @cached_property
    def template_parameters(self):
        """Return the list of namespaces containing template parameter information.
         For example for
          template <typename T, typename... Ts> class tuple {}
        will return:
        [
            SimpleNamespace(is_variadic=False, kind=CursorKind.TEMPLATE_TYPE_PARAMETER, spelling='T'),
            SimpleNamespace(is_variadic=True, kind=CursorKind.TEMPLATE_TYPE_PARAMETER, spelling='Ts'),
        ]"""

        return [types.SimpleNamespace(
            is_variadic=cutil.is_variadic(c),
            kind=c.kind,
            spelling=c.spelling
        ) for c in self.get_template_parameter_cursors()]

    @property
    def parent(self):
        """
        Returns:
            Lexical parent of current element.
        """

        lexical_parent = self._clang_cursor.lexical_parent
        return CXXElement.create_cxx_element(lexical_parent) if lexical_parent else None

    @staticmethod
    def create_cxx_element(clang_cursor):
        """Static factory method to create a cxx element based on the cursor kind"""

        kind = clang_cursor.kind
        if kind == cli.CursorKind.ENUM_DECL:
            return CXXEnumElement(clang_cursor)
        if kind in (
                cli.CursorKind.FUNCTION_DECL,
                cli.CursorKind.FUNCTION_TEMPLATE,
                cli.CursorKind.CXX_METHOD,
                cli.CursorKind.CONSTRUCTOR
        ):
            return CXXFunctionElement(clang_cursor)
        if kind in (
                cli.CursorKind.CLASS_DECL,
                cli.CursorKind.STRUCT_DECL,
                cli.CursorKind.CLASS_TEMPLATE,
                cli.CursorKind.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION
        ):
            return CXXClassElement(clang_cursor)
        if kind == cli.CursorKind.PARM_DECL:
            return CXXArgumentElement(clang_cursor)
        if kind == cli.CursorKind.FIELD_DECL:
            return CXXMemberElement(clang_cursor)

        return CXXElement(clang_cursor)

    def __getattr__(self, prop):
        """
        Delegate all missing properties to the underlying clang Cursor object.
        This is done to eliminate the usages of cursor and use cxx element instead of it.
        """

        if not hasattr(self._clang_cursor, prop):
            raise AttributeError(f"{self.__class__.__name__}.{prop} is invalid")

        return getattr(self._clang_cursor, prop)


class CXXEnumElement(CXXElement):
    """Wrapper type on clang enum cursor"""

    def __init__(self, clang_cursor):
        super(CXXEnumElement, self).__init__(clang_cursor)

    @property
    def type_name(self):
        return self._clang_cursor.type.spelling

    @cached_property
    def enum_cases(self):
        """Information about enum cases"""

        _values = []
        last_case_comment = None
        for enum_value_c in self._clang_cursor.walk_preorder():
            if enum_value_c.kind != cli.CursorKind.ENUM_CONSTANT_DECL:
                continue
            if enum_value_c.raw_comment != last_case_comment:
                comment = cutil.extract_pure_comment(enum_value_c.raw_comment)
            elif last_case_comment:
                comment = ['', 'The same as previous case comment.', '']
            else:
                comment = None
            last_case_comment = enum_value_c.raw_comment
            enum_val_params = types.SimpleNamespace(name=enum_value_c.spelling,
                                                    value=enum_value_c.enum_value,
                                                    comment=comment)
            _values.append(enum_val_params)

        return _values


class CXXClassElement(CXXElement):
    """Wrapper type on clang class/struct cursor"""

    def __init__(self, clang_cursor):
        super(CXXClassElement, self).__init__(clang_cursor)

    @property
    def type_name(self):
        return self._clang_cursor.type.spelling

    @property
    def is_polymorphic(self):
        """Checks the cursor corresponds to a polymorphic type"""
        return cutil.is_polymorphic(self._clang_cursor)

    @property
    def has_multiple_base_branches(self):
        """Checks the class/struct has multiple base branches in its hierarchy"""
        return cutil.has_multiple_base_branches(self._clang_cursor)

    @property
    def is_template(self):
        """Checks whether the class/struct cursor corresponds to a template"""
        return self._clang_cursor.kind in (
            cli.CursorKind.CLASS_TEMPLATE, cli.CursorKind.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION)

    @property
    def base_type_elements(self):
        """
        Returns:
            List of base type elements.
        """

        _base_type_elements = []
        cursor = self._clang_cursor
        if self._clang_cursor.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
            cursor = self._clang_cursor.get_definition()
        for base_specifier in cursor.get_children():
            if base_specifier.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
                _base_type_elements.append(CXXClassElement(base_specifier))

        return _base_type_elements

    @property
    def ancestors(self):
        """
        Returns:
            List of ancestor elements.
        Raises:
            AttributeError: If current element is not a class/struct.
        """

        def walk(base_type_elements):
            for base in base_type_elements:
                for _base in walk(base.base_type_elements):
                    yield _base
                yield base

        return list(walk(self.base_type_elements))

    @cached_property
    def base_types(self):
        """
        Returns:
            List of base types.
        """
        return [element.type for element in self.base_type_elements]


class CXXFunctionElement(CXXElement):
    """Wrapper type on clang function/method cursor"""

    def __init__(self, clang_cursor):
        super(CXXFunctionElement, self).__init__(clang_cursor)

    @property
    def is_template(self):
        """Checks whether the function cursor corresponds to a template"""
        return self._clang_cursor.kind == cli.CursorKind.FUNCTION_TEMPLATE

    @property
    def is_static(self):
        """Checks whether the function cursor is static"""
        return self._clang_cursor.is_static_method()

    @property
    def is_const(self):
        """Checks whether the function cursor is const"""
        return self._clang_cursor.is_const_method()

    @property
    def is_overloaded(self):
        """Checks the function cursor is overloaded"""
        return cutil.is_overloaded(self._clang_cursor)

    @cached_property
    def overridden_elements(self):
        """
        Returns:
            List of overridden elements.
        """

        def _get_overridden_elems(cxx_element):

            elements = []
            if cxx_element.kind == cli.CursorKind.CXX_METHOD and cxx_element.get_overriden_cursors():
                for overridden in cxx_element.get_overriden_cursors():
                    elements.append(CXXFunctionElement(overridden))
                    elements += _get_overridden_elems(overridden)
            return elements

        return _get_overridden_elems(self)

    @property
    def result_type(self):
        """Return type info for function"""

        if self._clang_cursor.kind == cli.CursorKind.CONSTRUCTOR:
            return None

        return CXXType(self._clang_cursor.result_type)

    @property
    def args(self):
        """Argument elements of the function element"""

        _args = []

        # for function templates Cursor.get_arguments returns an empty array,
        # using get_children instead
        if self._clang_cursor.kind == cli.CursorKind.FUNCTION_TEMPLATE:
            for i, arg_c in enumerate(self._clang_cursor.get_children()):
                if arg_c.kind == cli.CursorKind.PARM_DECL:
                    # pass arg_idx to CXXArgumentElement to use arg{i} name instead of spelling when spelling is empty
                    _args.append(CXXArgumentElement(arg_c, arg_idx=i))
        else:
            for i, arg_c in enumerate(self._clang_cursor.get_arguments()):
                # pass arg_idx to CXXArgumentElement to use arg{i} name instead of spelling when spelling is empty
                _args.append(CXXArgumentElement(arg_c, arg_idx=i))

        return _args


class CXXArgumentElement(CXXElement):
    """Wrapper type on clang argument/parameter cursor"""

    def __init__(self, clang_cursor, arg_idx=None):
        super(CXXArgumentElement, self).__init__(clang_cursor)
        self.__arg_idx = arg_idx

    @property
    def name(self):
        """The name of the argument"""

        spelling = self._clang_cursor.spelling

        # use arg{i} name when the cursor spelling is empty
        # TODO: maybe we can move this logic to snippets
        if (self.is_variadic or not spelling) and self.__arg_idx is not None:
            return f'{spelling or "arg"}{self.__arg_idx + 1}'

        return spelling

    def __get_default(self, param_var):
        """Utility method to get default parameter kind and value"""

        # todo implementation is odd for now
        val = None
        kind = None
        if '=' in [p.spelling for p in param_var.get_tokens()]:
            for def_curs in param_var.walk_preorder():
                if def_curs.kind in (
                        cli.CursorKind.INTEGER_LITERAL,
                        cli.CursorKind.FLOATING_LITERAL,
                        cli.CursorKind.IMAGINARY_LITERAL,
                        cli.CursorKind.STRING_LITERAL,
                        cli.CursorKind.CHARACTER_LITERAL,
                        cli.CursorKind.CXX_BOOL_LITERAL_EXPR
                ):
                    kind = DefaultValueKind.LITERAL
                    val = next(def_curs.get_tokens(), None)
                    if val:
                        val = val.spelling
                elif def_curs.kind in (
                        cli.CursorKind.CXX_NULL_PTR_LITERAL_EXPR,
                        cli.CursorKind.GNU_NULL_EXPR,
                        cli.CursorKind.NULL_STMT):
                    val = 'nullptr'
                    kind = DefaultValueKind.NULL_PTR
                elif def_curs.kind == cli.CursorKind.DECL_REF_EXPR:
                    val = ''.join([token.spelling for token in def_curs.get_tokens()])
                    kind = DefaultValueKind.ENUM
                elif def_curs.kind == cli.CursorKind.CALL_EXPR:
                    kind = DefaultValueKind.CALL_EXPR
                    tokens = list(def_curs.get_tokens())
                    val = ''.join([token.spelling for token in tokens if token.spelling != '='])

                    if len(tokens) == 1:
                        if tokens[0].kind == cli.TokenKind.LITERAL:
                            # std::string case
                            kind = DefaultValueKind.LITERAL
                        elif val == 'nullptr':
                            # std::shared_ptr case
                            kind = DefaultValueKind.NULL_PTR
                    # value is retrieved break to not override it
                    break
        return kind, val

    @cached_property
    def __default_info(self):
        """Calculates default value information"""
        default_kind, default_value = self.__get_default(self._clang_cursor)
        return types.SimpleNamespace(kind=default_kind, value=default_value)

    @cached_property
    def default(self):
        """Default value of the default argument"""
        return self.__default_info.value

    @cached_property
    def default_is_literal(self):
        """Checks whether a default value is a literal"""
        return self.__default_info.kind == DefaultValueKind.LITERAL

    @cached_property
    def default_is_nullptr(self):
        """Checks whether a default value is nullptr"""
        return self.__default_info.kind == DefaultValueKind.NULL_PTR

    @cached_property
    def is_variadic(self):
        """Return whether the argument is template parameter pack or not."""
        return cutil.is_variadic(self._clang_cursor)


class CXXMemberElement(CXXElement):
    """Wrapper type on clang member/field cursor"""

    def __init__(self, clang_cursor, arg_idx=None):
        super(CXXMemberElement, self).__init__(clang_cursor)
