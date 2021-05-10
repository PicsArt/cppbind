from __future__ import annotations
from typing import *
import examples.optionals.optionals as pybind_optionals_pygen
from bind_utils import *
from metaclass import *
from classes.task_pygen import *
from enums.color_pygen import *


class Optionals(metaclass=OriginalMethodsMetaclass):
    """"""
    
    @bind
    def __init__(self):
        pass
    
    @bind
    def optional_ptr_with_nullptr_default(self, task: Task = None) -> Task:
        """
        """
        pass

    @bind
    def optional_int_with_default(self, val: int = 5) -> int:
        """"""
        pass

    @bind
    def optional_string_with_default(self, val: str = "abc") -> str:
        """"""
        pass

    @bind
    def optional_char_with_default(self, symbol: str = ',') -> str:
        """"""
        pass

    @bind
    def optional_ptr_with_null_default(self, task: Task = None) -> Task:
        """"""
        pass

    @bind
    def optional_enum_with_default(self, c: Color = Color.Red) -> Color:
        """"""
        pass
