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

from typing import *

import examples.typedefs.queue_int as pybind_queue_int_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class QueueInt(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/typedefs/queue_int.hpp#L16
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L16>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L23
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L23>`_
        """
        pass
    
    @bind
    def push_back(self, element: int) -> None:
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L38
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L38>`_
        """
        pass

    @bind
    def push_back_from_str(self, element: str) -> None:
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L47
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L47>`_
        """
        pass

    @bind
    def get_size(self) -> int:
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L56
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L56>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class QueueIntUsage(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/typedefs/queue_int.hpp#L75
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L75>`_
    """
    
    @bind
    def __init__(self, q: QueueInt):
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L82
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L82>`_
        """
        pass
    
    @property
    @bind
    def empty_queue(self) -> QueueInt:
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L140
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L140>`_
        """
        pass


    @property
    @bind
    def saved_queue(self) -> QueueInt:
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L146
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L146>`_
        """
        pass

    
    @classmethod
    @bind
    def get_size(cls, q: QueueInt) -> int:
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L89
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L89>`_
        """
        pass

    @classmethod
    @bind
    def get_last_element(cls, q: QueueInt) -> int:
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L98
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L98>`_
        """
        pass

    @classmethod
    @bind
    def get_first_element(cls, q: QueueInt) -> int:
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L107
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L107>`_
        """
        pass

    @classmethod
    @bind
    def get_inv_queue(cls, v: List[int]) -> QueueInt:
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L116
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L116>`_
        """
        pass

    @bind
    def get_saved_queue(self) -> QueueInt:
        """
        Documentation generated from: `cxx/typedefs/queue_int.hpp#L132
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/typedefs/queue_int.hpp#L132>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
