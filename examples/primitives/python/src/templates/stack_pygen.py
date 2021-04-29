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


class StackTask(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    @bind
    def __init__(self):
        pass

    @bind
    def __init__(self, st: Task):
        pass
    
    @bind
    def push(self, item: Task) -> None:
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
    def top(self) -> Task:
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
