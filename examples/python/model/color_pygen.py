from __future__ import annotations
from typing import *
import iegen.examples.model.color as pybind_color_pygen
from bind_utils import *
from metaclass import *


class Color(pybind_color_pygen.Color):
    # Red = 1
    Red = pybind_color_pygen.Color.Red
    # Green = 1
    Green = pybind_color_pygen.Color.Green
    # Blue = 3
    Blue = pybind_color_pygen.Color.Blue
