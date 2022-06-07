"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 06/03/2022-07:09.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import pybind_example_lib.array.array as pybind_array
from example_lib.cppbind.bind_utils import *
from example_lib.cppbind.metaclass import *


class Array(metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self):
        
        pass
    
    @property
    @bind
    def size(self) -> int:
        
        pass

    @property
    @bind
    def empty(self) -> bool:
        
        pass
    
    @bind
    def front(self) -> int:
        
        pass

    @bind
    def back(self) -> int:
        
        pass

    @bind
    def push_back(self, element: int) -> None:
        
        pass

    @bind
    def __getitem__(self, i: int) -> int:
        
        pass

    @bind
    def __setitem__(self, i: int, value: int):
        
        pass

    @bind
    def at(self, i: int) -> int:
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
