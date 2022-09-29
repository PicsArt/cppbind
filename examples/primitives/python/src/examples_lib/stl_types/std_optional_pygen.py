"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 09/09/2022-15:09.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.stl_types.std_optional as pybind_std_optional_pygen
import examples_lib.enums.color_pygen as enums_color_pygen
import examples_lib.enums.frame_pygen as enums_frame_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


@bind
def mul_int(a: Optional[int], b: int) -> Optional[int]:
    
    pass


@bind
def mul_float(a: Optional[float], b: float) -> Optional[float]:
    
    pass


@bind
def mul_double(a: Optional[float], b: float) -> Optional[float]:
    
    pass


@bind
def mul_short(a: Optional[int], b: int) -> Optional[int]:
    
    pass


@bind
def mul_long(a: Optional[int], b: int) -> Optional[int]:
    
    pass


@bind
def reverse_bool(a: Optional[bool]) -> Optional[bool]:
    
    pass


@bind
def mul_unsigned_int(a: Optional[int], b: int) -> Optional[int]:
    
    pass


@bind
def mul_unsigned_long(a: Optional[int], b: int) -> Optional[int]:
    
    pass


@bind
def mul_long_long(a: Optional[int], b: int) -> Optional[int]:
    
    pass


@bind
def mul_unsigned_char(a: Optional[int], b: int) -> Optional[int]:
    
    pass


@bind
def char_to_upper(a: Optional[str]) -> Optional[str]:
    
    pass


@bind
def concat_string(first: Optional[str], second: str) -> Optional[str]:
    
    pass


@bind
def concat(v: Optional[List[str]], s: str) -> Optional[List[str]]:
    
    pass


@bind
def concat2(v: List[Optional[str]], s: str) -> List[Optional[str]]:
    
    pass


@bind
def same_color(color: Optional[enums_color_pygen.Color]) -> Optional[enums_color_pygen.Color]:
    
    pass


@bind
def same_template_optional_int(a: Optional[int]) -> Optional[int]:
    
    pass


@bind
def same_template_optional_string(a: Optional[str]) -> Optional[str]:
    
    pass


@bind
def same_pair(pair: Optional[Tuple[int, int]]) -> Optional[Tuple[int, int]]:
    
    pass


@bind
def same_map(map: Optional[Dict[int, int]]) -> Optional[Dict[int, int]]:
    
    pass


class FrameUsage(metaclass=CppBindMetaclass):
    
    @bind
    def __init__(self):
        
        pass
    
    @bind
    def same_frame(self, frame: Optional[enums_frame_pygen.Frame]) -> Optional[enums_frame_pygen.Frame]:
        
        pass

    @bind
    def get_frame(self) -> Optional[enums_frame_pygen.Frame]:
        
        pass

    @bind
    def __repr__(self) -> str:
        """
        CppBind generated __repr__ method returning underlying C++ object type and id.
        """
        pass