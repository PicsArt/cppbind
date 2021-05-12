from __future__ import annotations
from typing import *
import examples.templates.stack as pybind_stack_pygen
from bind_utils import *
from metaclass import *
from classes.project_pygen import *
from classes.task_pygen import *


class StackProject(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    @bind
    def __init__(self):
        pass

    @bind
    def __init__(self, st: Project):
        pass
    
    @bind
    def push(self, item: Project) -> None:
        """
        comments
        """
        pass

    @bind
    def pop(self) -> None:
        """
        comments
        """
        pass

    @bind
    def top(self) -> Project:
        """
        comments
        """
        pass

    @bind
    def empty(self) -> bool:
        """
        comments
        """
        pass


class StackPyTask(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    @bind
    def __init__(self):
        pass

    @bind
    def __init__(self, st: PyTask):
        pass
    
    @bind
    def push(self, item: PyTask) -> None:
        """
        comments
        """
        pass

    @bind
    def pop(self) -> None:
        """
        comments
        """
        pass

    @bind
    def top(self) -> PyTask:
        """
        comments
        """
        pass

    @bind
    def empty(self) -> bool:
        """
        comments
        """
        pass
