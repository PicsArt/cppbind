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

import examples.functionals.functional_example as pybind_functional_example_pygen
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class FunctionalExamples(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/functionals/functional_example.hpp#L13
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/functionals/functional_example.hpp#L13>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/functionals/functional_example.hpp#L19
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/functionals/functional_example.hpp#L19>`_
        """
        pass
    
    @classmethod
    @bind
    def gen_func_to_increment_result(cls, f: Callable[[int], int]) -> Callable[[int], int]:
        """
        Documentation generated from: `cxx/functionals/functional_example.hpp#L26
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/functionals/functional_example.hpp#L26>`_
        """
        pass
