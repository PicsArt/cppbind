"""
This file was generated by iegen on 06/07/2021-18:33.
Please do not change it manually.
"""

from __future__ import annotations

from typing import *

import examples.containers.map as pybind_map_pygen
from bind_utils import *
from metaclass import *


class MapItem(metaclass=OriginalMethodsMetaclass):
    """
    comments
    Documentation generated from: `cxx/containers/map.hpp#L18 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L18>`_
    """
    
    @bind
    def __init__(self, _value: int):
        """
        comments
        Documentation generated from: `cxx/containers/map.hpp#L33 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L33>`_
        """
        pass
    
    @property
    @bind
    def value(self) -> int:
        """
        comments
        Documentation generated from: `cxx/containers/map.hpp#L25 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L25>`_
        """
        pass

    @value.setter
    @bind
    def value(self, value: int):
        """
        comments
        Documentation generated from: `cxx/containers/map.hpp#L25 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L25>`_
        """
        pass


class MapExamples(metaclass=OriginalMethodsMetaclass):
    """
    comments
    Documentation generated from: `cxx/containers/map.hpp#L44 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L44>`_
    """
    
    @bind
    def __init__(self):
        """
        comments
        Documentation generated from: `cxx/containers/map.hpp#L52 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L52>`_
        """
        pass
    
    @bind
    def add_string_pair(self, info: tuple) -> None:
        """
        comments
        Documentation generated from: `cxx/containers/map.hpp#L61 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L61>`_
        """
        pass

    @bind
    def add_int_map(self, info: dict) -> None:
        """
        comments
        Documentation generated from: `cxx/containers/map.hpp#L72 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L72>`_
        """
        pass

    @bind
    def add_string_map(self, info: dict) -> None:
        """
        comments
        Documentation generated from: `cxx/containers/map.hpp#L83 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L83>`_
        """
        pass

    @bind
    def get_string_map(self) -> dict:
        """
        comments
        Documentation generated from: `cxx/containers/map.hpp#L95 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L95>`_
        """
        pass

    @bind
    def get_int_map(self) -> dict:
        """
        comments
        Documentation generated from: `cxx/containers/map.hpp#L106 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L106>`_
        """
        pass

    @bind
    def add_mixed_map(self, info: dict) -> None:
        """
        comments
        Documentation generated from: `cxx/containers/map.hpp#L117 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L117>`_
        """
        pass

    @bind
    def get_mixed_map(self) -> dict:
        """
        comments
        Documentation generated from: `cxx/containers/map.hpp#L128 <https://github.com/PicsArt/iegen/tree/master/examples/primitivescxx/containers/map.hpp#L128>`_
        """
        pass
