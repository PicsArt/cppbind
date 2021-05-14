from __future__ import annotations
from typing import *
import examples.templates.stack as pybind_stack_pygen
from bind_utils import *
from metaclass import *
from simple import *


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


class StackRoot(metaclass=OriginalMethodsMetaclass):
    """"""
    
    @bind
    def __init__(self):
        pass

    @bind
    def __init__(self, st: Root):
        pass
    
    @bind
    def push(self, item: Root) -> None:
        """"""
        pass

    @bind
    def pop(self) -> None:
        """"""
        pass

    @bind
    def top(self) -> Root:
        """"""
        pass

    @bind
    def empty(self) -> bool:
        """"""
        pass
