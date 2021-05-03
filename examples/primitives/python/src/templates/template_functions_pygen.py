from __future__ import annotations
from typing import *
import examples.templates.template_functions as pybind_template_functions_pygen
from bind_utils import *
from metaclass import *
from classes.project_pygen import *
from classes.task_pygen import *


class TemplateFunctions(metaclass=OriginalMethodsMetaclass):
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
    def make_pair(self, arg0: Project, arg1: Project) -> tuple:
        """
        comments
        """
        pass

    @bind
    def make_pair(self, arg0: Task, arg1: Project) -> tuple:
        """
        comments
        """
        pass
