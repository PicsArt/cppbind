"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 12/07/2021-12:30.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.simple.holder as pybind_holder_pygen
import examples_lib.simple.task.task_pygen as task
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class Holder(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/simple/holder.hpp#L13
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/simple/holder.hpp#L13>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/simple/holder.hpp#L21
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/simple/holder.hpp#L21>`_
        """
        pass
    
    @property
    @bind
    def task(self) -> task.PyTask:
        """
        Documentation generated from: `cxx/simple/holder.hpp#L28
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/simple/holder.hpp#L28>`_
        """
        pass