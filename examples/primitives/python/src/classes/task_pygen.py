from __future__ import annotations
from typing import *
import examples.classes.task as pybind_task_pygen
from metaclass import *
from bind_utils import *


class Task(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    @bind
    def __init__(self, title: str):
        pass


    @property
    @bind
    def title(self) -> str:
        """
        comments
        """
        pass



    

