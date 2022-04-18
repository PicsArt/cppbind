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

import examples.templates.template_methods as pybind_template_methods_pygen
import examples_lib.simple.project_pygen as simple_project_pygen
import examples_lib.simple.root_pygen as simple_root_pygen
from examples_lib.iegen.bind_utils_pygen import *
from examples_lib.iegen.metaclass_pygen import *


class TemplateMethods(metaclass=IEGenMetaclass):
    """
    Documentation generated from: `cxx/templates/template_methods.hpp#L14
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L14>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L21
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L21>`_
        """
        pass
    
    @bind
    def max(self, a: int, b: int) -> int:
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L32
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L32>`_
        """
        pass

    @bind
    def max(self, a: str, b: str) -> str:
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L32
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L32>`_
        """
        pass

    @bind
    def make_pair(self, a: simple_project_pygen.Project, b: simple_project_pygen.Project) -> Tuple[simple_project_pygen.Project, simple_project_pygen.Project]:
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L49
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L49>`_
        """
        pass

    @bind
    def make_pair(self, a: simple_root_pygen.Root, b: simple_project_pygen.Project) -> Tuple[simple_root_pygen.Root, simple_project_pygen.Project]:
        """
        Documentation generated from: `cxx/templates/template_methods.hpp#L49
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/template_methods.hpp#L49>`_
        """
        pass
