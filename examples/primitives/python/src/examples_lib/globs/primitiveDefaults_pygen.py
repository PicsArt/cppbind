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

import examples.globs.primitiveDefaults as pybind_primitiveDefaults_pygen
import examples_lib.enums.color_pygen as enums_color_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


@bind
def optional_color(c: enums_color_pygen.Color = enums_color_pygen.Color.Red) -> enums_color_pygen.Color:
    """
    A global function with enum default argument.
    Documentation generated from: `cxx/globs/utils.hpp#L120
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/globs/utils.hpp#L120>`_
    """
    pass


@bind
def optional_string(optional_str: str = "abc") -> str:
    """
    A global function with string default argument.
    Documentation generated from: `cxx/globs/utils.hpp#L133
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/globs/utils.hpp#L133>`_
    """
    pass


@bind
def optional_int(i: int = 5) -> int:
    """
    A global function with primitive default value.
    Documentation generated from: `cxx/globs/utils.hpp#L145
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/globs/utils.hpp#L145>`_
    """
    pass
