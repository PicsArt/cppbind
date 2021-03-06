"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 06/20/2022-07:57.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.optionals.optionals as pybind_optionals_pygen
import examples_lib.enums.color_pygen as enums_color_pygen
import examples_lib.enums.logging_pygen as enums_logging_pygen
import examples_lib.getters.person_pygen as getters_person_pygen
import examples_lib.simple.project_pygen as simple_project_pygen
import examples_lib.simple.root_pygen as simple_root_pygen
import examples_lib.simple.task.task_pygen as simple_task_task_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class Optionals(metaclass=CppBindMetaclass):
    """
    Documentation generated from: `cxx/optionals/optionals.hpp#L26
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L26>`_
    """
    
    @bind
    def __init__(self, task: simple_task_task_pygen.PyTask = None, i: int = 1, r: simple_root_pygen.Root = None):
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L177
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L177>`_
        """
        pass
    
    @bind
    def optional_ptr_with_nullptr_default(self, task: Optional[simple_task_task_pygen.PyTask] = None) -> Optional[simple_task_task_pygen.PyTask]:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L36
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L36>`_
        """
        pass

    @bind
    def optional_ptr_with_null_default(self, task: Optional[simple_task_task_pygen.PyTask] = None) -> Optional[simple_task_task_pygen.PyTask]:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L47
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L47>`_
        """
        pass

    @bind
    def optional_int_with_default(self, value: int = 5) -> int:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L56
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L56>`_
        """
        pass

    @bind
    def optional_long_with_default(self, value: int = 7) -> int:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L65
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L65>`_
        """
        pass

    @bind
    def optional_double_with_default(self, value: float = 9.0) -> float:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L74
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L74>`_
        """
        pass

    @bind
    def optional_float_with_default(self, value: float = 11.0) -> float:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L83
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L83>`_
        """
        pass

    @bind
    def optional_bool_with_default(self, value: bool = True) -> bool:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L92
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L92>`_
        """
        pass

    @bind
    def optional_string_with_default(self, optional_str: str = "abc") -> str:
        """
        @param[in] optional_str string with default value
        Documentation generated from: `cxx/optionals/optionals.hpp#L102
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L102>`_
        """
        pass

    @bind
    def optional_char_with_default(self, symbol: str = ',') -> str:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L111
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L111>`_
        """
        pass

    @bind
    def optional_unsigned_char_with_default(self, num: int = 100) -> int:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L120
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L120>`_
        """
        pass

    @bind
    def optional_char_pointer_with_default(self, optional_str: str = "def") -> str:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L129
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L129>`_
        """
        pass

    @bind
    def optional_enum_with_default(self, c: enums_color_pygen.Color = enums_color_pygen.Color.Red) -> enums_color_pygen.Color:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L138
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L138>`_
        """
        pass

    @bind
    def optional_enum_with_default_and_changed_names(self, level: enums_logging_pygen.LogLevel = enums_logging_pygen.LogLevel.WARNING) -> enums_logging_pygen.LogLevel:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L147
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L147>`_
        """
        pass

    @bind
    def single_complex_default_value(self, task: simple_task_task_pygen.PyTask = None) -> simple_task_task_pygen.PyTask:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L159
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L159>`_
        """
        pass

    @bind
    def multiple_mixed_default_values(self, task: simple_task_task_pygen.PyTask = None, i: int = 1, r: simple_root_pygen.Root = None) -> str:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L168
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L168>`_
        """
        pass

    @bind
    def optional_enum_with_default_and_field_prefix(self, c: enums_color_pygen.ColorShade = enums_color_pygen.ColorShade.ShadeLight) -> enums_color_pygen.ColorShade:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L188
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L188>`_
        """
        pass

    @bind
    def optional_enum_with_internal_default(self, c: enums_color_pygen.ColorShade) -> enums_color_pygen.ColorShade:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L197
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L197>`_
        """
        pass

    @bind
    def optional_string_view_with_default(self, optional_str: str = "abc") -> str:
        """
        @param[in] optional_str string with default value
        Documentation generated from: `cxx/optionals/optionals.hpp#L207
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L207>`_
        """
        pass

    @bind
    def optional_f_d_ptr_with_nullptr_default(self, project: Optional[simple_project_pygen.Project] = None) -> Optional[simple_project_pygen.Project]:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L218
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L218>`_
        """
        pass

    @bind
    def optional_shared_ptr_with_nullptr_default(self, person: Optional[getters_person_pygen.Person] = None) -> Optional[getters_person_pygen.Person]:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L228
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L228>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
