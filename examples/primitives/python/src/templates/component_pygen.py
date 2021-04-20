from __future__ import annotations
from typing import *
import examples.templates.component as pybind_component_pygen
from bind_utils import *
from metaclass import *
from templates.addressable_pygen import *

class Component(AddressableRoot, metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    @bind
    def __init__(self, parent: Root, name: str):
        pass


    
    

