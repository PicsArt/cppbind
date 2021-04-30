from __future__ import annotations
from typing import *
import examples.simple.project as pybind_project_pygen
from bind_utils import *
from metaclass import *
from simple.task_pygen import *


class Project(metaclass=OriginalMethodsMetaclass):
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
    
    @bind
    def add_task(self, task: Task) -> None:
        """
        comments
        """
        pass

    @bind
    def tasks(self) -> list:
        """
        comments
        """
        pass
