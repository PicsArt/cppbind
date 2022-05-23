# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

import clang.cindex as cli
import cppbind.utils.clang as cutil


class CXXType:
    """
    Type which holds a clang type or a string type with it's template choice if it's a template type,
    and gives some utility functionality based on it.
    """

    def __init__(self, type_, template_choice=None):
        self.type_ = type_
        self.template_choice = template_choice

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
            return CXXType(_type[:-2], self.template_choice)
        if _type.endswith('*') or _type.endswith('&'):
            return CXXType(_type[:-1], self.template_choice)
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
            return self.type_.kind == cli.TypeKind.TYPEDEF
        # we don't have  a mechanism for string types yet
        return False

    @property
    def template_argument_types(self):
        # if type is unexposed it's choice can be a template thus we need to use string parsing in that case
        if isinstance(self.type_, cli.Type) and self.type_.kind != cli.TypeKind.UNEXPOSED:
            return [CXXType(self.type_.get_template_argument_type(num), self.template_choice)
                    for num in range(self.type_.get_num_template_arguments())]
        return self._get_template_arguments()

    def _get_template_arguments(self):
        """
        Retrieves template arguments spelling from a type's spelling.
        E.g. for 'std::pair<std::string, std::vector<int>>' will return ['std::string', 'std::vector<int>']
        Note: there are cases this does not handle for example if the expression contains offset operator
        """
        type_spelling = self.type_name

        # only most nested type's arguments should be retrieved e.g for for a::b::<c::C>::G<d::D, e::E> -- d::D, e::E
        template_args = []
        parentheses_count = 0
        length = len(type_spelling)
        arg_end_idx = length - 1
        for i, symbol in enumerate(reversed(type_spelling)):
            # template should end with >
            if symbol == '>':
                parentheses_count += 1
            elif symbol == '<':
                parentheses_count -= 1
            elif symbol == ',' and parentheses_count == 1:
                template_args.append(CXXType(type_spelling[length - i + 1:arg_end_idx].strip(),
                                             self.template_choice))
                arg_end_idx = length - i - 1
            if parentheses_count == 0:
                # if i=0 then self is not a template
                if i != 0:
                    template_args.append(CXXType(type_spelling[length - i:arg_end_idx],
                                                 self.template_choice))
                break
        return list(reversed(template_args))

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
            (isinstance(self.type_, cli.Type) and self.is_typedef and (self.canonical_type.is_pointer or self.canonical_type.is_lval_reference) ) \
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
            for arg_type in self.template_argument_types:
                if arg_type.is_unexposed:
                    return True
        return False
