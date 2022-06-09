"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 06/07/2022-13:36.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.operators.counter as pybind_counter_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class Counter(metaclass=CppBindMetaclass):
    """
    An example for with overloaded methods.
    Documentation generated from: `cxx/operators/counter.hpp#L12
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/operators/counter.hpp#L12>`_
    """
    
    @bind
    def __init__(self, count: int):
        """
        Counter constructor.
        Documentation generated from: `cxx/operators/counter.hpp#L20
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/operators/counter.hpp#L20>`_
        """
        pass
    
    @property
    @bind
    def count(self) -> int:
        """
        Getter for count.
        Documentation generated from: `cxx/operators/counter.hpp#L32
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/operators/counter.hpp#L32>`_
        """
        pass
    
    @bind
    def __add__(self, counter: Counter) -> Counter:
        """
        Plus operator
        Documentation generated from: `cxx/operators/counter.hpp#L42
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/operators/counter.hpp#L42>`_
        """
        pass

    @bind
    def __gt__(self, counter: Counter) -> bool:
        """
        Documentation generated from: `cxx/operators/counter.hpp#L66
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/operators/counter.hpp#L66>`_
        """
        pass

    @bind
    def __iadd__(self, counter: Counter) -> Counter:
        """
        Documentation generated from: `cxx/operators/counter.hpp#L77
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/operators/counter.hpp#L77>`_
        """
        pass

    @bind
    def __eq__(self, counter: Counter) -> bool:
        """
        Equality operator
        Documentation generated from: `cxx/operators/counter.hpp#L88
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/operators/counter.hpp#L88>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class PositiveCounter(metaclass=CppBindMetaclass):
    """
    A class example to the case when non-operator method is mapped to == operator
    Documentation generated from: `cxx/operators/counter.hpp#L103
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/operators/counter.hpp#L103>`_
    """
    
    @bind
    def __init__(self, count: int):
        """
        Documentation generated from: `cxx/operators/counter.hpp#L110
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/operators/counter.hpp#L110>`_
        """
        pass
    
    @bind
    def __eq__(self, other: PositiveCounter) -> bool:
        """
        Documentation generated from: `cxx/operators/counter.hpp#L121
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/operators/counter.hpp#L121>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
