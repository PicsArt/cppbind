from __future__ import annotations
from typing import *
import examples.getters.number as pybind_number_pygen
from bind_utils import *
from metaclass import *


class Numberint(metaclass=OriginalMethodsMetaclass):
    """"""
    
    @bind
    def __init__(self, n: int):
        pass
    
    @property
    @bind
    def num(self) -> int:
        """"""
        pass

    @num.setter
    @bind
    def num(self, value: int):
        """"""
        pass


class Numberfloat(metaclass=OriginalMethodsMetaclass):
    """"""
    
    @bind
    def __init__(self, n: float):
        pass
    
    @property
    @bind
    def num(self) -> float:
        """"""
        pass

    @num.setter
    @bind
    def num(self, value: float):
        """"""
        pass
