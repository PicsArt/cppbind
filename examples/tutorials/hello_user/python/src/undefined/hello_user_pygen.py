from __future__ import annotations
from typing import *
import examples.undefined.hello_user as pybind_hello_user_pygen
from metaclass import *
from bind_utils import *


class UserInfo(metaclass=OriginalMethodsMetaclass):
    """
    Structure to describe user."""
    @bind
    def __init__(self, user_name: str, user_age: int):
        pass


    @property
    @bind
    def age(self) -> int:
        """
        Age of user.
        """
        pass

    @property
    @bind
    def name(self) -> str:
        """
        Name of user.
        """
        pass

    @property
    @bind
    def want_a_drink(self) -> bool:
        """
        Some wishes of the user."""
        pass

    @want_a_drink.setter
    @bind
    def want_a_drink(self, value: bool):
        """
        Some wishes of the user."""
        pass
    


class Host(metaclass=OriginalMethodsMetaclass):
    """
    Host class."""
    @bind
    def __init__(self):
        pass


    
    @bind
    def hello(self, user: UserInfo) -> str:
        """
        Greeting function."""
        pass
    @bind
    def welcome(self, user: UserInfo) -> str:
        """
        Welcome function."""
        pass

