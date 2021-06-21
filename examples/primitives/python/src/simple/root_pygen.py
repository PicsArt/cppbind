"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 06/18/2021-14:08.
Please do not change it manually.
"""

from __future__ import annotations

from typing import *

import examples.simple.root as pybind_root_pygen
from bind_utils import *
from metaclass import *


class Root(metaclass=OriginalMethodsMetaclass):
    """
    Class Root
    Documentation generated from: `cxx/simple/root.hpp#L20
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/simple/root.hpp#L20>`_
    """
    
    @bind
    def __init__(self, _path: str):
        """
        comments

        Documentation generated from: `cxx/simple/root.hpp#L28
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/simple/root.hpp#L28>`_
        """
        pass
    
    @property
    @bind
    def path(self) -> str:
        """
        Documentation generated from: `cxx/simple/root.hpp#L44
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/simple/root.hpp#L44>`_
        """
        pass

    @path.setter
    @bind
    def path(self, value: str):
        """
        Documentation generated from: `cxx/simple/root.hpp#L44
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/simple/root.hpp#L44>`_
        """
        pass
    
    @bind
    def set_path(self, _path: str) -> None:
        """
        Documentation generated from: `cxx/simple/root.hpp#L36
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/simple/root.hpp#L36>`_
        """
        pass
