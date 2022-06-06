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

import examples.simple.path as pybind_path_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class Path(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/simple/path.hpp#L14
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/simple/path.hpp#L14>`_
    """
    
    @bind
    def __init__(self, _value: str):
        """
        Documentation generated from: `cxx/simple/path.hpp#L21
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/simple/path.hpp#L21>`_
        """
        pass
    
    @property
    @bind
    def value(self) -> str:
        """
        Documentation generated from: `cxx/simple/path.hpp#L38
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/simple/path.hpp#L38>`_
        """
        pass

    
    @bind
    def __str__(self) -> str:
        """
        Documentation generated from: `cxx/simple/path.hpp#L29
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/simple/path.hpp#L29>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CPPBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
