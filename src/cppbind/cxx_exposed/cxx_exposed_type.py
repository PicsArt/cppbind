# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

from types import SimpleNamespace

from cached_property import cached_property

import cppbind.utils.clang as cutil
from cppbind.ir import ElementKind, TypeKind
from cppbind.ir.cxx_type import CXXType


class CXXExposedType:
    """
    Type which holds a CXXType or a string type with its cursor and template choice if it's a template type,
    and gives some utility functionality based on it.
    """

    def __init__(self, cxx_type, template_choice=None, cxx_element=None):
        # CXXType object or the string representation of the type
        self._cxx_type = cxx_type
        self._template_choice = template_choice
        # if the type is invalid for templates but the cursor is available use it to retrieve information
        self._cxx_element = cxx_element

        # TODO: replace False with the logic for strings when it's possible
        self.is_enum = cxx_type.is_enum if isinstance(cxx_type, CXXType) else False
        self.is_bool = cxx_type.is_bool if isinstance(cxx_type, CXXType) else False
        self.is_long = cxx_type.is_long if isinstance(cxx_type, CXXType) else False
        self.is_float = cxx_type.is_float if isinstance(cxx_type, CXXType) else False
        self.is_char = cxx_type.is_char if isinstance(cxx_type, CXXType) else False
        self.is_uchar = cxx_type.is_uchar if isinstance(cxx_type, CXXType) else False

    def __eq__(self, other):
        return self.type_name == other.type_name

    def __hash__(self):
        # TODO: note this might be required to be changed in #239
        return hash(self.type_name)

    @property
    def type_name(self):
        return cutil.replace_template_choice(
            self._cxx_type if isinstance(self._cxx_type, str) else self._cxx_type.type_name,
            self._template_choice).rstrip('.')

    @property
    def pointee_type(self):
        if isinstance(self._cxx_type, CXXType):
            pointee_type = self._cxx_type.pointee_type
            return CXXExposedType(pointee_type,
                                  self._template_choice) if pointee_type.spelling else self
        # type_ is a string
        _type = self._cxx_type.strip()
        if _type.endswith('&&'):
            return CXXExposedType(_type[:-2].strip(), self._template_choice)
        if _type.endswith('*') or _type.endswith('&'):
            return CXXExposedType(_type[:-1].strip(), self._template_choice)
        return self

    @property
    def canonical_type(self):
        if isinstance(self._cxx_type, CXXType):
            canonical_type = self._cxx_type.canonical_type
            return CXXExposedType(canonical_type,
                                  self._template_choice) if canonical_type.spelling else self
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
        if isinstance(self._cxx_type, CXXType) and self._cxx_type.kind != TypeKind.UNEXPOSED:
            return self._cxx_type.get_num_template_arguments() != -1
        else:
            return self.type_name.endswith('>')

    @property
    def is_function_proto(self):
        if isinstance(self._cxx_type, CXXType):
            return self._cxx_type.is_function_proto
        # we don't have a mechanism for string types yet
        return False

    @property
    def is_typedef(self):
        if isinstance(self._cxx_type, CXXType):
            return self._cxx_type.is_typedef
        # we don't have  a mechanism for string types yet
        return False

    @cached_property
    def __template_parameter_cursors(self):
        if self._cxx_element:
            return self._cxx_element.get_template_parameter_cursors()
        else:
            cursor = self._cxx_type.get_template_declaration()
            return cutil.get_template_parameter_cursors(cursor)

    @cached_property
    def is_variadic(self):
        """Returns whether the type is a variadic template or an instance of a variadic template."""
        if isinstance(self._cxx_type, str):
            # in case of strings we cannot identify whether it's variadic or not
            return False
        elif isinstance(self._cxx_type, CXXType):
            return self._cxx_type.is_variadic
        else:
            return any(cutil.is_variadic(cursor) for cursor in self.__template_parameter_cursors)

    @cached_property
    def template_arguments(self):
        """
        Returns a list of namespaces containing the argument and its kind, e.g. for std::array<double, 3> returns
        [SimpleNamespace(type=CXXExposedType('double'), kind=CursorKind.TEMPLATE_TYPE_PARAMETER),
         SimpleNamespace(type=3, kind=CursorKind.TEMPLATE_NON_TYPE_PARAMETER)].
        Currently, type and integral parameters are supported.
        """

        if not self.is_template:
            return []

        if self._cxx_element is None and (isinstance(self._cxx_type, str) or self._cxx_type.kind == TypeKind.UNEXPOSED):
            # neither cursor nor type is available, thus using string parsing to retrieve template arguments
            return self.__arguments_from_type_name()

        # either cursor or type is available, thus we can use them to retrieve information about template parameters
        cursors = self.__template_parameter_cursors

        if self.is_variadic:
            # for variadic use string parse
            # NOTE: later when adding support for other template parameter
            # kinds like enums, floating point parameters, etc., it might be reasonable to not use string parsing
            return self.__arguments_from_type_name()

        if isinstance(self._cxx_type, CXXType) and self._cxx_type.kind != TypeKind.UNEXPOSED:
            # clang Type is available, and it's not unexposed, we can take template arguments from it
            arguments = [self._cxx_type.get_template_argument_type(num) for num in
                         range(self._cxx_type.get_num_template_arguments())]
        else:
            # clang Type is not available, but we have a cursor
            # which can be used to retrieve information about template parameters
            arguments = [cursor.spelling for cursor in cursors]

        # argument spellings are used for non type template parameters, as for them clang gives an invalid Type
        # using canonical as the argument might be an expression that should be evaluated
        argument_spellings = cutil.get_template_arguments_from_str(
            self.type_name if self._is_unexposed else self.canonical_type.type_name)
        args = []
        for ii, argument in enumerate(arguments):
            cursor = cursors[ii]
            # for now using clangs CursorKind for identifying type and non-type parameters
            # later we might have our own template parameter kind and expose it to snippets
            if cursor.kind == ElementKind.TEMPLATE_TYPE_PARAMETER:
                args.append(SimpleNamespace(type=CXXExposedType(argument, self._template_choice),
                                            kind=ElementKind.TEMPLATE_TYPE_PARAMETER))
            elif cursor.kind == ElementKind.TEMPLATE_NON_TYPE_PARAMETER:
                if isinstance(argument, CXXType) and argument.kind == TypeKind.INVALID:
                    # if the non-type argument is a clang Type then it's invalid so use its spelling
                    # retrieved from string parsing
                    argument = argument_spellings[ii]
                if cutil.is_integral_type(cursor.type.get_canonical()):
                    args.append(
                        SimpleNamespace(type=int(cutil.replace_template_choice(argument, self._template_choice)),
                                        kind=ElementKind.TEMPLATE_NON_TYPE_PARAMETER))
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
            parameter = cutil.replace_template_choice(arg_spelling, self._template_choice)
            if parameter.lstrip('+-').isnumeric():
                args.append(SimpleNamespace(type=int(parameter),
                                            kind=ElementKind.TEMPLATE_NON_TYPE_PARAMETER))
            else:
                # NOTE: currently only from the string we cannot identify whether the argument is a type or not
                # maybe we can check by trying to build its converter?
                args.append(SimpleNamespace(type=CXXExposedType(arg_spelling, self._template_choice),
                                            kind=ElementKind.TEMPLATE_TYPE_PARAMETER))
        return args

    @property
    def _template_type_name(self):
        return cutil.template_type_name(self.type_name)

    @property
    def is_lval_reference(self):
        return self._cxx_type.is_lval_reference if isinstance(self._cxx_type, CXXType) else \
            not self._cxx_type.strip().endswith('&&') and self._cxx_type.strip().endswith('&')

    @property
    def is_rval_reference(self):
        return self._cxx_type.is_rval_reference if isinstance(self._cxx_type, CXXType) else \
            self._cxx_type.strip().endswith('&&')

    @property
    def is_pointer(self):
        return self._cxx_type.is_pointer if isinstance(self._cxx_type, CXXType) else self._cxx_type.strip().endswith(
            '*')

    @property
    def is_value_type(self):
        return not self.canonical_type.is_pointer and not self.canonical_type.is_lval_reference

    @property
    def unqualified_type_name(self):
        return cutil.get_unqualified_type_name(self.type_name).rstrip('.')

    @property
    def resolved_type(self):
        """Returns pointee type if the type is not typedef on pointer, otherwise returns canonical type"""
        return self.canonical_pointee_type if (isinstance(self._cxx_type, CXXType) and self.is_typedef and (
                self.canonical_type.is_pointer or self.canonical_type.is_lval_reference)) else self.pointee_type

    @property
    def is_const_qualified(self):
        # when self._cxx_type is string then only prefixed const qualified types are supported
        # for example `int const &` is not supported
        # in case of clang's Type all cases are supported
        return self.type_name.startswith('const')

    @property
    def base_types(self):
        """
        Returns a list of base exposed types.
        """
        # redefining to add a template choice
        return [] if isinstance(self._cxx_type, str) else [CXXExposedType(base_type, self._template_choice) for
                                                           base_type in self._cxx_type.base_types]

    @property
    def __pointee_name(self):
        return cutil.replace_template_choice(
            self.pointee_type._cxx_type.spelling if isinstance(self._cxx_type,
                                                               CXXType) else self.pointee_type._cxx_type,
            self._template_choice)

    @property
    def canonical_pointee_type(self):
        t = self
        if self.is_typedef or not self._is_unexposed:
            t = self.canonical_type
        if t.is_pointer or t.is_lval_reference:
            t = t.pointee_type
        return t

    @property
    def _is_unexposed(self):
        """
        Recursively checks if the type has an unexposed template argument.
        E.g. std::vector<std::shared_ptr<T>> is unexposed.
        Returns:
            bool: True if the has an unexposed template argument and False otherwise.
        """
        if isinstance(self._cxx_type, str):
            return self._cxx_type != cutil.replace_template_choice(self._cxx_type, self._template_choice)
        clang_type = self.canonical_type._cxx_type
        if clang_type.kind == TypeKind.UNEXPOSED:
            return True
        if clang_type.kind in (TypeKind.POINTER, TypeKind.LVALUEREFERENCE):
            return self.pointee_type._is_unexposed
        if self.is_template:
            for num in range(self._cxx_type.get_num_template_arguments()):
                tp = self._cxx_type.get_template_argument_type(num)
                if tp.kind == TypeKind.UNEXPOSED:
                    return True
        return False


