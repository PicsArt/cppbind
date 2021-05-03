from __future__ import annotations
from typing import *
import examples.templates.stack_usage as pybind_stack_usage_pygen
from bind_utils import *
from metaclass import *
from templates.stack_pygen import *
from classes.project_pygen import *


class StackUsage(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    @bind
    def __init__(self):
        pass
    
    @bind
    def first_item_of_specialized(self, p: StackProject) -> Project:
        """
        comments
        """
        pass

    @bind
    def first_item_of_template(self, arg0: StackProject) -> Project:
        """
        comments
        """
        pass
