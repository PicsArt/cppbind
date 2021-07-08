"""
Config parser module
"""

import configparser
import os
import sys
import types

from ctypes.util import find_library

import clang.cindex as cli
from iegen.common import PROJECT_CONFIG_DIR

PROJECT_CONFIG = os.path.join(PROJECT_CONFIG_DIR, "iegen_config.cfg")

DEFAULT_DIRS = ['', './', PROJECT_CONFIG_DIR]

clang_lib = find_library('clang-12') or find_library('clang-9') or find_library('clang-6')

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

    with open(config_file) as file:
        config.read_file(file)

    return config


class IEGConfig:
    """
    Loads IEG config file into structure
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

        self.logging = types.SimpleNamespace()
        self.logging.__dict__.update(cnfg.items("LOG"))

    def __repr__(self):
        return f"IEG_Config({repr(self.__dict__)})"


config = IEGConfig(["~/iegen_config.cfg", "iegen_config.cfg"])
