from __future__ import annotations
from typing import *
import examples.getters.number as pybind_number_pygen
from bind_utils import *
from metaclass import *


class Numberint(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    @bind
    def __init__(self, n: int):
        pass
    
    @property
    @bind
    def num(self) -> int:
        """
        comments
        """
        pass

    @num.setter
    @bind
    def num(self, value: int):
        """
        comments
        """
        pass


class Numberfloat(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    @bind
    def __init__(self, n: float):
        pass
    
    @property
    @bind
    def num(self) -> float:
        """
        comments
        """
        pass

    @num.setter
    @bind
    def num(self, value: float):
        """
        comments
        """
        pass
