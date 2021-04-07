from __future__ import annotations
from typing import *
import iegen.examples.classes.room as pybind_room_pygen
from bind_utils import *
from metaclass import *


class Room(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    
    @bind
    def calculate_area(self) -> float:
        """
        comments
        """
        pass
    @bind
    def calculate_volume(self) -> float:
        """
        comments
        """
        pass

