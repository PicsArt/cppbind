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

import examples.globs.complexDefaults as pybind_complexDefaults_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *

if TYPE_CHECKING:
    import examples_lib.simple.root_pygen as simple_root_pygen
    import examples_lib.simple.task.task_pygen as simple_task_task_pygen


@bind
def single_complex_default_value(task: simple_task_task_pygen.PyTask = None) -> simple_task_task_pygen.PyTask:
    
    pass


@bind
def multiple_mixed_default_values(task: simple_task_task_pygen.PyTask = None, i: int = 1, r: simple_root_pygen.Root = None) -> str:
    """
    A global function with mixed default values.
    """
    pass
