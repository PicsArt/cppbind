from __future__ import annotations
from typing import *
import examples.templates.stack as pybind_stack_pygen
from bind_utils import *
from metaclass import *
from simple.project_pygen import *
from simple.task_pygen import *


class StackProject(metaclass=OriginalMethodsMetaclass):
    """"""
    
    @bind
    def __init__(self):
        pass

    @bind
    def __init__(self, st: Project):
        pass
    
    @bind
    def push(self, item: Project) -> None:
        """"""
        pass

    @bind
    def pop(self) -> None:
        """"""
        pass

    @bind
    def top(self) -> Project:
        """"""
        pass

    @bind
    def empty(self) -> bool:
        """"""
        pass


class StackTask(metaclass=OriginalMethodsMetaclass):
    """"""
    
    @bind
    def __init__(self):
        pass

    @bind
    def __init__(self, st: Task):
        pass
    
    @bind
    def push(self, item: Task) -> None:
        """"""
        pass

    @bind
    def pop(self) -> None:
        """"""
        pass

    @bind
    def top(self) -> Task:
        """"""
        pass

    @bind
    def empty(self) -> bool:
        """"""
        pass
