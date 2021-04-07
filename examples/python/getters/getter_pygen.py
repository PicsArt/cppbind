from __future__ import annotations
from typing import *
import iegen.examples.getters.getter as pybind_getter_pygen
from bind_utils import *
from metaclass import *


class GetterSetter(metaclass=OriginalMethodsMetaclass):
    """
    comments"""

    @bind
    def __init__(self):
        pass

    @property
    @bind
    def value(self) -> str:
        """
        value getter"""
        pass

    @value.setter
    @bind
    def value(self, value: str):
        """
        value getter"""
        pass


class GetterSetterExtended(GetterSetter, metaclass=OriginalMethodsMetaclass):
    """
    comments"""

    @bind
    def __init__(self):
        pass
