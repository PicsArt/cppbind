"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 06/28/2021-13:46.
Please do not change it manually.
"""

from __future__ import annotations

from typing import *

import examples.overloads.utils as pybind_utils_pygen
from bind_utils import *
from metaclass import *


class Utils(metaclass=OriginalMethodsMetaclass):
    """
    An example with overloaded methods.
    Documentation generated from: `cxx/overloads/utils.hpp#L16
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/utils.hpp#L16>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/overloads/utils.hpp#L21
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/utils.hpp#L21>`_
        """
        pass
    
    @classmethod
    @bind
    def sum(cls, first: int, second: int) -> int:
        """
        Sum two ints.
        Documentation generated from: `cxx/overloads/utils.hpp#L29
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/utils.hpp#L29>`_
        """
        pass

    @classmethod
    @bind
    def sum(cls, first: float, second: float) -> float:
        """
        Sum two floats.
        Documentation generated from: `cxx/overloads/utils.hpp#L39
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/utils.hpp#L39>`_
        """
        pass

    @bind
    def concatenate(self, first: str, second: str) -> str:
        """
        Concatenate with two strings.
        Documentation generated from: `cxx/overloads/utils.hpp#L49
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/utils.hpp#L49>`_
        """
        pass

    @bind
    def concatenate(self, first: str, second: str, third: str) -> str:
        """
        Concatenate with three strings.
        Documentation generated from: `cxx/overloads/utils.hpp#L59
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/utils.hpp#L59>`_
        """
        pass
