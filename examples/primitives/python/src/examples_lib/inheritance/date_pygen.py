"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 11/29/2021-11:43.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.inheritance.date as pybind_date_pygen
import examples_lib.inheritance.base_pygen as base
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class Date(base.Base, metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/inheritance/date.hpp#L17
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/date.hpp#L17>`_
    """
    
    @bind
    def __init__(self, d: int, m: int, y: int):
        """
        Documentation generated from: `cxx/inheritance/date.hpp#L24
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/date.hpp#L24>`_
        """
        pass
    
    @property
    @bind
    def date(self) -> str:
        """
        Documentation generated from: `cxx/inheritance/date.hpp#L48
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/date.hpp#L48>`_
        """
        pass
    
    @bind
    def value(self) -> str:
        """
        Documentation generated from: `cxx/inheritance/date.hpp#L39
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/date.hpp#L39>`_
        """
        pass
