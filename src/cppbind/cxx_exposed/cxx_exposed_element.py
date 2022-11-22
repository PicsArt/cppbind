# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.


"""
Module to define which cxx properties must be exposed to jinja snippets.
"""
import itertools
import types
from copy import copy

from cached_property import cached_property

import cppbind.utils.clang as cutil
from cppbind.cxx_exposed.cxx_exposed_type import CXXExposedType
from cppbind.ir import ElementKind
from cppbind.ir.cxx_element import CXXArgumentElement


class CXXExposedElement:
    """Class to define exposed properties to snippets"""

    def __init__(self, cxx_element, template_choice=None):
        self._cxx_element = cxx_element
        self._template_choice = template_choice

        self.kind_name = cxx_element.kind_name
        self.name = cxx_element.name
        self.displayname = cxx_element.displayname
        self.source_file_name = cxx_element.source_file_name
        self.is_public = cxx_element.is_public
        self.is_private = cxx_element.is_private
        self.is_protected = cxx_element.is_protected
        self.raw_comment = cxx_element.raw_comment
        self.namespace = cxx_element.namespace
        self.is_abstract = cxx_element.is_abstract
        self.is_open = cxx_element.is_open

    def _get_full_displayname(self):
        return self._cxx_element.get_full_displayname()

    @cached_property
    def parent(self):
        return CXXExposedElement.__create_cxx_exposed_element(self._cxx_element.parent, self._template_choice)

    @staticmethod
    def __create_cxx_exposed_element(cxx_element, template_choice):
        """Static factory method to create a cxx exposed element based on the cxx element kind"""

        kind = cxx_element.kind
        if kind == ElementKind.ENUM_DECL:
            return CXXEnumExposedElement(cxx_element)
        if kind in (
                ElementKind.FUNCTION_DECL,
                ElementKind.FUNCTION_TEMPLATE,
                ElementKind.CXX_METHOD,
                ElementKind.CONSTRUCTOR
        ):
            return CXXFunctionExposedElement(cxx_element, template_choice)
        if kind in (
                ElementKind.CLASS_DECL,
                ElementKind.STRUCT_DECL,
                ElementKind.CLASS_TEMPLATE,
                ElementKind.CLASS_TEMPLATE_PARTIAL_SPECIALIZATION
        ):
            return CXXClassExposedElement(cxx_element, template_choice)
        if kind == ElementKind.PARM_DECL:
            return CXXArgumentExposedElement(cxx_element, template_choice)
        if kind == ElementKind.FIELD_DECL:
            return CXXMemberExposedElement(cxx_element, template_choice)

        return CXXExposedElement(cxx_element, template_choice)


class CXXEnumExposedElement(CXXExposedElement):
    """Class to define exposed enum properties to snippets"""

    def __init__(self, cxx_element):
        super(CXXEnumExposedElement, self).__init__(cxx_element)

        self.type_name = cxx_element.type_name
        self.enum_cases = cxx_element.enum_cases


class CXXClassExposedElement(CXXExposedElement):
    """Class to define exposed class/struct properties to snippets"""

    def __init__(self, cxx_element, template_choice=None):
        super(CXXClassExposedElement, self).__init__(cxx_element, template_choice)
        self.__is_templated = cxx_element.is_templated

        self.is_polymorphic = cxx_element.is_polymorphic
        self.has_multiple_base_branches = cxx_element.has_multiple_base_branches
        self.is_template = cxx_element.is_template
        self.template_parameters = cxx_element.template_parameters

    @cached_property
    def type_name(self):
        """The type name corresponding to the given cursor"""

        # in case of templates type.spelling is empty or partial defined (without template parameter specialization)
        # always using display name for unexposed types e.g T
        cxx_type_name = self._cxx_element.get_full_displayname()
        return cutil.replace_template_choice(cxx_type_name, self._template_choice)

    @cached_property
    def base_types(self):
        """
        Returns:
            List of base types exposed elements with template choice.
        """
        # specializing this in exposed type due to template_choice
        return [CXXExposedType(base, self._template_choice) for base in self._cxx_element.base_types]

    @cached_property
    def ancestors(self):
        """
        Returns:
            List of base types exposed elements with template choice.
        """
        # specializing this in exposed type due to template_choice
        return [CXXExposedType(ancestor.type, self._template_choice) for ancestor in
                self._cxx_element.ancestors]

    @cached_property
    def type(self):
        return CXXExposedType(self.type_name if self._cxx_element.is_templated else self._cxx_element.type,
                              template_choice=self._template_choice)


