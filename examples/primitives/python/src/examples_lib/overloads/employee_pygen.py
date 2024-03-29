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

import examples.overloads.employee as pybind_employee_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class Employee(metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self, name: str):
        
        pass

    @bind
    def __init__(self, age: int, email: str = ""):
        
        pass
    
    @property
    @bind
    def name(self) -> str:
        
        pass

    @property
    @bind
    def email(self) -> str:
        
        pass

    @property
    @bind
    def age(self) -> int:
        
        pass
    
    @bind
    def set_data(self, name: str, age: int, email: str = "") -> None:
        
        pass

    @bind
    def set_data(self, age: int) -> None:
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
