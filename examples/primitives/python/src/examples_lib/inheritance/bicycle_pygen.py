"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 11/22/2022-06:43.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.inheritance.bicycle as pybind_bicycle_pygen
import examples_lib.inheritance.vehicle_pygen as vehicle_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class Bicycle(vehicle_pygen.Vehicle, metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self, number_of_seats: int):
        
        pass
    
    @bind
    def type(self) -> str:
        
        pass


class ElectricBicycle(Bicycle, metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self, number_of_seats: int):
        
        pass
    
    @bind
    def type(self) -> str:
        
        pass


class MountainBicycle(Bicycle, metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self, number_of_seats: int):
        
        pass
    
    @bind
    def type(self) -> str:
        
        pass


class ElectricCityBicycle(ElectricBicycle, metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self, number_of_seats: int):
        
        pass
    
    @bind
    def type(self) -> str:
        
        pass
