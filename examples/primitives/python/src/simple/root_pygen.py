from __future__ import annotations
from typing import *
import examples.simple.root as pybind_root_pygen
from bind_utils import *
from metaclass import *


class Root(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    @bind
    def __init__(self, _path: str):
        pass
    
    @property
    @bind
    def path(self) -> str:
        """
        comments
        """
        pass

