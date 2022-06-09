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

import examples.overloads.utils as pybind_utils_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class Utils(metaclass=CppBindMetaclass):
    """
    An example with overloaded methods.
    Documentation generated from: `cxx/overloads/utils.hpp#L14
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L14>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/overloads/utils.hpp#L20
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L20>`_
        """
        pass
    
    @classmethod
    @bind
    def sum(cls, first: int, second: int) -> int:
        """
        Sum two ints.
        Documentation generated from: `cxx/overloads/utils.hpp#L29
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L29>`_
        """
        pass

    @classmethod
    @bind
    def sum(cls, first: float, second: float) -> float:
        """
        Sum two floats.
        Documentation generated from: `cxx/overloads/utils.hpp#L39
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L39>`_
        """
        pass

    @bind
    def concatenate(self, first: str, second: str) -> str:
        """
        Concatenate with two strings.
        Documentation generated from: `cxx/overloads/utils.hpp#L49
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L49>`_
        """
        pass

    @bind
    def concatenate(self, first: str, second: str, third: str) -> str:
        """
        Concatenate with three strings.
        Documentation generated from: `cxx/overloads/utils.hpp#L59
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L59>`_
        """
        pass

    @classmethod
    @bind
    def minus(cls, first: int, second: int) -> int:
        """
        Sub two ints.
        Documentation generated from: `cxx/overloads/utils.hpp#L72
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L72>`_
        """
        pass

    @classmethod
    @bind
    def minus(cls, first: float, second: float) -> float:
        """
        Sub two floats.
        Documentation generated from: `cxx/overloads/utils.hpp#L83
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L83>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
