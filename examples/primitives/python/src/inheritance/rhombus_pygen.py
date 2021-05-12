from __future__ import annotations
from typing import *
import examples.inheritance.rhombus as pybind_rhombus_pygen
from bind_utils import *
from metaclass import *
from inheritance.parallelogram_pygen import *


class Rhombus(Parallelogram, metaclass=OriginalMethodsMetaclass):
    """"""
    
    @bind
    def __init__(self, diagonal1: float, diagonal2: float):
        pass
