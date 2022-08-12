# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.


"""
Module to define which cxx properties must be exposed to jinja snippets.
"""


import cppbind.utils.clang as cutil


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

    @property
    def type_name(self):
        """The type name corresponding to the given element"""

        # in case of templates type.spelling is empty or partial defined (without template parameter specialization)
        if self.__is_templated and self.__template_choice:
            cxx_type_name = self._cxx_element.get_full_displayname()
            return cutil.replace_template_choice(cxx_type_name, self.__template_choice)

        return self._cxx_element.get_type().spelling


class CXXFunctionExposedElement(CXXExposedElement):
    """Class to define exposed function/method properties to snippets"""

    def __init__(self, cxx_element):
        super(CXXFunctionExposedElement, self).__init__(cxx_element)

        self.is_template = cxx_element.is_template
        self.is_static = cxx_element.is_static
        self.is_const = cxx_element.is_const
        self.is_overloaded = cxx_element.is_overloaded


class CXXArgumentExposedElement(CXXExposedElement):
    """Class to define exposed argument properties to snippets"""

    def __init__(self, cxx_element):
        super(CXXArgumentExposedElement, self).__init__(cxx_element)

        self.type = cxx_element.get_type()
        self.default = cxx_element.default
        self.default_is_literal = cxx_element.default_is_literal
        self.default_is_nullptr = cxx_element.default_is_nullptr
