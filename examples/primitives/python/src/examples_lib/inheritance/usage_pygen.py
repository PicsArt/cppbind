"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 11/24/2022-07:17.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.inheritance.usage as pybind_usage_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *

if TYPE_CHECKING:
    import examples_lib.inheritance.bicycle_pygen as bicycle_pygen
    import examples_lib.inheritance.date_pygen as date_pygen
    import examples_lib.inheritance.parallelogram_pygen as parallelogram_pygen
    import examples_lib.inheritance.vehicle_pygen as vehicle_pygen


class GeometricFigure(metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self, p: parallelogram_pygen.Parallelogram):
        
        pass
    
    @property
    @bind
    def parallelogram(self) -> parallelogram_pygen.Parallelogram:
        
        pass

    @parallelogram.setter
    @bind
    def parallelogram(self, value: parallelogram_pygen.Parallelogram):
        
        pass

    @property
    @bind
    def nullable_parallelogram(self) -> Optional[parallelogram_pygen.Parallelogram]:
        
        pass

    @nullable_parallelogram.setter
    @bind
    def nullable_parallelogram(self, value: Optional[parallelogram_pygen.Parallelogram]):
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class MyVehicle(metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self, v: vehicle_pygen.Vehicle, cv: vehicle_pygen.Vehicle):
        
        pass
    
    @property
    @bind
    def vehicle(self) -> Optional[vehicle_pygen.Vehicle]:
        
        pass

    @vehicle.setter
    @bind
    def vehicle(self, value: Optional[vehicle_pygen.Vehicle]):
        
        pass

    @property
    @bind
    def const_vehicle(self) -> Optional[vehicle_pygen.Vehicle]:
        
        pass

    @const_vehicle.setter
    @bind
    def const_vehicle(self, value: Optional[vehicle_pygen.Vehicle]):
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class MyBicycle(metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self, b: bicycle_pygen.Bicycle):
        
        pass
    
    @property
    @bind
    def bicycle(self) -> bicycle_pygen.Bicycle:
        
        pass

    @bicycle.setter
    @bind
    def bicycle(self, value: bicycle_pygen.Bicycle):
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class MyCalendar(metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self, events: List[date_pygen.Date]):
        
        pass
    
    @property
    @bind
    def events(self) -> List[date_pygen.Date]:
        
        pass
    
    @bind
    def add_event(self, e: date_pygen.Date) -> None:
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
