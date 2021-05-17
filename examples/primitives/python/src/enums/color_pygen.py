from __future__ import annotations
from typing import *
import examples.enums.color as pybind_color_pygen
from bind_utils import *
from metaclass import *


class Color(pybind_color_pygen.Color):
    """
    Color Enum."""
    # Red = 1
    Red = pybind_color_pygen.Color.Red
    # Green = 1
    Green = pybind_color_pygen.Color.Green
    # Blue = 20
    Blue = pybind_color_pygen.Color.Blue
