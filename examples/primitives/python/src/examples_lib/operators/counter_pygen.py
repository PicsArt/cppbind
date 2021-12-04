"""
,--.,------. ,----.   ,------.,--.  ,--.
|  ||  .---''  .-.|   |  .---'|  ,'.|  |
|  ||  `--, |  | .---.|  `--, |  |' '  |
|  ||  `---.'  '--'  ||  `---.|  | `   |
`--'`------' `------' `------'`--'  `--'

This file is generated by iegen on 12/04/2021-12:25.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.operators.counter as pybind_counter_pygen
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class Counter(metaclass=OriginalMethodsMetaclass):
    """
    An example for with overloaded methods.
    Documentation generated from: `cxx/operators/counter.hpp#L12
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/counter.hpp#L12>`_
    """
    
    @bind
    def __init__(self, count: int):
        """
        Counter constructor.
        Documentation generated from: `cxx/operators/counter.hpp#L19
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/counter.hpp#L19>`_
        """
        pass
    
    @property
    @bind
    def count(self) -> int:
        """
        Getter for count.
        Documentation generated from: `cxx/operators/counter.hpp#L31
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/counter.hpp#L31>`_
        """
        pass
    
    @bind
    def __add__(self, counter: Counter) -> Counter:
        """
        Plus operator
        Documentation generated from: `cxx/operators/counter.hpp#L42
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/counter.hpp#L42>`_
        """
        pass

    @bind
    def compare_to(self, counter: Counter) -> int:
        """
        Comparison operator for kotlin
        Documentation generated from: `cxx/operators/counter.hpp#L54
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/counter.hpp#L54>`_
        """
        pass

    @bind
    def __gt__(self, counter: Counter) -> bool:
        """
        Documentation generated from: `cxx/operators/counter.hpp#L67
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/counter.hpp#L67>`_
        """
        pass

    @bind
    def __iadd__(self, counter: Counter) -> Counter:
        """
        Documentation generated from: `cxx/operators/counter.hpp#L78
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/operators/counter.hpp#L78>`_
        """
        pass
