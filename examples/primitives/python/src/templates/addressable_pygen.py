"""
This file was generated by iegen on 05/18/2021-20:19.
Please do not change it manually.
"""

from __future__ import annotations

from typing import *

import examples.templates.addressable as pybind_addressable_pygen
from bind_utils import *
from metaclass import *
from simple.root_pygen import *


class AddressableRoot(metaclass=OriginalMethodsMetaclass):
    """
    Addressable is a base class for all the objects, that have abs path."""
    
    @bind
    def __init__(self, parent: Root, name: str):
        pass
    
    @bind
    def abs_path(self) -> str:
        """
        comments
        @brief Get object's abs path based on parent's abs path and object's name
        @return the abs path of the object"""
        pass