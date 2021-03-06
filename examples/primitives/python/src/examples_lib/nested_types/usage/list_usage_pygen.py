"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 06/09/2022-13:25.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.nested_types.usage.list_usage as pybind_list_usage_pygen
import examples_lib.nested_types.list_pygen as list_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class ListWrapper(metaclass=CppBindMetaclass):
    """
    A dummy test example using nested types.
    Documentation generated from: `cxx/nested_types/list_usage.hpp#L16
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list_usage.hpp#L16>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/nested_types/list_usage.hpp#L23
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list_usage.hpp#L23>`_
        """
        pass
    
    @property
    @bind
    def back(self) -> list_pygen.List.Item:
        """
        Documentation generated from: `cxx/nested_types/list_usage.hpp#L38
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list_usage.hpp#L38>`_
        """
        pass
    
    @bind
    def push_back(self, item: list_pygen.List.Item) -> None:
        """
        Documentation generated from: `cxx/nested_types/list_usage.hpp#L30
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list_usage.hpp#L30>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
