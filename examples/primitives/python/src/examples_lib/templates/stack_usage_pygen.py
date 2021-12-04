"""
,--.,------. ,----.   ,------.,--.  ,--.
|  ||  .---''  .-.|   |  .---'|  ,'.|  |
|  ||  `--, |  | .---.|  `--, |  |' '  |
|  ||  `---.'  '--'  ||  `---.|  | `   |
`--'`------' `------' `------'`--'  `--'

This file is generated by iegen on 12/04/2021-12:25.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.templates.stack_usage as pybind_stack_usage_pygen
import examples_lib.simple.project_pygen as project
import examples_lib.templates.stack_pygen as stack
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class StackUsage(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/templates/stack_usage.hpp#L19
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/stack_usage.hpp#L19>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/templates/stack_usage.hpp#L25
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/stack_usage.hpp#L25>`_
        """
        pass
    
    @bind
    def first_item_of_specialized_stack(self, p: stack.StackPrj) -> project.Project:
        """
        Documentation generated from: `cxx/templates/stack_usage.hpp#L32
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/stack_usage.hpp#L32>`_
        """
        pass

    @bind
    def first_item_of_template_stack(self, arg0: stack.StackPrj) -> project.Project:
        """
        Documentation generated from: `cxx/templates/stack_usage.hpp#L44
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/templates/stack_usage.hpp#L44>`_
        """
        pass
