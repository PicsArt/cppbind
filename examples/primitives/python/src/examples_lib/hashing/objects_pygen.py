"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 08/11/2022-07:34.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.hashing.objects as pybind_objects_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class Object1(metaclass=CppBindMetaclass):
    """
    Class with custom hash, equals and toString methods.
    """
    
    @bind
    def __init__(self, value: int = 0):
        
        pass
    
    @property
    @bind
    def value(self) -> int:
        
        pass
    
    @bind
    def __hash__(self) -> int:
        """
        Hash function returning dummy value for testing purposes.
        """
        pass

    @bind
    def __eq__(self, other: Object1) -> bool:
        """
        Equals function returning dummy value for testing purposes.
        """
        pass

    @bind
    def __str__(self) -> str:
        """
        ToString function returning dummy value for testing purposes.
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class Object2(metaclass=CppBindMetaclass):
    """
    Class without any special functions.
    For Kotlin CppBind will generate the default ones based on underlying C++ object is and type name.
    For Swift and Python it won't generate them.
    Instead for Python will generate a __repr__ returning a string containing C++ object id and type name.
    """
    
    @bind
    def __init__(self):
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class Object3(metaclass=CppBindMetaclass):
    """
    Class with custom hash, equals and toString methods.
    """
    
    @bind
    def __init__(self, value: int = 0):
        
        pass
    
    @property
    @bind
    def value(self) -> int:
        
        pass
    
    @bind
    def __hash__(self) -> int:
        """
        Hash function returning dummy value for testing purposes.
        """
        pass

    @bind
    def __eq__(self, other: Object3) -> bool:
        """
        Equals based on value property for testing purposes.
        """
        pass

    @bind
    def __str__(self) -> str:
        """
        ToString based on value property for testing purposes.
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class Object4(metaclass=CppBindMetaclass):
    """
    Class without any special functions.
    For Kotlin CppBind will generate the default ones based on underlying C++ object is and type name.
    For Swift and Python it won't generate them.
    Instead for Python will generate a __repr__ returning a string containing C++ object id and type name.
    """
    
    @bind
    def __init__(self):
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class ExtendedObject1(Object1, metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self, value: int = 0):
        
        pass
    
    @bind
    def __hash__(self) -> int:
        """
        Hash function returning dummy value for testing purposes.
        """
        pass


class ExtendedObject2(Object2, metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self):
        
        pass


class ExtendedObject3(Object3, metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self, value: int = 0):
        
        pass


class ExtendedObject4(Object4, metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self):
        
        pass
