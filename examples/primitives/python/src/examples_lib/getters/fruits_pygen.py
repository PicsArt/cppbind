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

from abc import abstractmethod
from typing import *

import examples.getters.fruits as pybind_fruits_pygen
from examples_lib.iegen.bind_utils import *
from examples_lib.iegen.metaclass import *


class FruitType(metaclass=EnumMetaclass):
    """
    Documentation generated from: `cxx/getters/fruits.hpp#L16
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L16>`_
    """
    Apple = pybind_fruits_pygen.FruitType.Apple
    Pineapple = pybind_fruits_pygen.FruitType.Pineapple

    def __int__(self):
        return self.value


class Fruit(metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/getters/fruits.hpp#L27
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L27>`_
    """
    @abstractmethod
    def __init__(self, *args, **kwargs):
        pass
    
    @property
    @bind
    def type(self) -> FruitType:
        """
        Documentation generated from: `cxx/getters/fruits.hpp#L36
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L36>`_
        """
        pass


class Apple(Fruit, metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/getters/fruits.hpp#L47
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L47>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/getters/fruits.hpp#L54
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L54>`_
        """
        pass
    
    @property
    @bind
    def type(self) -> FruitType:
        """
        Documentation generated from: `cxx/getters/fruits.hpp#L61
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L61>`_
        """
        pass


class Pineapple(Fruit, metaclass=OriginalMethodsMetaclass):
    """
    Documentation generated from: `cxx/getters/fruits.hpp#L73
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L73>`_
    """
    
    @bind
    def __init__(self):
        """
        Documentation generated from: `cxx/getters/fruits.hpp#L80
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L80>`_
        """
        pass
    
    @property
    @bind
    def type(self) -> FruitType:
        """
        Documentation generated from: `cxx/getters/fruits.hpp#L87
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L87>`_
        """
        pass


class Fruits(metaclass=OriginalMethodsMetaclass):
    """
    An example class containing template getters.
    Documentation generated from: `cxx/getters/fruits.hpp#L100
    <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L100>`_
    """
    
    @bind
    def __init__(self, fruits: List[Fruit]):
        """
        Documentation generated from: `cxx/getters/fruits.hpp#L107
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L107>`_
        """
        pass
    
    @property
    @bind
    def apples(self) -> List[Apple]:
        """
        Documentation generated from: `cxx/getters/fruits.hpp#L120
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L120>`_
        """
        pass

    @property
    @bind
    def pineapple(self) -> List[Pineapple]:
        """
        Documentation generated from: `cxx/getters/fruits.hpp#L120
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L120>`_
        """
        pass

    @property
    @bind
    def apples_with_pineapples(self) -> List[Fruit]:
        """
        Documentation generated from: `cxx/getters/fruits.hpp#L143
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L143>`_
        """
        pass

    @apples_with_pineapples.setter
    @bind
    def apples_with_pineapples(self, value: List[Fruit]):
        """
        Documentation generated from: `cxx/getters/fruits.hpp#L143
        <https://github.com/PicsArt/iegen/tree/master/examples/primitives/cxx/getters/fruits.hpp#L143>`_
        """
        pass
