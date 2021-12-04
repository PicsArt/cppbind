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

import examples.inheritance.usage as pybind_usage_pygen
import examples_lib.inheritance.bicycle_pygen as bicycle
import examples_lib.inheritance.parallelogram_pygen as parallelogram
import examples_lib.inheritance.vehicle_pygen as vehicle
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class GeometricFigure(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/inheritance/usage.hpp#L18
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L18>`_
    """
    
    @bind
    def __init__(self, p: parallelogram.Parallelogram):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L25
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L25>`_
        """
        pass
    
    @property
    @bind
    def parallelogram(self) -> parallelogram.Parallelogram:
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L32
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L32>`_
        """
        pass

    @parallelogram.setter
    @bind
    def parallelogram(self, value: parallelogram.Parallelogram):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L32
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L32>`_
        """
        pass


class MyVehicle(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/inheritance/usage.hpp#L56
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L56>`_
    """
    
    @bind
    def __init__(self, v: Vehicle):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L63
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L63>`_
        """
        pass
    
    @property
    @bind
    def vehicle(self) -> Vehicle:
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L70
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L70>`_
        """
        pass

    @vehicle.setter
    @bind
    def vehicle(self, value: Vehicle):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L70
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L70>`_
        """
        pass


class MyBicycle(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/inheritance/usage.hpp#L94
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L94>`_
    """
    
    @bind
    def __init__(self, b: Bicycle):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L101
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L101>`_
        """
        pass
    
    @property
    @bind
    def bicycle(self) -> Bicycle:
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L109
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L109>`_
        """
        pass

    @bicycle.setter
    @bind
    def bicycle(self, value: Bicycle):
        """
        Documentation generated from: `cxx/inheritance/usage.hpp#L109
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/usage.hpp#L109>`_
        """
        pass
