from __future__ import annotations
from typing import *
import examples.forward_decl.student as pybind_student_pygen
from bind_utils import *
from metaclass import *


class Student(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    @bind
    def __init__(self):
        pass
    
    @bind
    def add_teacher(self, t: Teacher) -> None:
        """"""
        pass

    @bind
    def teachers(self) -> list:
        """"""
        pass
