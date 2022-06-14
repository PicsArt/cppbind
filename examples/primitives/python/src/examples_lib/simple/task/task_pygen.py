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

import examples.simple.task.task as pybind_task_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class PyTask(metaclass=CppBindMetaclass):
    """
    Class holding task information.
    Documentation generated from: `cxx/simple/task.hpp#L19
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/simple/task.hpp#L19>`_
    """
    
    @bind
    def __init__(self, title: str):
        """
        Task Constructor.
        Documentation generated from: `cxx/simple/task.hpp#L28
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/simple/task.hpp#L28>`_
        """
        pass
    
    @property
    @bind
    def title(self) -> str:
        """
        Get objects title.
        Documentation generated from: `cxx/simple/task.hpp#L36
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/simple/task.hpp#L36>`_
        """
        pass
    
    @bind
    def set_title(self, title: str) -> None:
        """
        Get objects title.
        Documentation generated from: `cxx/simple/task.hpp#L46
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/simple/task.hpp#L46>`_
        """
        pass

    @bind
    def __eq__(self, t: PyTask) -> bool:
        """
        Documentation generated from: `cxx/simple/task.hpp#L55
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/simple/task.hpp#L55>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
