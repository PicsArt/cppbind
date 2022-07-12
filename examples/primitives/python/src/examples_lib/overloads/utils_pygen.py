"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 07/06/2022-11:52.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.overloads.utils as pybind_utils_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class Utils(metaclass=CppBindMetaclass):
    """
    An example with overloaded methods.
    Documentation generated from: `cxx/overloads/utils.hpp#L16
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L16>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/overloads/utils.hpp#L22
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L22>`_
        """
        pass
    
    @classmethod
    @bind
    def sum(cls, first: int, second: int) -> int:
        """
        Sum two ints.
        Documentation generated from: `cxx/overloads/utils.hpp#L31
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L31>`_
        """
        pass

    @classmethod
    @bind
    def sum(cls, first: float, second: float) -> float:
        """
        Sum two floats.
        Documentation generated from: `cxx/overloads/utils.hpp#L41
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L41>`_
        """
        pass

    @bind
    def concatenate(self, first: str, second: str) -> str:
        """
        Concatenate with two strings.
        Documentation generated from: `cxx/overloads/utils.hpp#L51
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L51>`_
        """
        pass

    @bind
    def concatenate(self, first: str, second: str, third: str) -> str:
        """
        Concatenate with three strings.
        Documentation generated from: `cxx/overloads/utils.hpp#L61
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L61>`_
        """
        pass

    @classmethod
    @bind
    def minus(cls, first: int, second: int) -> int:
        """
        Sub two ints.
        Documentation generated from: `cxx/overloads/utils.hpp#L74
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L74>`_
        """
        pass

    @classmethod
    @bind
    def minus(cls, first: float, second: float) -> float:
        """
        Sub two floats.
        Documentation generated from: `cxx/overloads/utils.hpp#L85
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L85>`_
        """
        pass

    @bind
    def sum_lists(self, first: List[int], second: List[int]) -> List[int]:
        """
        Documentation generated from: `cxx/overloads/utils.hpp#L99
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L99>`_
        """
        pass

    @bind
    def sum_lists(self, first: List[float], second: List[float]) -> List[float]:
        """
        Documentation generated from: `cxx/overloads/utils.hpp#L113
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/overloads/utils.hpp#L113>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
