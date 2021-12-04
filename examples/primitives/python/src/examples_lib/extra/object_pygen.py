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

import examples.extra.object as pybind_object_pygen
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class Object(metaclass=OriginalMethodsMetaclass):
    """
    comments

    Documentation generated from: `cxx/extra/object.hpp#L28
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/extra/object.hpp#L28>`_
    """
    
    @bind
    def __repr__(self) -> str:
        """
        String representation for mainly debug purposes
        @return class name and object address
        Documentation generated from: `cxx/extra/object.hpp#L40
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/extra/object.hpp#L40>`_
        """
        pass

    @bind
    def __str__(self) -> str:
        """
        String representation for user readability
        @return result of toReprString by default
        Documentation generated from: `cxx/extra/object.hpp#L50
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/extra/object.hpp#L50>`_
        """
        pass

    @bind
    def class_name(self) -> str:
        """
        Human readable class name
        @return class name
        Documentation generated from: `cxx/extra/object.hpp#L59
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/extra/object.hpp#L59>`_
        """
        pass

    @bind
    def __eq__(self, other: Object) -> bool:
        """
        Compare on equality two objects
        @param other is the second one
        @return is equals two objects
        Documentation generated from: `cxx/extra/object.hpp#L70
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/extra/object.hpp#L70>`_
        """
        pass

    @bind
    def __hash__(self) -> int:
        """
        Hash for object. Used in wrappers (java, obj-c, python) to define the hash function
        @return hash of the object
        Documentation generated from: `cxx/extra/object.hpp#L82
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/extra/object.hpp#L82>`_
        """
        pass

    @bind
    def debug_info(self) -> str:
        """
        Detailed string representation only for debug porpoises
        @return object state as string
        Documentation generated from: `cxx/extra/object.hpp#L91
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/extra/object.hpp#L91>`_
        """
        pass

    @bind
    def bytes_count(self) -> int:
        """
        The object's size in bytes
        @return bytes count
        Documentation generated from: `cxx/extra/object.hpp#L100
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/extra/object.hpp#L100>`_
        """
        pass
