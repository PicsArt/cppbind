from __future__ import annotations
from typing import *
import examples.templates.stack_usage as pybind_stack_usage_pygen
from bind_utils import *
from metaclass import *
from templates.stack_pygen import *
from classes.projecr_pygen import *

class TemplateUsage(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    @bind
    def __init__(self):
        pass


    
    @bind
    def max(self, arg0: int, arg1: int) -> int:
        """
        comments
        """
        pass
    @bind
    def max(self, arg0: str, arg1: str) -> str:
        """
        comments
        """
        pass
    @bind
    def usage1(self, p: StackProject) -> Project:
        """
        comments
        """
        pass
    @bind
    def usage2(self, arg0: StackProject) -> Project:
        """
        comments
        """
        pass
    @bind
    def usage4(self, arg0: Project) -> None:
        """
        comments
        """
        pass