class CXXFunctionExposedElement(CXXExposedElement):
    """Class to define exposed function/method properties to snippets"""

    def __init__(self, cxx_element, template_choice):
        super(CXXFunctionExposedElement, self).__init__(cxx_element, template_choice)

        self.is_template = cxx_element.is_template
        self.is_static = cxx_element.is_static
        self.is_const = cxx_element.is_const
        self.is_overloaded = cxx_element.is_overloaded

    @cached_property
    def overridden_elements(self):
        return [CXXFunctionExposedElement(element, template_choice=self._template_choice)
                for element in self._cxx_element.overridden_elements]

    @cached_property
    def result_type(self):
        return CXXExposedType(self._cxx_element.result_type, template_choice=self._template_choice) \
            if self._cxx_element.result_type else None

    @cached_property
    def args(self):
        _args = []
        template_choice = copy(self._template_choice)
        for arg in self._cxx_element.args:
            # if the argument is a template parameter pack, e.g., Args... then we unpack it
            # and expose each as a separate argument
            # for example if the choice for Args is [int, float]
            # then we expose two arguments corresponding to int and float respectively
            if arg.is_variadic:
                for k in template_choice:
                    if not isinstance(template_choice[k], list):
                        template_choice[k] = [template_choice[k]]
                for i, choice_values in enumerate(list(itertools.product(*template_choice.values()))):
                    # copy the argument and set index to overwrite the name
                    # e.g. first argument - args1, second - args2 and so on
                    arg_copy = CXXArgumentElement(arg._clang_cursor, i)
                    _args.append(CXXArgumentExposedElement(arg_copy,
                                                           template_choice=dict(
                                                               zip(template_choice.keys(), choice_values))))
            else:
                _args.append(CXXArgumentExposedElement(arg, template_choice=self._template_choice))
        return _args

    @cached_property
    def template_arguments(self):
        """Return list of namespaces containing template argument type and kind information."""
        _args = []
        if self.is_template:
            for param in self._cxx_element.template_parameters:
                value = self._template_choice[param.spelling]
                if isinstance(value, list):
                    for item in value:
                        _args.append(types.SimpleNamespace(
                            value=CXXExposedType(item,
                                                 self._template_choice) if param.kind == ElementKind.TEMPLATE_TYPE_PARAMETER else item,
                            kind=param.kind
                        ))
                else:
                    val = CXXExposedType(value,
                                         self._template_choice) if param.kind == ElementKind.TEMPLATE_TYPE_PARAMETER else value
                    _args.append(types.SimpleNamespace(value=val,
                                                       kind=param.kind))
        return _args


class CXXArgumentExposedElement(CXXExposedElement):
    """Class to define exposed argument properties to snippets"""

    def __init__(self, cxx_element, template_choice=None):
        super(CXXArgumentExposedElement, self).__init__(cxx_element, template_choice)

        self.default = cxx_element.default
        self.default_is_literal = cxx_element.default_is_literal
        self.default_is_nullptr = cxx_element.default_is_nullptr

    @cached_property
    def type(self):
        return CXXExposedType(self._cxx_element.type, template_choice=self._template_choice)


class CXXMemberExposedElement(CXXExposedElement):
    """Class to define exposed member properties to snippets"""

    def __init__(self, cxx_element, template_choice=None):
        super(CXXMemberExposedElement, self).__init__(cxx_element, template_choice)

    @cached_property
    def result_type(self):
        return CXXExposedType(self._cxx_element.type, self._template_choice)
