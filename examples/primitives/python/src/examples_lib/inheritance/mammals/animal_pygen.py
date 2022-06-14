"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 06/09/2022-13:25.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.inheritance.mammals.animal as pybind_animal_pygen
import examples_lib.inheritance.animal_pygen as animal_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class Mammals(metaclass=CppBindMetaclass):
    """
    Class to check generated imports for descendants list for kotlin in case of nested types (also for interface types)
    Documentation generated from: `cxx/inheritance/animal.hpp#L134
    <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L134>`_
    """
    

    class Dolphin(animal_pygen.AquaticAnimal, metaclass=CppBindMetaclass):
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L142
        <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L142>`_
        """
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass
