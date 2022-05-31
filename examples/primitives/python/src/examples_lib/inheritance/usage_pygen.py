"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 05/30/2022-13:28.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.inheritance.usage as pybind_usage_pygen
import examples_lib.inheritance.bicycle_pygen as bicycle_pygen
import examples_lib.inheritance.date_pygen as date_pygen
import examples_lib.inheritance.parallelogram_pygen as parallelogram_pygen
import examples_lib.inheritance.vehicle_pygen as vehicle_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class GeometricFigure(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/inheritance/usage.hpp#L20
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L20>`_
    """
    
    @bind
    def __init__(self, p: parallelogram_pygen.Parallelogram):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L28
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L28>`_
        """
        pass
    
    @property
    @bind
    def parallelogram(self) -> parallelogram_pygen.Parallelogram:
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L35
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L35>`_
        """
        pass

    @parallelogram.setter
    @bind
    def parallelogram(self, value: parallelogram_pygen.Parallelogram):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L35
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L35>`_
        """
        pass

    @property
    @bind
    def nullable_parallelogram(self) -> Optional[parallelogram_pygen.Parallelogram]:
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L45
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L45>`_
        """
        pass

    @nullable_parallelogram.setter
    @bind
    def nullable_parallelogram(self, value: Optional[parallelogram_pygen.Parallelogram]):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L45
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L45>`_
        """
        pass


class MyVehicle(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/inheritance/usage.hpp#L80
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L80>`_
    """
    
    @bind
    def __init__(self, v: vehicle_pygen.Vehicle, cv: vehicle_pygen.Vehicle):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L88
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L88>`_
        """
        pass
    
    @property
    @bind
    def vehicle(self) -> Optional[vehicle_pygen.Vehicle]:
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L96
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L96>`_
        """
        pass

    @vehicle.setter
    @bind
    def vehicle(self, value: Optional[vehicle_pygen.Vehicle]):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L96
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L96>`_
        """
        pass

    @property
    @bind
    def const_vehicle(self) -> Optional[vehicle_pygen.Vehicle]:
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L116
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L116>`_
        """
        pass

    @const_vehicle.setter
    @bind
    def const_vehicle(self, value: Optional[vehicle_pygen.Vehicle]):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L116
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L116>`_
        """
        pass


class MyBicycle(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/inheritance/usage.hpp#L142
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L142>`_
    """
    
    @bind
    def __init__(self, b: bicycle_pygen.Bicycle):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L150
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L150>`_
        """
        pass
    
    @property
    @bind
    def bicycle(self) -> bicycle_pygen.Bicycle:
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L158
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L158>`_
        """
        pass

    @bicycle.setter
    @bind
    def bicycle(self, value: bicycle_pygen.Bicycle):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L158
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L158>`_
        """
        pass


class MyCalendar(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/inheritance/usage.hpp#L182
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L182>`_
    """
    
    @bind
    def __init__(self, events: List[date_pygen.Date]):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L190
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L190>`_
        """
        pass
    
    @property
    @bind
    def events(self) -> List[date_pygen.Date]:
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L207
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L207>`_
        """
        pass
    
    @bind
    def add_event(self, e: date_pygen.Date) -> None:
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L198
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L198>`_
        """
        pass
