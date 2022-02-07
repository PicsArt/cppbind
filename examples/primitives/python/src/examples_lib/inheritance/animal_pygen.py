"""
,--.,------. ,----.   ,------.,--.  ,--. 
|  ||  .---''  .-.|   |  .---'|  ,'.|  | 
|  ||  `--, |  | .---.|  `--, |  |' '  | 
|  ||  `---.'  '--'  ||  `---.|  | `   | 
`--'`------' `------' `------'`--'  `--' 

This file is generated by iegen on 02/04/2022-12:39.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.inheritance.animal as pybind_animal_pygen
from examples_lib.iegen.bind_utils_pygen import *
from examples_lib.iegen.metaclass_pygen import *


class Animal(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/inheritance/animal.hpp#L26
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L26>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L33
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L33>`_
        """
        pass
    
    @bind
    def type_name(self) -> str:
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L40
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L40>`_
        """
        pass


class TerrestrialAnimal(Animal, metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/inheritance/animal.hpp#L50
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L50>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L57
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L57>`_
        """
        pass
    
    @bind
    def type_name(self) -> str:
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L64
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L64>`_
        """
        pass


class AquaticAnimal(Animal, metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/inheritance/animal.hpp#L74
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L74>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L81
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L81>`_
        """
        pass
    
    @bind
    def type_name(self) -> str:
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L88
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L88>`_
        """
        pass


class Frog(TerrestrialAnimal, AquaticAnimal, metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/inheritance/animal.hpp#L99
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L99>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L106
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L106>`_
        """
        pass
    
    @bind
    def type_name(self) -> str:
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L113
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L113>`_
        """
        pass


class LittleFrog(Frog, metaclass=OriginalMethodsMetaclass):
    """
    Class to help checking the empty case of descendants list
    Documentation generated from: `cxx/inheritance/animal.hpp#L124
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L124>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L131
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L131>`_
        """
        pass


class AnimalUsage(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/inheritance/animal.hpp#L139
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L139>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L146
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L146>`_
        """
        pass

    @bind
    def __init__(self, little_frog: LittleFrog):
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L153
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L153>`_
        """
        pass
    
    @classmethod
    @bind
    def get_animal_type_name(cls, animal: Animal) -> str:
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L160
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L160>`_
        """
        pass

    @classmethod
    @bind
    def get_aquatic_animal_type_name(cls, animal: AquaticAnimal) -> str:
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L169
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L169>`_
        """
        pass

    @bind
    def get_animal(self) -> Animal:
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L178
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L178>`_
        """
        pass

    @bind
    def get_aquatic_animal(self) -> AquaticAnimal:
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L187
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L187>`_
        """
        pass

    @bind
    def get_frog(self) -> Frog:
        """
        Documentation generated from: `cxx/inheritance/animal.hpp#L196
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L196>`_
        """
        pass

    @bind
    def get_little_frog(self) -> Frog:
        """
        Method to check that any downcast is not done when descendants=[]
        Documentation generated from: `cxx/inheritance/animal.hpp#L206
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/inheritance/animal.hpp#L206>`_
        """
        pass
