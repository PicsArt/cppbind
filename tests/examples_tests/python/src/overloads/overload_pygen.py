from __future__ import annotations
from typing import *
import iegen.examples.overloads.overload as pybind_overload_pygen
from bind_utils import *
from metaclass import *


class Overload(metaclass=OriginalMethodsMetaclass):
    """
    An example for with overloaded methods."""
    @bind
    def __init__(self):
        pass


    
    @bind
    def concatenate(self, first: str, second: str) -> str:
        """
        Concatenate with two strings.
        """
        pass
    @bind
    def concatenate(self, first: str, second: str, third: str) -> str:
        """
        Concatenate with three strings.
        """
        pass

