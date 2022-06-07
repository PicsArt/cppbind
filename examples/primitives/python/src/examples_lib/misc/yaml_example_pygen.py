"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 06/03/2022-07:13.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.misc.yaml_example as pybind_yaml_example_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class WithExternalAPIComments(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/misc/yaml_example.hpp#L8
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L8>`_
    """
    
    @bind
    def __init__(self, s: str):
        """
        Documentation generated from: `cxx/misc/yaml_example.hpp#L11
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L11>`_
        """
        pass
    
    @property
    @bind
    def str(self) -> str:
        """
        Documentation generated from: `cxx/misc/yaml_example.hpp#L21
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L21>`_
        """
        pass

    @str.setter
    @bind
    def str(self, value: str):
        """
        Documentation generated from: `cxx/misc/yaml_example.hpp#L21
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L21>`_
        """
        pass
    
    @classmethod
    @bind
    def ret_int(cls, n: int) -> int:
        """
        retInt function
        returns integer passed by argument
        Documentation generated from: `cxx/misc/yaml_example.hpp#L17
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L17>`_
        """
        pass

    @classmethod
    @bind
    def max(cls, a: int, b: int) -> int:
        """
        Documentation generated from: `cxx/misc/yaml_example.hpp#L29
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L29>`_
        """
        pass

    @classmethod
    @bind
    def max(cls, a: str, b: str) -> str:
        """
        Documentation generated from: `cxx/misc/yaml_example.hpp#L29
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L29>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class AdderInt(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/misc/yaml_example.hpp#L38
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L38>`_
    """
    
    @classmethod
    @bind
    def add(cls, a: int, b: int) -> int:
        """
        Documentation generated from: `cxx/misc/yaml_example.hpp#L41
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L41>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class AdderFloat(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/misc/yaml_example.hpp#L38
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L38>`_
    """
    
    @classmethod
    @bind
    def add(cls, a: float, b: float) -> float:
        """
        Documentation generated from: `cxx/misc/yaml_example.hpp#L41
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L41>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class color(metaclass=CppBindEnumMetaclass):
    """
    Documentation generated from: `cxx/misc/yaml_example.hpp#L46
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/misc/yaml_example.hpp#L46>`_
    """
    RED = pybind_yaml_example_pygen.color.RED
    GREEN = pybind_yaml_example_pygen.color.GREEN
    BLUE = pybind_yaml_example_pygen.color.BLUE

    def __int__(self):
        return self.value
