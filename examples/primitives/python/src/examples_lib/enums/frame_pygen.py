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

import examples.enums.frame as pybind_frame_pygen
import examples_lib.enums.color_pygen as color_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class Frame(metaclass=CppBindMetaclass):
    """
    Class Frame.
    Documentation generated from: `cxx/enums/frame.hpp#L14
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/enums/frame.hpp#L14>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/enums/frame.hpp#L20
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/enums/frame.hpp#L20>`_
        """
        pass
    
    @property
    @bind
    def background_color(self) -> color_pygen.Color:
        """
        Documentation generated from: `cxx/enums/frame.hpp#L26
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/enums/frame.hpp#L26>`_
        """
        pass

    @background_color.setter
    @bind
    def background_color(self, value: color_pygen.Color):
        """
        Documentation generated from: `cxx/enums/frame.hpp#L26
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/enums/frame.hpp#L26>`_
        """
        pass

    @property
    @bind
    def background_color_shade(self) -> color_pygen.ColorShade:
        """
        Documentation generated from: `cxx/enums/frame.hpp#L32
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/enums/frame.hpp#L32>`_
        """
        pass

    @background_color_shade.setter
    @bind
    def background_color_shade(self, value: color_pygen.ColorShade):
        """
        Documentation generated from: `cxx/enums/frame.hpp#L32
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/enums/frame.hpp#L32>`_
        """
        pass
    
    @bind
    def get_next_color(self, color: color_pygen.Color) -> color_pygen.Color:
        """
        Documentation generated from: `cxx/enums/frame.hpp#L39
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/enums/frame.hpp#L39>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
