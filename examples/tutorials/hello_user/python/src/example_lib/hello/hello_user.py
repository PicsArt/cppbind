"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 06/03/2022-07:09.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import pybind_example_lib.hello.hello_user as pybind_hello_user
from example_lib.cppbind.bind_utils import *
from example_lib.cppbind.metaclass import *


class UserInfo(metaclass=CppBindMetaclass):
    """
    Structure to describe user.
    """
    
    @bind
    def __init__(self, user_name: str, user_age: int):
        """
        Creates user
        """
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
        Some wishes of the user.
        """
        pass

    @want_a_drink.setter
    @bind
    def want_a_drink(self, value: bool):
        """
        Some wishes of the user.
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass


class Host(metaclass=CppBindMetaclass):
    """
    Host class.
    """
    
    @bind
    def __init__(self):
        """
        Creates host
        """
        pass
    
    @bind
    def hello(self, user: UserInfo) -> str:
        """
        Greeting function.
        """
        pass

    @bind
    def welcome(self, user: UserInfo) -> str:
        """
        Welcome function.
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
