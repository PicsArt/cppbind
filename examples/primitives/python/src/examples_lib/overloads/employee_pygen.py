"""
,--.,------. ,----.   ,------.,--.  ,--.
|  ||  .---''  .-.|   |  .---'|  ,'.|  |
|  ||  `--, |  | .---.|  `--, |  |' '  |
|  ||  `---.'  '--'  ||  `---.|  | `   |
`--'`------' `------' `------'`--'  `--'

This file is generated by iegen on 12/06/2021-12:08.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.overloads.employee as pybind_employee_pygen
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class Employee(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/overloads/employee.hpp#L15
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/employee.hpp#L15>`_
    """
    
    @bind
    def __init__(self, name: str):
        """
        Documentation generated from: `cxx/overloads/employee.hpp#L22
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/employee.hpp#L22>`_
        """
        pass

    @bind
    def __init__(self, age: int, email: str = ""):
        """
        Documentation generated from: `cxx/overloads/employee.hpp#L29
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/employee.hpp#L29>`_
        """
        pass
    
    @property
    @bind
    def name(self) -> str:
        """
        Documentation generated from: `cxx/overloads/employee.hpp#L57
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/employee.hpp#L57>`_
        """
        pass

    @property
    @bind
    def email(self) -> str:
        """
        Documentation generated from: `cxx/overloads/employee.hpp#L66
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/employee.hpp#L66>`_
        """
        pass

    @property
    @bind
    def age(self) -> int:
        """
        Documentation generated from: `cxx/overloads/employee.hpp#L75
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/employee.hpp#L75>`_
        """
        pass
    
    @bind
    def set_data(self, name: str, age: int, email: str = "") -> None:
        """
        Documentation generated from: `cxx/overloads/employee.hpp#L37
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/employee.hpp#L37>`_
        """
        pass

    @bind
    def set_data(self, age: int) -> None:
        """
        Documentation generated from: `cxx/overloads/employee.hpp#L48
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/overloads/employee.hpp#L48>`_
        """
        pass
