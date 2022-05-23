# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Config parser module
"""

import configparser
import os
import sys
import types

from ctypes.util import find_library

import clang.cindex as cli
from cppbind.common import PROJECT_CONFIG_DIR
from .error import Error

PROJECT_CONFIG = os.path.join(PROJECT_CONFIG_DIR, "cppbind_config.cfg")

DEFAULT_DIRS = ['', './', PROJECT_CONFIG_DIR]

# find clang for windows and mac
clang_lib = find_library('libclang')

# find clang for linux
if clang_lib is None:
    for version in range(13, 5, -1):
        clang_lib = find_library(f'clang-{version}')
        if clang_lib:
            break

if clang_lib is None:
    print("clang dev is not installed. Please read README.md")
    sys.exit(1)

# setting clang library file.
# in feature we might  consider to have path optionally defined in config
cli.Config.set_library_file(clang_lib)


def read_config(config_file=None):
    """
    creates and loads config file.
    Args:
        config_file: default config file
    """
    config_file = config_file or PROJECT_CONFIG

    config = configparser.ConfigParser(
        converters={
            'list': lambda x: [i.strip() for i in x.split(',')]
        }
    )

    try:
        with open(config_file) as file:
            config.read_file(file)
    except OSError as err:
        Error.critical(f"Cannot read config file {config_file}: {err}")

    return config


class CppBindConfig:
    """
    Loads cppbind config file into structure
    """

    def __init__(self, file_names=None):
        """
        initializes config

        loads default config as well as config provided by user
        Args:
            file_names: list of file names that is going to be loaded
        """

        cnfg = read_config()

        if file_names is not None:
            cnfg.read(file_names)

        self.application = types.SimpleNamespace(**dict(cnfg.items('APPLICATION')))

        self.default_config_dirs = DEFAULT_DIRS

        self.languages = cnfg.getlist("APPLICATION", "all_languages")
        self.platforms = cnfg.getlist("APPLICATION", "all_platforms")

        self.api_start_kw = cnfg.get("API", "parser_start")

        self.logging = types.SimpleNamespace(**dict(cnfg.items("LOG")))

    def __repr__(self):
        return f"CppBind_Config({repr(self.__dict__)})"


config = CppBindConfig(["~/cppbind_config.cfg", "cppbind_config.cfg"])
