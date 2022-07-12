"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 07/06/2022-10:46.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.templates.template_methods as pybind_template_methods_pygen
import examples_lib.simple.project_pygen as simple_project_pygen
import examples_lib.simple.root_pygen as simple_root_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class TemplateMethods(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/templates/template_methods.hpp#L16
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L16>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L23
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L23>`_
        """
        pass
    
    @bind
    def max(self, a: int, b: int) -> int:
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L34
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L34>`_
        """
        pass

    @bind
    def max(self, a: str, b: str) -> str:
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L34
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L34>`_
        """
        pass

    @bind
    def make_pair(self, a: simple_project_pygen.Project, b: simple_project_pygen.Project) -> Tuple[simple_project_pygen.Project, simple_project_pygen.Project]:
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L51
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L51>`_
        """
        pass

    @bind
    def make_pair(self, a: simple_root_pygen.Root, b: simple_project_pygen.Project) -> Tuple[simple_root_pygen.Root, simple_project_pygen.Project]:
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L51
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L51>`_
        """
        pass

    @classmethod
    @bind
    def merge(cls, first: List[int], second: List[int]) -> List[int]:
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L65
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L65>`_
        """
        pass

    @classmethod
    @bind
    def merge(cls, first: List[str], second: List[str]) -> List[str]:
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L65
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L65>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
