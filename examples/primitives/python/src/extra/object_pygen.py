from __future__ import annotations
from typing import *
import examples.extra.object as pybind_object_pygen
from bind_utils import *
from metaclass import *


class Object(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    @bind
    def to_string(self) -> str:
        """
        String representation for mainly debug porpoises
        @return class name and object address"""
        pass

    @bind
    def class_name(self) -> str:
        """
        Human readable class name
        @return class name"""
        pass

    @bind
    def equals(self, other: Object) -> bool:
        """
        Compare on equality two objects
        @param other is the second one
        @return is equals two objects"""
        pass

    @bind
    def hash(self) -> int:
        """
        Hash for object. Used in wrappers (java, obj-c, python) to define the hash function
        @return hash of the object"""
        pass

    @bind
    def debug_info(self) -> str:
        """
        Detailed string representation only for debug porpoises
        @return object state as string"""
        pass

    @bind
    def bytes_count(self) -> int:
        """
        The object's size in bytes
        @return bytes count"""
        pass
