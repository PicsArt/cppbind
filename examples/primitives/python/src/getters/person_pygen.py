from __future__ import annotations
from typing import *
import examples.getters.person as pybind_person_pygen
from bind_utils import *
from metaclass import *


class Person(metaclass=OriginalMethodsMetaclass):
    """
    This class contains a private string field and getter/setter methods for it."""
    @bind
    def __init__(self, name: str):
        pass


    @property
    @bind
    def full_name(self) -> str:
        """
        fullname getter"""
        pass

    @full_name.setter
    @bind
    def full_name(self, value: str):
        """
        fullname getter"""
        pass


    

