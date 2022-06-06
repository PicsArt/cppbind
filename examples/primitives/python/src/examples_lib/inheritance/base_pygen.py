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

from abc import abstractmethod
from typing import *

import examples.inheritance.base as pybind_base_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class Base(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/inheritance/base.hpp#L14
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/base.hpp#L14>`_
    """
    @abstractmethod
    def __init__(self, *args, **kwargs):
        pass
    
    @bind
    def value(self) -> str:
        """
        Documentation generated from: `cxx/inheritance/base.hpp#L24
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/base.hpp#L24>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CPPBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
