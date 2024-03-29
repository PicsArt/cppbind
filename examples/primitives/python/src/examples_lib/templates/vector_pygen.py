"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 10/12/2022-06:55.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.templates.vector as pybind_vector_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class VectorInt(metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self):
        
        pass

    @bind
    def __init__(self, vec: VectorInt):
        
        pass
    
    @bind
    def push_back(self, value: int) -> None:
        
        pass

    @bind
    def pop_back(self) -> None:
        
        pass

    @bind
    def __getitem__(self, idx: int) -> int:
        
        pass

    @bind
    def __add__(self, rhs: VectorInt) -> VectorInt:
        
        pass

    @bind
    def __eq__(self, rhs: VectorInt) -> bool:
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class StringsVector(metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self):
        
        pass

    @bind
    def __init__(self, vec: StringsVector):
        
        pass
    
    @bind
    def push_back(self, value: str) -> None:
        
        pass

    @bind
    def pop_back(self) -> None:
        
        pass

    @bind
    def __getitem__(self, idx: int) -> str:
        
        pass

    @bind
    def __add__(self, rhs: StringsVector) -> StringsVector:
        
        pass

    @bind
    def __eq__(self, rhs: StringsVector) -> bool:
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class Vector(metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self):
        
        pass

    @bind
    def __init__(self, vec: Vector):
        
        pass
    
    @bind
    def push_back(self, value: float) -> None:
        
        pass

    @bind
    def pop_back(self) -> None:
        
        pass

    @bind
    def __getitem__(self, idx: int) -> float:
        
        pass

    @bind
    def __add__(self, rhs: Vector) -> Vector:
        
        pass

    @bind
    def __eq__(self, rhs: Vector) -> bool:
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


@bind
def create_vector_int_int_int(args1: int, args2: int) -> VectorInt:
    """
    An example with variadic template.
    """
    pass