class CXXRunnerExposedType(CXXExposedType):
    """Subclass of CXXExposedType which defines some additional context dependent properties"""

    def __init__(self, cxx_type, template_choice=None, cxx_element=None, ir=None, ctx=None):
        super(CXXRunnerExposedType, self).__init__(cxx_type, template_choice, cxx_element)
        self.__ir = ir
        self.__ctx = ctx

    @cached_property
    def __node(self):
        """Private helper property to find node from IR or context"""

        # first lookup in IR (we may lookup only in IR, when we explode template nodes in IR)
        if self.__ir:
            node = self.__ir.find_node_by_type(self._cxx_type)
            if node:
                return node

        # use context if IR lookup failed
        if self.__ctx:
            return self.__ctx.node

        return None

    @property
    def namespace(self):
        """The namespace of the type"""
        return self.__node.cxx_element.namespace if self.__node else None

    @property
    def is_polymorphic(self):
        """Checks whether the type is polymorphic"""
        return self.__node.cxx_element.is_polymorphic if self.__node else None

    @property
    def parent_type(self):
        """Lexical parent type of the current type"""

        if not self.__node:
            return None

        parent_element = self.__node.cxx_element.parent
        if not parent_element:
            return None

        parent_cxx_type = parent_element.type if not parent_element.is_templated else cutil.replace_template_choice(
            parent_element.get_full_displayname(), self._template_choice or self.__ctx.template_choice)

        return CXXExposedType(parent_cxx_type, self._template_choice)
