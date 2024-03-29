"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 08/11/2022-07:34.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.enums.logging as pybind_logging_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *


class LogLevel(metaclass=CppBindEnumMetaclass):
    
    DEBUG = pybind_logging_pygen.LogLevel.DEBUG
    log_info_level = pybind_logging_pygen.LogLevel.log_info_level
    WARNING = pybind_logging_pygen.LogLevel.WARNING
    ERROR = pybind_logging_pygen.LogLevel.ERROR
    LOG_CRITICAL = pybind_logging_pygen.LogLevel.LOG_CRITICAL

    def __int__(self):
        return self.value


@bind
def get_next_log_level(log_level: LogLevel) -> LogLevel:
    
    pass
