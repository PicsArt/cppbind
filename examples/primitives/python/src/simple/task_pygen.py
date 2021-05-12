from __future__ import annotations
from typing import *
import examples.simple.task as pybind_task_pygen
from bind_utils import *
from metaclass import *


class Task(metaclass=OriginalMethodsMetaclass):
    """
    Class holding task information."""
    
    @bind
    def __init__(self, title: str):
        pass
    
    @property
    @bind
    def title(self) -> str:
        """
        Get objects title."""
        pass
