from __future__ import annotations
from typing import *
import examples.classes.root as pybind_root_pygen
from metaclass import *
from bind_utils import *


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

    

