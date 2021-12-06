"""
,--.,------. ,----.   ,------.,--.  ,--.
|  ||  .---''  .-.|   |  .---'|  ,'.|  |
|  ||  `--, |  | .---.|  `--, |  |' '  |
|  ||  `---.'  '--'  ||  `---.|  | `   |
`--'`------' `------' `------'`--'  `--'

This file is generated by iegen on 12/06/2021-12:08.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.inheritance.rectangle as pybind_rectangle_pygen
import examples_lib.inheritance.parallelogram_pygen as parallelogram
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class Rectangle(parallelogram.Parallelogram, metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/inheritance/rectangle.hpp#L13
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/rectangle.hpp#L13>`_
    """
    
    @bind
    def __init__(self, length: float, width: float):
        """
        Documentation generated from: `cxx/inheritance/rectangle.hpp#L20
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/rectangle.hpp#L20>`_
        """
        pass
    
    @property
    @bind
    def area(self) -> float:
        """
        Documentation generated from: `cxx/inheritance/rectangle.hpp#L30
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/rectangle.hpp#L30>`_
        """
        pass

    @property
    @bind
    def length(self) -> float:
        """
        Documentation generated from: `cxx/inheritance/rectangle.hpp#L43
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/rectangle.hpp#L43>`_
        """
        pass

    @property
    @bind
    def width(self) -> float:
        """
        Documentation generated from: `cxx/inheritance/rectangle.hpp#L52
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/rectangle.hpp#L52>`_
        """
        pass
