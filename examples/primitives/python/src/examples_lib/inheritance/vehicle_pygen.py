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

from abc import abstractmethod
from typing import *

import examples.inheritance.vehicle as pybind_vehicle_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class Vehicle(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/inheritance/vehicle.hpp#L16
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/vehicle.hpp#L16>`_
    """
    @abstractmethod
    def __init__(self, *args, **kwargs):
        pass
    
    @property
    @bind
    def number_of_seats(self) -> int:
        """
        Documentation generated from: `cxx/inheritance/vehicle.hpp#L26
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/vehicle.hpp#L26>`_
        """
        pass
    
    @bind
    def type(self) -> str:
        """
        Documentation generated from: `cxx/inheritance/vehicle.hpp#L35
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/vehicle.hpp#L35>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
