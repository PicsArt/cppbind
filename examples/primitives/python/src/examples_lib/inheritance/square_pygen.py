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

import examples.inheritance.square as pybind_square_pygen
import examples_lib.inheritance.rectangle_pygen as rectangle_pygen
import examples_lib.inheritance.rhombus_pygen as rhombus_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class Square(rhombus_pygen.RhombusFigure, rectangle_pygen.Rectangle, metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/inheritance/square.hpp#L16
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/square.hpp#L16>`_
    """
    
    @bind
    def __init__(self, side: float):
        """
        Documentation generated from: `cxx/inheritance/square.hpp#L24
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/square.hpp#L24>`_
        """
        pass
    
    @property
    @bind
    def area(self) -> float:
        """
        Documentation generated from: `cxx/inheritance/square.hpp#L31
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/square.hpp#L31>`_
        """
        pass
    
    @bind
    def perimeter(self) -> float:
        """
        Documentation generated from: `cxx/inheritance/square.hpp#L40
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/square.hpp#L40>`_
        """
        pass
