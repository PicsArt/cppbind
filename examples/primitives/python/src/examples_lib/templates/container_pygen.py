"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 12/06/2021-18:17.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.templates.container as pybind_container_pygen
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class Container(metaclass=OriginalMethodsMetaclass):
    """
    An example interface which descendant types are templates. Used for an example of downcast in target language.
    Documentation generated from: `cxx/templates/container.hpp#L28
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/container.hpp#L28>`_
    """
    pass


class ContainerHolder(metaclass=OriginalMethodsMetaclass):
    """
    An example of usage for a type which descendants are template types.
    Used for an example of downcast in target language.
    Documentation generated from: `cxx/templates/container.hpp#L40
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/container.hpp#L40>`_
    """
    
    @bind
    def __init__(self, container: Container):
        """
        Documentation generated from: `cxx/templates/container.hpp#L47
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/container.hpp#L47>`_
        """
        pass
    
    @property
    @bind
    def container(self) -> Container:
        """
        Documentation generated from: `cxx/templates/container.hpp#L54
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/container.hpp#L54>`_
        """
        pass
