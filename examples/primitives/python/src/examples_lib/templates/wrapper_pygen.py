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

import examples.templates.wrapper as pybind_wrapper_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class WrapperPairStrings(metaclass=CppBindMetaclass):
    """
    This is a template class example.
    For templates user must explicitly specify all possible types for each template parameter in the API using
    template attribute.
    Documentation generated from: `cxx/templates/wrapper.hpp#L25
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L25>`_
    """
    
    @bind
    def __init__(self, value: Tuple[str, str]):
        """
        Documentation generated from: `cxx/templates/wrapper.hpp#L34
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L34>`_
        """
        pass
    
    @property
    @bind
    def value(self) -> Tuple[str, str]:
        """
        Documentation generated from: `cxx/templates/wrapper.hpp#L50
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L50>`_
        """
        pass

    @value.setter
    @bind
    def value(self, value: Tuple[str, str]):
        """
        Documentation generated from: `cxx/templates/wrapper.hpp#L50
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L50>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class WrapperPairIntInt(metaclass=CppBindMetaclass):
    """
    This is a template class example.
    For templates user must explicitly specify all possible types for each template parameter in the API using
    template attribute.
    Documentation generated from: `cxx/templates/wrapper.hpp#L25
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L25>`_
    """
    
    @bind
    def __init__(self, value: Tuple[int, int]):
        """
        Documentation generated from: `cxx/templates/wrapper.hpp#L34
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L34>`_
        """
        pass
    
    @property
    @bind
    def value(self) -> Tuple[int, int]:
        """
        Documentation generated from: `cxx/templates/wrapper.hpp#L50
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L50>`_
        """
        pass

    @value.setter
    @bind
    def value(self, value: Tuple[int, int]):
        """
        Documentation generated from: `cxx/templates/wrapper.hpp#L50
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L50>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class WrapperString(metaclass=CppBindMetaclass):
    """
    This is a template class example.
    For templates user must explicitly specify all possible types for each template parameter in the API using
    template attribute.
    Documentation generated from: `cxx/templates/wrapper.hpp#L25
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L25>`_
    """
    
    @bind
    def __init__(self, value: str):
        """
        Documentation generated from: `cxx/templates/wrapper.hpp#L34
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L34>`_
        """
        pass
    
    @property
    @bind
    def value(self) -> str:
        """
        Documentation generated from: `cxx/templates/wrapper.hpp#L50
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L50>`_
        """
        pass

    @value.setter
    @bind
    def value(self, value: str):
        """
        Documentation generated from: `cxx/templates/wrapper.hpp#L50
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/templates/wrapper.hpp#L50>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
