"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 06/03/2022-07:13.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.forward_decl.teacher as pybind_teacher_pygen
import examples_lib.forward_decl.student_pygen as student_pygen
from examples_lib.cppbind.bind_utils_pygen import *
from examples_lib.cppbind.metaclass_pygen import *


class Teacher(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/forward_decl/teacher.hpp#L20
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/forward_decl/teacher.hpp#L20>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/forward_decl/teacher.hpp#L27
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/forward_decl/teacher.hpp#L27>`_
        """
        pass
    
    @bind
    def add_student(self, s: student_pygen.Student) -> None:
        """
        Documentation generated from: `cxx/forward_decl/teacher.hpp#L34
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/forward_decl/teacher.hpp#L34>`_
        """
        pass

    @bind
    def students(self) -> List[student_pygen.Student]:
        """
        Documentation generated from: `cxx/forward_decl/teacher.hpp#L43
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/forward_decl/teacher.hpp#L43>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CPPBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
