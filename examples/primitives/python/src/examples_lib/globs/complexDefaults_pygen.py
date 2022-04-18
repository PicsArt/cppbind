"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 04/08/2022-05:40.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.globs.complexDefaults as pybind_complexDefaults_pygen
import examples_lib.simple.root_pygen as simple_root_pygen
import examples_lib.simple.task.task_pygen as simple_task_task_pygen
from examples_lib.iegen.bind_utils_pygen import *
from examples_lib.iegen.metaclass_pygen import *


@bind
def single_complex_default_value(task: simple_task_task_pygen.PyTask = None) -> simple_task_task_pygen.PyTask:
    """
    Documentation generated from: `cxx/globs/utils.hpp#L161
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/globs/utils.hpp#L161>`_
    """
    pass


@bind
def multiple_mixed_default_values(task: simple_task_task_pygen.PyTask = None, i: int = 1, r: simple_root_pygen.Root = None) -> str:
    """
    A global function with mixed default values.
    Documentation generated from: `cxx/globs/utils.hpp#L174
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/globs/utils.hpp#L174>`_
    """
    pass
