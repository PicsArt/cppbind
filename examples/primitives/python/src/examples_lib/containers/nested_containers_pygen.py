"""
,--.,------. ,----.   ,------.,--.  ,--.
|  ||  .---''  .-.|   |  .---'|  ,'.|  |
|  ||  `--, |  | .---.|  `--, |  |' '  |
|  ||  `---.'  '--'  ||  `---.|  | `   |
`--'`------' `------' `------'`--'  `--'

This file is generated by iegen on 12/04/2021-12:25.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.containers.nested_containers as pybind_nested_containers_pygen
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class NestedExamples(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/containers/nested_containers.hpp#L15
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L15>`_
    """
    
    @bind
    def __init__(self):
        """
        comments

        Documentation generated from: `cxx/containers/nested_containers.hpp#L23
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L23>`_
        """
        pass
    
    @bind
    def set_nested_int_vector(self, v: List[List[int]]) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L30
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L30>`_
        """
        pass

    @bind
    def get_nested_int_vector(self) -> List[List[int]]:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L39
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L39>`_
        """
        pass

    @bind
    def set_nested_int_map(self, m: dict) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L48
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L48>`_
        """
        pass

    @bind
    def get_nested_int_map(self) -> dict:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L56
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L56>`_
        """
        pass

    @bind
    def mixed_example_with_many_args(self, v1: List[List[int]], v2: List[List[int]], m1: dict, m2: dict) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L65
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L65>`_
        """
        pass

    @bind
    def set_vector_of_int_maps(self, v: List[dict]) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L74
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L74>`_
        """
        pass

    @bind
    def get_vector_of_int_maps(self) -> List[dict]:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L83
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L83>`_
        """
        pass

    @bind
    def set_map_of_int_vectors(self, m: dict) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L92
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L92>`_
        """
        pass

    @bind
    def get_map_of_int_vectors(self) -> dict:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L101
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L101>`_
        """
        pass

    @bind
    def set_complex_string_vector(self, v: List[List[List[str]]]) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L110
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L110>`_
        """
        pass

    @bind
    def get_complex_string_vector(self) -> List[List[List[str]]]:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L119
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L119>`_
        """
        pass

    @bind
    def set_complex_string_map(self, m: dict) -> None:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L128
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L128>`_
        """
        pass

    @bind
    def get_complex_string_map(self) -> dict:
        """
        Documentation generated from: `cxx/containers/nested_containers.hpp#L137
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/containers/nested_containers.hpp#L137>`_
        """
        pass
