# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.
from cached_property import cached_property

import clang.cindex as cli
import cppbind.utils.clang as cutil


class CXXType:
    """
    Type which holds a clang type or a string type with its cursor and template choice if it's a template type,
    and gives some utility functionality based on it.
    """

    def __init__(self, type_, template_choice=None, cursor=None):
        # clang Type object or the string representation of the type
        self.type_ = type_
        self.template_choice = template_choice
        # if the type is invalid for templates but the cursor is available use it to retrieve information
        self.cursor = cursor

    def __eq__(self, other):
        return self.type_name == other.type_name

    def __hash__(self):
        # TODO: note this might be required to be changed in #239
        return hash(self.type_name)

    @property
    def type_name(self):
        return cutil.replace_template_choice(self.type_ if isinstance(self.type_, str) else self.type_.spelling,
                                             self.template_choice)

    @property
    def pointee_type(self):
        if isinstance(self.type_, cli.Type):
            return CXXType(self.type_.get_pointee(),
                           self.template_choice) if self.type_.get_pointee().spelling else self
        # type_ is a string
        _type = self.type_.strip()
        if _type.endswith('&&'):
            return CXXType(_type[:-2].strip(), self.template_choice)
        if _type.endswith('*') or _type.endswith('&'):
            return CXXType(_type[:-1].strip(), self.template_choice)
        return self

    @property
    def canonical_type(self):
        if isinstance(self.type_, cli.Type):
            return CXXType(self.type_.get_canonical(),
                           self.template_choice) if self.type_.get_canonical().spelling else self
        else:
            # we do not have a mechanism for string types yet
            return self

    @property
    def is_template(self):
        """
        Returns whether the type is a template or not. Only most nested type is considered.
        For example for cppbind::example::List<int>::Item it'll return False as Item itself is not a template.
        This property is used for internal purposes like for building type converters.
        """
        # we have to use type_name for clang types as well as it can be an unexposed type and it's choice can be a
        # template for example if it's spelling is T and the choice of T is std::vector<int> then T is a template
        if isinstance(self.type_, cli.Type) and self.type_.kind != cli.TypeKind.UNEXPOSED:
            return self.type_.get_num_template_arguments() != -1
        else:
            return self.type_name.endswith('>')

    @property
    def is_function_proto(self):
        if isinstance(self.type_, cli.Type):
            return self.type_.kind == cli.TypeKind.FUNCTIONPROTO
        # we don't have a mechanism for string types yet
        return False

    @property
    def is_typedef(self):
        if isinstance(self.type_, cli.Type):
            return self.type_.kind == cli.TypeKind.TYPEDEF or \
                   self.type_.get_declaration().kind in (cli.CursorKind.TYPE_ALIAS_DECL, cli.CursorKind.TYPEDEF_DECL)
        # we don't have  a mechanism for string types yet
        return False

    @cached_property
    def template_arguments(self):
        """
        Returns a list of tuples containing the argument and its kind, e.g. for std::array<double, 3> returns
        [(CXXType('double'), CursorKind.TEMPLATE_TYPE_PARAMETER), (3, CursorKind.TEMPLATE_NON_TYPE_PARAMETER)].
        Currently, type and integral parameters are supported.
        """
        if self.cursor is None and (isinstance(self.type_, str) or self.type_.kind == cli.TypeKind.UNEXPOSED):
            # neither cursor nor type is available, thus using string parsing to retrieve template arguments
            return self.__arguments_from_type_name()

        # either cursor or type is available, thus we can use them to retrieve information about template parameters
        cursor = self.cursor or cutil.get_template_declaration(self.type_)
        cursors = cutil.get_template_parameter_cursors(cursor)

        if isinstance(self.type_, cli.Type) and self.type_.kind != cli.TypeKind.UNEXPOSED:
            # clang Type is available, and it's not unexposed, we can take template arguments from it
            arguments = [self.type_.get_template_argument_type(num) for num in
                         range(self.type_.get_num_template_arguments())]
        else:
            # clang Type is not available, but we have a cursor
            # which can be used to retrieve information about template parameters
            arguments = [cursor.spelling for cursor in cursors]

        # argument spellings are used for non type template parameters, as for them clang gives an invalid Type
        # using canonical as the argument might be an expression that should be evaluated
        argument_spellings = cutil.get_template_arguments_from_str(
            self.type_name if self.is_unexposed else self.canonical_type.type_name)
        args = []
        for ii, argument in enumerate(arguments):
            cursor = cursors[ii]
            # for now using clangs CursorKind for identifying type and non-type parameters
            # later we might have our own template parameter kind and expose it to snippets
            if cursor.kind == cli.CursorKind.TEMPLATE_TYPE_PARAMETER:
                args.append((CXXType(argument, self.template_choice), cli.CursorKind.TEMPLATE_TYPE_PARAMETER))
            elif cursor.kind == cli.CursorKind.TEMPLATE_NON_TYPE_PARAMETER:
                if isinstance(argument, cli.Type) and argument.kind == cli.TypeKind.INVALID:
                    # if the non-type argument is a clang Type then it's invalid so use its spelling
                    # retrieved from string parsing
                    argument = argument_spellings[ii]
                if cutil.is_integral_type(cursor.type.get_canonical()):
                    args.append((int(cutil.replace_template_choice(argument, self.template_choice)),
                                 cli.CursorKind.TEMPLATE_NON_TYPE_PARAMETER))
                else:
                    # non-integral non type parameter, currently not supported
                    args.append(None)
            else:
                # template template parameter, currently not supported
                args.append(None)

        return args

    def __arguments_from_type_name(self):
        args = []
        for arg_spelling in cutil.get_template_arguments_from_str(self.type_name):
            parameter = cutil.replace_template_choice(arg_spelling, self.template_choice)
            if parameter.lstrip('+-').isnumeric():
                args.append((int(parameter),
                             cli.CursorKind.TEMPLATE_NON_TYPE_PARAMETER))
            else:
                # NOTE: currently only from the string we cannot identify whether the argument is a type or not
                # maybe we can check by trying to build its converter?
                args.append((CXXType(arg_spelling, self.template_choice),
                             cli.CursorKind.TEMPLATE_TYPE_PARAMETER))
        return args

    @property
    def template_type_name(self):
        return cutil.template_type_name(self.type_name)

    @property
    def is_lval_reference(self):
        return self.type_.kind == cli.TypeKind.LVALUEREFERENCE if isinstance(self.type_, cli.Type) else \
            not self.type_.strip().endswith('&&') and self.type_.strip().endswith('&')

    @property
    def is_rval_reference(self):
        return self.type_.kind == cli.TypeKind.RVALUEREFERENCE if isinstance(self.type_, cli.Type) else \
            self.type_.strip().endswith('&&')

    @property
    def is_pointer(self):
        return self.type_.kind == cli.TypeKind.POINTER if isinstance(self.type_,
                                                                     cli.Type) else self.type_.strip().endswith('*')

    @property
    def is_value(self):
        return not self.canonical_type.is_pointer and not self.canonical_type.is_lval_reference

    @property
    def unqualified_type_name(self):
        return cutil.get_unqualified_type_name(self.type_name)

    @property
    def unqualified_resolved_type_name(self):
        """Returns unqualified type name if the type is not typedef on pointer, otherwise returns canonical name"""
        return self.raw_type.unqualified_type_name if \
            (isinstance(self.type_, cli.Type) and self.is_typedef and (
                    self.canonical_type.is_pointer or self.canonical_type.is_lval_reference)) \
            else cutil.get_unqualified_type_name(self.pointee_name)

    @property
    def is_const_qualified(self):
        # when self.type_ is string then only prefixed const qualified types are supported
        # for example `int const &` is not supported
        # in case of clang's Type all cases are supported
        return self.type_name.startswith('const')

    @property
    def pointee_name(self):
        return cutil.replace_template_choice(
            self.pointee_type.type_.spelling if isinstance(self.type_, cli.Type) else self.pointee_type.type_,
            self.template_choice)

    @property
    def raw_type(self):
        t = self
        if self.is_typedef or not self.is_unexposed:
            t = self.canonical_type
        if t.is_pointer or t.is_lval_reference:
            t = t.pointee_type
        return t

    @property
    def is_unexposed(self):
        """
        Recursively checks if the type has an unexposed template argument.
        E.g. std::vector<std::shared_ptr<T>> is unexposed.
        Returns:
            bool: True if the has an unexposed template argument and False otherwise.
        """
        if isinstance(self.type_, str):
            return self.type_ != cutil.replace_template_choice(self.type_, self.template_choice)
        clang_type = self.canonical_type.type_
        if clang_type.kind == cli.TypeKind.UNEXPOSED:
            return True
        if clang_type.kind in (cli.TypeKind.POINTER, cli.TypeKind.LVALUEREFERENCE):
            return self.pointee_type.is_unexposed
        if self.is_template:
            for num in range(self.type_.get_num_template_arguments()):
                tp = self.type_.get_template_argument_type(num)
                if tp.kind == cli.TypeKind.UNEXPOSED:
                    return True
        return False
