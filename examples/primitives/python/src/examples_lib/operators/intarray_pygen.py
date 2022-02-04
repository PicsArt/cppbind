"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 01/31/2022-08:01.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.operators.intarray as pybind_intarray_pygen
from examples_lib.iegen.bind_utils_pygen import *
from examples_lib.iegen.metaclass_pygen import *


class IntArray(metaclass=OriginalMethodsMetaclass):
    """
    An example for with overloaded operators.
    Documentation generated from: `cxx/operators/intarray.hpp#L16
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/intarray.hpp#L16>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/operators/intarray.hpp#L23
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/intarray.hpp#L23>`_
        """
        pass
    
    @bind
    def __getitem__(self, i: int) -> int:
        """
        Documentation generated from: `cxx/operators/intarray.hpp#L34
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/intarray.hpp#L34>`_
        """
        pass

    @bind
    def __setitem__(self, i: int, value: int):
        """
        Documentation generated from: `cxx/operators/intarray.hpp#L34
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/intarray.hpp#L34>`_
        """
        pass

    @bind
    def __getitem__(self, i: str) -> int:
        """
        Documentation generated from: `cxx/operators/intarray.hpp#L46
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/intarray.hpp#L46>`_
        """
        pass

    @bind
    def __getitem__(self, i: float) -> int:
        """
        Documentation generated from: `cxx/operators/intarray.hpp#L59
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/intarray.hpp#L59>`_
        """
        pass