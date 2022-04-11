"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 03/24/2022-13:05.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.enums.frame as pybind_frame_pygen
import examples_lib.enums.color_pygen as color
from examples_lib.iegen.bind_utils_pygen import *
from examples_lib.iegen.metaclass_pygen import *


class Frame(metaclass=IEGenMetaclass):
    """
    Class Frame.
    Documentation generated from: `cxx/enums/frame.hpp#L14
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/enums/frame.hpp#L14>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/enums/frame.hpp#L20
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/enums/frame.hpp#L20>`_
        """
        pass
    
    @property
    @bind
    def background_color(self) -> color.Color:
        """
        Documentation generated from: `cxx/enums/frame.hpp#L26
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/enums/frame.hpp#L26>`_
        """
        pass

    @background_color.setter
    @bind
    def background_color(self, value: color.Color):
        """
        Documentation generated from: `cxx/enums/frame.hpp#L26
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/enums/frame.hpp#L26>`_
        """
        pass

    @property
    @bind
    def background_color_shade(self) -> color.ColorShade:
        """
        Documentation generated from: `cxx/enums/frame.hpp#L32
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/enums/frame.hpp#L32>`_
        """
        pass

    @background_color_shade.setter
    @bind
    def background_color_shade(self, value: color.ColorShade):
        """
        Documentation generated from: `cxx/enums/frame.hpp#L32
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/enums/frame.hpp#L32>`_
        """
        pass
