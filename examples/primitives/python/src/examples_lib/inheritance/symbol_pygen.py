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

import examples.inheritance.symbol as pybind_symbol_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class Sign(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/inheritance/symbol.hpp#L13
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L13>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L22
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L22>`_
        """
        pass
    
    @bind
    def type_name(self) -> str:
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L31
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L31>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CPPBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class Text(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/inheritance/symbol.hpp#L44
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L44>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L52
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L52>`_
        """
        pass
    
    @bind
    def type_name(self) -> str:
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L61
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L61>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CPPBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class Digit(Sign, Text, metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/inheritance/symbol.hpp#L74
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L74>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L82
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L82>`_
        """
        pass
    
    @bind
    def type_name(self) -> str:
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L89
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L89>`_
        """
        pass


class SymbolUsage(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/inheritance/symbol.hpp#L102
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L102>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L109
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L109>`_
        """
        pass

    @bind
    def __init__(self, d: Digit):
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L116
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L116>`_
        """
        pass
    
    @bind
    def get_text_type(self, t: Text) -> str:
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L123
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L123>`_
        """
        pass

    @bind
    def get_sign_type(self, s: Sign) -> str:
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L132
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L132>`_
        """
        pass

    @bind
    def get_text_id(self, t: Text) -> int:
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L141
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L141>`_
        """
        pass

    @bind
    def get_sign_id(self, s: Sign) -> int:
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L150
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L150>`_
        """
        pass

    @bind
    def get_text_ptr(self) -> Text:
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L160
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L160>`_
        """
        pass

    @bind
    def get_sign_ptr(self) -> Sign:
        """
        Documentation generated from: `cxx/inheritance/symbol.hpp#L170
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/symbol.hpp#L170>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CPPBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
