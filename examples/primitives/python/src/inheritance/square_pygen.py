"""
This file was generated by iegen on 06/16/2021-14:04.
Please do not change it manually.
"""

from __future__ import annotations

from typing import *

import examples.inheritance.square as pybind_square_pygen
from bind_utils import *
from metaclass import *
from inheritance.rhombus_pygen import *
from inheritance.rectangle_pygen import *


class Square(Rhombus, Rectangle, metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/inheritance/square.hpp#L20
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/square.hpp#L20>`_
    """
    
    @bind
    def __init__(self, side: float):
        """
        Documentation generated from: `cxx/inheritance/square.hpp#L27
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/square.hpp#L27>`_
        """
        pass
    
    @property
    @bind
    def area(self) -> float:
        """
        Documentation generated from: `cxx/inheritance/square.hpp#L34
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/square.hpp#L34>`_
        """
        pass
    
    @bind
    def perimeter(self) -> float:
        """
        Documentation generated from: `cxx/inheritance/square.hpp#L43
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/square.hpp#L43>`_
        """
        pass
