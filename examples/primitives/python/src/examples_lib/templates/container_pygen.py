"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 06/03/2022-07:13.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.templates.container as pybind_container_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class Container(metaclass=CppBindMetaclass):
    """
    An example interface which descendant types are templates. Used for an example of downcast in target language.
    Documentation generated from: `cxx/templates/container.hpp#L28
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/container.hpp#L28>`_
    """
    pass

    @bind
    def __repr__(self) -> str:
        """
        CPPBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class ContainerHolder(metaclass=CppBindMetaclass):
    """
    An example of usage for a type which descendants are template types.
    Used for an example of downcast in target language.
    Documentation generated from: `cxx/templates/container.hpp#L40
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/container.hpp#L40>`_
    """
    
    @bind
    def __init__(self, container: Container):
        """
        Documentation generated from: `cxx/templates/container.hpp#L47
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/container.hpp#L47>`_
        """
        pass
    
    @property
    @bind
    def container(self) -> Container:
        """
        Documentation generated from: `cxx/templates/container.hpp#L54
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/container.hpp#L54>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CPPBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
