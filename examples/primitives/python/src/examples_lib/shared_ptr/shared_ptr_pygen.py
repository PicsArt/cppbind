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

from typing import *

import examples.shared_ptr.shared_ptr as pybind_shared_ptr_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class Car(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L13
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L13>`_
    """
    
    @bind
    def __init__(self, cost: int):
        """
        Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L20
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L20>`_
        """
        pass
    
    @property
    @bind
    def cost(self) -> int:
        """
        value getter
        Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L32
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L32>`_
        """
        pass
    
    @bind
    def set_cost_with_car_shared_ptr(self, sp: Car) -> None:
        """
        Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L41
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L41>`_
        """
        pass

    @bind
    def set_cost_with_car(self, sp: Car) -> None:
        """
        Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L50
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L50>`_
        """
        pass

    @bind
    def set_cost_with_car_const_shared_ptr(self, sp: Car) -> None:
        """
        comments

        Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L62
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L62>`_
        """
        pass

    @bind
    def make_const_shared_ptr(self, sp: Car) -> Car:
        """
        comments

        Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L73
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L73>`_
        """
        pass

    @bind
    def set_cost_with_car_ref(self, sp: Car) -> None:
        """
        Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L82
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L82>`_
        """
        pass

    @bind
    def set_cost_with_car_ptr(self, sp: Car) -> None:
        """
        Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L91
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L91>`_
        """
        pass

    @bind
    def get_new_car_shared_ptr(self) -> Car:
        """
        Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L100
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L100>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class CarUsage(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L115
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L115>`_
    """
    
    @bind
    def __init__(self, car: Car):
        """
        Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L122
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L122>`_
        """
        pass
    
    @bind
    def get_car(self) -> Car:
        """
        CppBind supports only by value return in case shared_ref is set
        Documentation generated from: `cxx/shared_ptr/shared_ptr.hpp#L130
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/shared_ptr/shared_ptr.hpp#L130>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
