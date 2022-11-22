# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.


"""Module to define cxx type wrapper class"""

import clang.cindex as cli
import cppbind.utils.clang as cutil


class CXXType:
    """Wrapper type on clang type"""

    def __init__(self, clang_type):
        self.__clang_type = clang_type

    @property
    def type_name(self):
        """The spelling of clang type"""
        return self.__clang_type.spelling

    @property
    def is_function_proto(self):
        """Checks if the type is a function prototype"""
        return self.__clang_type.kind == cli.TypeKind.FUNCTIONPROTO

    @property
    def is_typedef(self):
        """Checks if the type is a typedef to another type"""
        return self.__clang_type.kind == cli.TypeKind.TYPEDEF or \
               self.__clang_type.get_declaration().kind in (cli.CursorKind.TYPE_ALIAS_DECL,
                                                            cli.CursorKind.TYPEDEF_DECL)

    @property
    def is_lval_reference(self):
        """Checks if the type is lvalue reference"""
        return self.__clang_type.kind == cli.TypeKind.LVALUEREFERENCE

    @property
    def is_rval_reference(self):
        """Checks if the type is rvalue reference"""
        return self.__clang_type.kind == cli.TypeKind.RVALUEREFERENCE

    @property
    def is_pointer(self):
        """Checks if the type is a pointer"""
        return self.__clang_type.kind == cli.TypeKind.POINTER

    @property
    def pointee_type(self):
        """Returns the pointee type of the type"""
        return CXXType(self.__clang_type.get_pointee())

    @property
    def canonical_type(self):
        """Returns canonical type of the type"""
        return CXXType(self.__clang_type.get_canonical())

    @property
    def argument_types(self):
        """Returns the list of argument types of function type"""
        return [CXXType(arg_type) for arg_type in self.__clang_type.argument_types()]

    def get_template_declaration(self):
        """Returns the declaration cursor for the clang Type"""
        return cutil.get_template_declaration(self.__clang_type)

    def get_declaration(self):
        """Returns the declaration cursor for the clang Type."""
        return cutil.get_declaration(self.__clang_type)

    def get_result(self):
        """Returns the result type associated with a function type"""
        return CXXType(self.__clang_type.get_result())

    def get_template_argument_type(self, num):
        """Returns the CXXType for the indicated template argument"""
        return CXXType(self.__clang_type.get_template_argument_type(num))

    @property
    def is_enum(self):
        """Checks the type is enum"""
        return self.__clang_type.get_canonical().kind == cli.TypeKind.ENUM

    @property
    def is_bool(self):
        """Checks the type is boolean"""
        return self.__clang_type.get_canonical().kind == cli.TypeKind.BOOL

    @property
    def is_long(self):
        """Checks the type is long"""
        return self.__clang_type.get_canonical().kind == cli.TypeKind.LONG

    @property
    def is_float(self):
        """Checks the type is float"""
        return self.__clang_type.get_canonical().kind in (cli.TypeKind.FLOAT, cli.TypeKind.FLOAT128)

    @property
    def is_char(self):
        """Checks the type is char"""
        return self.__clang_type.get_canonical().kind in (cli.TypeKind.CHAR_S, cli.TypeKind.CHAR_S)

    @property
    def is_uchar(self):
        """Checks the type is unsigned char"""
        return self.__clang_type.get_canonical().kind == cli.TypeKind.UCHAR

    @property
    def base_types(self):
        """Returns a list of base types."""
        _base_types = []
        decl_cursor = self.get_declaration()
        if decl_cursor:
            for base_specifier in decl_cursor.get_children():
                if base_specifier.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
                    _base_types.append(CXXType(base_specifier.type))

        return _base_types

    @property
    def is_variadic(self):
        """Returns whether the type is a variadic template or an instance of a variadic template."""
        if cutil.is_templated(self.__clang_type):
            declaration = self.get_declaration()
            if declaration:
                return any(cutil.is_variadic(cursor) for cursor in
                           cutil.get_template_parameter_cursors(self.get_declaration()))
        return False

    def __getattr__(self, prop):
        """Delegate all missing methods/properties to the underlying clang Type object"""

        if not hasattr(self.__clang_type, prop):
            raise AttributeError(f"{self.__class__.__name__}.{prop} is invalid")

        return getattr(self.__clang_type, prop)
