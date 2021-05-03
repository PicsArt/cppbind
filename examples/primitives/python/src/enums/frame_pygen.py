from __future__ import annotations
from typing import *
import examples.enums.frame as pybind_frame_pygen
from bind_utils import *
from metaclass import *


class Frame(metaclass=OriginalMethodsMetaclass):
    """
    """
    
    @bind
    def __init__(self):
        pass
    
    @property
    @bind
    def background_color(self) -> Color:
        """"""
        pass

    @background_color.setter
    @bind
    def background_color(self, value: Color):
        """"""
        pass
