"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 12/07/2021-12:30.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.templates.pair as pybind_pair_pygen
import examples_lib.forward_decl.student_pygen as student
import examples_lib.overloads.employee_pygen as employee
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class PairEmployee(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/templates/pair.hpp#L25
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/pair.hpp#L25>`_
    """
    
    @bind
    def __init__(self, first: str, second: Employee):
        """
        Documentation generated from: `cxx/templates/pair.hpp#L34
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/pair.hpp#L34>`_
        """
        pass
    
    @property
    @bind
    def first(self) -> str:
        """
        Documentation generated from: `cxx/templates/pair.hpp#L41
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/pair.hpp#L41>`_
        """
        pass

    @property
    @bind
    def second(self) -> Employee:
        """
        Documentation generated from: `cxx/templates/pair.hpp#L50
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/pair.hpp#L50>`_
        """
        pass


class PairStudent(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/templates/pair.hpp#L25
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/pair.hpp#L25>`_
    """
    
    @bind
    def __init__(self, first: str, second: Student):
        """
        Documentation generated from: `cxx/templates/pair.hpp#L34
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/pair.hpp#L34>`_
        """
        pass
    
    @property
    @bind
    def first(self) -> str:
        """
        Documentation generated from: `cxx/templates/pair.hpp#L41
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/pair.hpp#L41>`_
        """
        pass

    @property
    @bind
    def second(self) -> Student:
        """
        Documentation generated from: `cxx/templates/pair.hpp#L50
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/pair.hpp#L50>`_
        """
        pass
