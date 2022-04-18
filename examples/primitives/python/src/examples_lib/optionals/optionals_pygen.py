"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 04/12/2022-12:19.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.optionals.optionals as pybind_optionals_pygen
import examples_lib.enums.color_pygen as enums_color_pygen
import examples_lib.getters.person_pygen as getters_person_pygen
import examples_lib.simple.project_pygen as simple_project_pygen
import examples_lib.simple.root_pygen as simple_root_pygen
import examples_lib.simple.task.task_pygen as simple_task_task_pygen
from examples_lib.iegen.bind_utils_pygen import *
from examples_lib.iegen.metaclass_pygen import *


class Optionals(metaclass=IEGenMetaclass):
    """
    Documentation generated from: `cxx/optionals/optionals.hpp#L23
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L23>`_
    """
    
    @bind
    def __init__(self, task: simple_task_task_pygen.PyTask = None, i: int = 1, r: simple_root_pygen.Root = None):
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L159
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L159>`_
        """
        pass
    
    @bind
    def optional_ptr_with_nullptr_default(self, task: Optional[simple_task_task_pygen.PyTask] = None) -> Optional[simple_task_task_pygen.PyTask]:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L33
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L33>`_
        """
        pass

    @bind
    def optional_ptr_with_null_default(self, task: Optional[simple_task_task_pygen.PyTask] = None) -> Optional[simple_task_task_pygen.PyTask]:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L44
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L44>`_
        """
        pass

    @bind
    def optional_int_with_default(self, value: int = 5) -> int:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L53
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L53>`_
        """
        pass

    @bind
    def optional_long_with_default(self, value: int = 7) -> int:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L62
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L62>`_
        """
        pass

    @bind
    def optional_double_with_default(self, value: float = 9.0) -> float:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L71
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L71>`_
        """
        pass

    @bind
    def optional_float_with_default(self, value: float = 11.0) -> float:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L80
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L80>`_
        """
        pass

    @bind
    def optional_bool_with_default(self, value: bool = True) -> bool:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L89
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L89>`_
        """
        pass

    @bind
    def optional_string_with_default(self, optional_str: str = "abc") -> str:
        """
        @param[in] optional_str string with default value
        Documentation generated from: `cxx/optionals/optionals.hpp#L99
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L99>`_
        """
        pass

    @bind
    def optional_char_with_default(self, symbol: str = ',') -> str:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L111
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L111>`_
        """
        pass

    @bind
    def optional_char_pointer_with_default(self, optional_str: str = "def") -> str:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L120
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L120>`_
        """
        pass

    @bind
    def optional_enum_with_default(self, c: enums_color_pygen.Color = enums_color_pygen.Color.Red) -> enums_color_pygen.Color:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L129
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L129>`_
        """
        pass

    @bind
    def single_complex_default_value(self, task: simple_task_task_pygen.PyTask = None) -> simple_task_task_pygen.PyTask:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L141
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L141>`_
        """
        pass

    @bind
    def multiple_mixed_default_values(self, task: simple_task_task_pygen.PyTask = None, i: int = 1, r: simple_root_pygen.Root = None) -> str:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L150
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L150>`_
        """
        pass

    @bind
    def optional_enum_with_default_and_field_prefix(self, c: enums_color_pygen.ColorShade = enums_color_pygen.ColorShade.ShadeLight) -> enums_color_pygen.ColorShade:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L170
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L170>`_
        """
        pass

    @bind
    def optional_enum_with_internal_default(self, c: enums_color_pygen.ColorShade) -> enums_color_pygen.ColorShade:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L179
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L179>`_
        """
        pass

    @bind
    def optional_string_view_with_default(self, optional_str: str = "abc") -> str:
        """
        @param[in] optional_str string with default value
        Documentation generated from: `cxx/optionals/optionals.hpp#L189
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L189>`_
        """
        pass

    @bind
    def optional_f_d_ptr_with_nullptr_default(self, project: Optional[simple_project_pygen.Project] = None) -> Optional[simple_project_pygen.Project]:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L200
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L200>`_
        """
        pass

    @bind
    def optional_shared_ptr_with_nullptr_default(self, person: Optional[getters_person_pygen.Person] = None) -> Optional[getters_person_pygen.Person]:
        """
        Documentation generated from: `cxx/optionals/optionals.hpp#L210
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/optionals/optionals.hpp#L210>`_
        """
        pass
