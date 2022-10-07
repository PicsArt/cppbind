# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.


"""
Module to define which cxx properties must be exposed to jinja snippets.
"""

from cached_property import cached_property

import cppbind.utils.clang as cutil
from cppbind.cxx_exposed.cxx_exposed_type import CXXExposedType


class CXXExposedElement:
    """Class to define exposed properties to snippets"""

    def __init__(self, cxx_element):
        self._cxx_element = cxx_element

        self.kind_name = cxx_element.kind_name
        self.name = cxx_element.name
        self.displayname = cxx_element.displayname
        self.source_file_name = cxx_element.source_file_name
        self.is_public = cxx_element.is_public
        self.is_private = cxx_element.is_private
        self.is_protected = cxx_element.is_protected
        self.namespace = cxx_element.namespace
        self.is_abstract = cxx_element.is_abstract
        self.is_open = cxx_element.is_open

    def _get_full_displayname(self):
        return self._cxx_element.get_full_displayname()


class CXXEnumExposedElement(CXXExposedElement):
    """Class to define exposed enum properties to snippets"""

    def __init__(self, cxx_element):
        super(CXXEnumExposedElement, self).__init__(cxx_element)

        self.type_name = cxx_element.type_name
        self.enum_cases = cxx_element.enum_cases


class CXXClassExposedElement(CXXExposedElement):
    """Class to define exposed class/struct properties to snippets"""

    def __init__(self, cxx_element, template_choice=None):
        super(CXXClassExposedElement, self).__init__(cxx_element)
        self.__template_choice = template_choice
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
        return cutil.replace_template_choice(cxx_type_name, self.__template_choice)

    @cached_property
    def base_types(self):
        """
        Returns:
            List of base types exposed elements with template choice.
        """
        # specializing this in exposed type due to template_choice
        return [CXXExposedType(element.type, self.__template_choice) for element in
                self._cxx_element.base_type_elements]

    @cached_property
    def ancestors(self):
        """
        Returns:
            List of base types exposed elements with template choice.
        """
        # specializing this in exposed type due to template_choice
        return [CXXExposedType(ancestor.type, self.__template_choice) for ancestor in
                self._cxx_element.ancestors]

    @cached_property
    def type(self):
        return CXXExposedType(self.type_name if self._cxx_element.is_templated else self._cxx_element.type,
                              template_choice=self.__template_choice)


class CXXFunctionExposedElement(CXXExposedElement):
    """Class to define exposed function/method properties to snippets"""

    def __init__(self, cxx_element, template_choice):
        super(CXXFunctionExposedElement, self).__init__(cxx_element)
        self.__template_choice = template_choice

        self.is_template = cxx_element.is_template
        self.is_static = cxx_element.is_static
        self.is_const = cxx_element.is_const
        self.is_overloaded = cxx_element.is_overloaded
        self.template_parameters = cxx_element.template_parameters

    @cached_property
    def overridden_elements(self):
        return [CXXFunctionExposedElement(element, template_choice=self.__template_choice)
                for element in self._cxx_element.overridden_elements]

    @cached_property
    def parent(self):
        return CXXClassExposedElement(self._cxx_element.parent, self.__template_choice)

    @cached_property
    def result_type(self):
        return CXXExposedType(self._cxx_element.result_type, template_choice=self.__template_choice) \
            if self._cxx_element.result_type else None

    @cached_property
    def args(self):
        return [CXXArgumentExposedElement(arg, template_choice=self.__template_choice)
                for arg in self._cxx_element.args]


class CXXArgumentExposedElement(CXXExposedElement):
    """Class to define exposed argument properties to snippets"""

    def __init__(self, cxx_element, template_choice=None):
        super(CXXArgumentExposedElement, self).__init__(cxx_element)
        self.__template_choice = template_choice

        self.default = cxx_element.default
        self.default_is_literal = cxx_element.default_is_literal
        self.default_is_nullptr = cxx_element.default_is_nullptr

    @cached_property
    def type(self):
        return CXXExposedType(self._cxx_element.type, template_choice=self.__template_choice)

    @cached_property
    def is_variadic(self):
        return self._cxx_element.type.type_name.endswith('...')


class CXXMemberExposedElement(CXXExposedElement):
    """Class to define exposed member properties to snippets"""

    def __init__(self, cxx_element, template_choice=None):
        super(CXXMemberExposedElement, self).__init__(cxx_element)
        self.__template_choice = template_choice

    @cached_property
    def result_type(self):
        return CXXExposedType(self._cxx_element.type, template_choice=self.__template_choice)
