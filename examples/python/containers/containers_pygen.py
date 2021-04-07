from __future__ import annotations
from typing import *
import iegen.examples.containers.containers as pybind_containers_pygen
from bind_utils import *
from metaclass import *


class Item(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """

    @bind
    def __init__(self, _value: int):
        pass

    @property
    @bind
    def value(self) -> int:
        """
        comments
        """
        pass

    @value.setter
    @bind
    def value(self, value: int):
        """
        comments
        """
        pass


class Containers(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """

    @bind
    def __init__(self):
        pass

    @bind
    def add_string_pair(self, info: tuple) -> None:
        """
        comments
        """
        pass

    @bind
    def add_int_map(self, info: dict) -> None:
        """
        comments
        """
        pass

    @bind
    def add_string_map(self, info: dict) -> None:
        """
        comments
        """
        pass

    @bind
    def add_int_pair(self, info: tuple) -> None:
        """
        comments
        """
        pass

    @bind
    def get_string_pair(self) -> tuple:
        """
        comments
        """
        pass

    @bind
    def get_string_map(self) -> dict:
        """
        comments
        """
        pass

    @bind
    def get_int_map(self) -> dict:
        """
        comments
        """
        pass

    @bind
    def get_map(self) -> dict:
        """
        comments
        """
        pass

    @bind
    def add_int_vector(self, v: list) -> None:
        """
        comments
        """
        pass

    @bind
    def add_string_vector(self, v: list) -> None:
        """
        comments
        """
        pass

    @bind
    def get_string_vector(self) -> list:
        """
        comments
        """
        pass

    @bind
    def get_int_vector(self) -> list:
        """
        comments
        """
        pass
