"""
,--.,------. ,----.   ,------.,--.  ,--.
|  ||  .---''  .-.|   |  .---'|  ,'.|  |
|  ||  `--, |  | .---.|  `--, |  |' '  |
|  ||  `---.'  '--'  ||  `---.|  | `   |
`--'`------' `------' `------'`--'  `--'

This file is generated by iegen on 12/04/2021-12:04.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import hello_user.hello.hello_user as pybind_hello_user
from hello_user.iegen.bind_utils import *
from hello_user.iegen.metaclass import *


class UserInfo(metaclass=OriginalMethodsMetaclass):
    """
    Structure to describe user.
    Documentation generated from: `cxx/hello_user.hpp#L9
    <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user/cxx/hello_user.hpp#L9>`_
    """
    
    @bind
    def __init__(self, user_name: str, user_age: int):
        """
        Creates user
        Documentation generated from: `cxx/hello_user.hpp#L16
        <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user/cxx/hello_user.hpp#L16>`_
        """
        pass
    
    @property
    @bind
    def age(self) -> int:
        """
        Age of user.
        Documentation generated from: `cxx/hello_user.hpp#L22
        <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user/cxx/hello_user.hpp#L22>`_
        """
        pass


    @property
    @bind
    def name(self) -> str:
        """
        Name of user.
        Documentation generated from: `cxx/hello_user.hpp#L28
        <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user/cxx/hello_user.hpp#L28>`_
        """
        pass


    @property
    @bind
    def want_a_drink(self) -> bool:
        """
        Some wishes of the user.
        Documentation generated from: `cxx/hello_user.hpp#L34
        <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user/cxx/hello_user.hpp#L34>`_
        """
        pass

    @want_a_drink.setter
    @bind
    def want_a_drink(self, value: bool):
        """
        Some wishes of the user.
        Documentation generated from: `cxx/hello_user.hpp#L34
        <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user/cxx/hello_user.hpp#L34>`_
        """
        pass


class Host(metaclass=OriginalMethodsMetaclass):
    """
    Host class.
    Documentation generated from: `cxx/hello_user.hpp#L43
    <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user/cxx/hello_user.hpp#L43>`_
    """
    
    @bind
    def __init__(self):
        """
        Creates host
        Documentation generated from: `cxx/hello_user.hpp#L50
        <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user/cxx/hello_user.hpp#L50>`_
        """
        pass
    
    @bind
    def hello(self, user: UserInfo) -> str:
        """
        Greeting function.
        Documentation generated from: `cxx/hello_user.hpp#L57
        <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user/cxx/hello_user.hpp#L57>`_
        """
        pass

    @bind
    def welcome(self, user: UserInfo) -> str:
        """
        Welcome function.
        Documentation generated from: `cxx/hello_user.hpp#L66
        <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user/cxx/hello_user.hpp#L66>`_
        """
        pass
