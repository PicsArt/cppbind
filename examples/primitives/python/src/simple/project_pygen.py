from __future__ import annotations
from typing import *
import examples.simple.project as pybind_project_pygen
from bind_utils import *
from metaclass import *
from simple.task_pygen import *


class Project(metaclass=OriginalMethodsMetaclass):
    """
    Class holding project information."""
    
    @bind
    def __init__(self, title: str):
        pass
    
    @property
    @bind
    def title(self) -> str:
        """
        Get project´s title."""
        pass
    
    @bind
    def add_task(self, task: Task) -> None:
        """
        Add a task to project."""
        pass

    @bind
    def tasks(self) -> list:
        """
        Get project´s tasks."""
        pass
