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

import examples.nested_types.list as pybind_list_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class List(metaclass=CppBindMetaclass):
    """
    An example with multi level nested type using header_code_fragment to create an alias in target languages.
    Documentation generated from: `cxx/nested_types/list.hpp#L23
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L23>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/nested_types/list.hpp#L69
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L69>`_
        """
        pass
    
    @property
    @bind
    def back(self) -> List.Item:
        """
        Documentation generated from: `cxx/nested_types/list.hpp#L95
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L95>`_
        """
        pass
    

    class Item(metaclass=CppBindMetaclass):
        """
        Documentation generated from: `cxx/nested_types/list.hpp#L30
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L30>`_
        """
        
        @bind
        def __init__(self, v: List.Item.Value):
            """
            Documentation generated from: `cxx/nested_types/list.hpp#L61
            <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L61>`_
            """
            pass
        
        @property
        @bind
        def value(self) -> List.Item.Value:
            """
            Documentation generated from: `cxx/nested_types/list.hpp#L54
            <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L54>`_
            """
            pass

        @value.setter
        @bind
        def value(self, value: List.Item.Value):
            """
            Documentation generated from: `cxx/nested_types/list.hpp#L54
            <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L54>`_
            """
            pass
        

        class Value(metaclass=CppBindMetaclass):
            """
            Documentation generated from: `cxx/nested_types/list.hpp#L36
            <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L36>`_
            """
            
            @bind
            def __init__(self, _value: int):
                """
                Documentation generated from: `cxx/nested_types/list.hpp#L48
                <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L48>`_
                """
                pass
            
            @property
            @bind
            def value(self) -> int:
                """
                Documentation generated from: `cxx/nested_types/list.hpp#L41
                <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L41>`_
                """
                pass

            @value.setter
            @bind
            def value(self, value: int):
                """
                Documentation generated from: `cxx/nested_types/list.hpp#L41
                <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L41>`_
                """
                pass

            @bind
            def __repr__(self) -> str:
                """
                CppBind generated __repr__ method returning underlying C++ object type and id.
                """
                pass

    @bind
    def push_back(self, item: List.Item) -> None:
        """
        Documentation generated from: `cxx/nested_types/list.hpp#L76
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L76>`_
        """
        pass

    @bind
    def pop_back(self) -> None:
        """
        Documentation generated from: `cxx/nested_types/list.hpp#L85
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/nested_types/list.hpp#L85>`_
        """
        pass
