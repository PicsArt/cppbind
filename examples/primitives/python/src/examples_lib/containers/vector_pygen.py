"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 02/07/2022-10:05.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.containers.vector as pybind_vector_pygen
from examples_lib.iegen.bind_utils_pygen import *
from examples_lib.iegen.metaclass_pygen import *


class VectorItem(metaclass=OriginalMethodsMetaclass):
    """
    comments

    Documentation generated from: `cxx/containers/vector.hpp#L17
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L17>`_
    """
    
    @bind
    def __init__(self, _value: int):
        """
        comments

        Documentation generated from: `cxx/containers/vector.hpp#L33
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L33>`_
        """
        pass
    
    @property
    @bind
    def value(self) -> int:
        """
        comments

        Documentation generated from: `cxx/containers/vector.hpp#L24
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L24>`_
        """
        pass

    @value.setter
    @bind
    def value(self, value: int):
        """
        comments

        Documentation generated from: `cxx/containers/vector.hpp#L24
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L24>`_
        """
        pass


class VectorExamples(metaclass=OriginalMethodsMetaclass):
    """
    comments

    Documentation generated from: `cxx/containers/vector.hpp#L44
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L44>`_
    """
    
    @bind
    def __init__(self):
        """
        comments

        Documentation generated from: `cxx/containers/vector.hpp#L53
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L53>`_
        """
        pass
    
    @bind
    def add_int_vector(self, v: List[int]) -> None:
        """
        comments

        Documentation generated from: `cxx/containers/vector.hpp#L62
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L62>`_
        """
        pass

    @bind
    def add_obj_vector(self, v: List[VectorItem]) -> None:
        """
        comments

        Documentation generated from: `cxx/containers/vector.hpp#L75
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L75>`_
        """
        pass

    @bind
    def add_string_vector(self, v: List[str]) -> None:
        """
        comments

        Documentation generated from: `cxx/containers/vector.hpp#L88
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L88>`_
        """
        pass

    @bind
    def get_string_vector(self) -> List[str]:
        """
        comments

        Documentation generated from: `cxx/containers/vector.hpp#L101
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L101>`_
        """
        pass

    @bind
    def get_obj_vector(self) -> List[VectorItem]:
        """
        comments

        Documentation generated from: `cxx/containers/vector.hpp#L113
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L113>`_
        """
        pass

    @bind
    def get_int_vector(self) -> List[int]:
        """
        comments

        Documentation generated from: `cxx/containers/vector.hpp#L124
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/vector.hpp#L124>`_
        """
        pass
