from __future__ import annotations
from typing import *
import examples.overloads.utils as pybind_utils_pygen
from bind_utils import *
from metaclass import *


class Utils(metaclass=OriginalMethodsMetaclass):
    """
    An example for with overloaded methods."""
    
    @classmethod
    @bind
    def sum(cls, first: int, second: int) -> int:
        """
        Concatenate with two strings.
        """
        pass

    @classmethod
    @bind
    def sum(cls, first: float, second: float) -> float:
        """
        Concatenate with three strings.
        """
        pass
