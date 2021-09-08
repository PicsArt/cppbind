"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 09/06/2021-11:13.
Please do not change it manually.
"""

from __future__ import annotations

from typing import *

import examples.containers.nested_containers as pybind_nested_containers_pygen
from examples_lib.bind_utils import *
from examples_lib.metaclass import *


class NestedExamples(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/containers/nested_containers.hpp#L14
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L14>`_
    """
    
    @bind
    def __init__(self):
        """
        comments

        Documentation generated from: `cxx/containers/nested_containers.hpp#L22
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L22>`_
        """
        pass
    
    @bind
    def set_nested_int_vector(self, v: List[List[int]]) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L29
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L29>`_
        """
        pass

    @bind
    def get_nested_int_vector(self) -> List[List[int]]:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L38
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L38>`_
        """
        pass

    @bind
    def set_nested_int_map(self, m: dict) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L47
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L47>`_
        """
        pass

    @bind
    def get_nested_int_map(self) -> dict:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L55
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L55>`_
        """
        pass

    @bind
    def mixed_example_with_many_args(self, v1: List[List[int]], v2: List[List[int]], m1: dict, m2: dict) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L64
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L64>`_
        """
        pass

    @bind
    def set_vector_of_int_maps(self, v: List[dict]) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L73
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L73>`_
        """
        pass

    @bind
    def get_vector_of_int_maps(self) -> List[dict]:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L82
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L82>`_
        """
        pass

    @bind
    def set_map_of_int_vectors(self, m: dict) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L91
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L91>`_
        """
        pass

    @bind
    def get_map_of_int_vectors(self) -> dict:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L100
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L100>`_
        """
        pass
