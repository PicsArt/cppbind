"""
Module contains common fixtures used in iegen related tests
"""
import copy
import os
import platform

from unittest.mock import Mock
import pytest

from iegen import PROJECT_CONFIG_DIR
from iegen.common.config import config as default_config
from iegen.common.yaml_process import load_yaml
from iegen.context_manager.ctx_desc import ContextDescriptor
from . import TEST_CXX_DIR, TEST_OUT_DIR


def test_dummy():
    pass


@pytest.fixture(autouse=True, scope="session")
def global_setup():
    pass


@pytest.fixture(autouse=True, scope="function")
def local_setup():
    pass


@pytest.fixture(scope="session")
def config():
    """
    Fixture returns ieg config for test.
    """
    cnfg = copy.deepcopy(default_config)

    return cnfg


@pytest.fixture(scope="session")
def parser_config(config):
    """
    Fixture returns ieg parser config for test.
    """
    return config


@pytest.fixture(scope="session")
def out_dir():
    """
    Fixture returns out_dir for test files.
    """
    return TEST_OUT_DIR


@pytest.fixture(scope="session")
def clang_config():
    """
    Fixture returns clang config parameters for test files.
    """
    config = {
        'clang_args': [],
        'include_dirs': ['.'],
        'src_glob': [TEST_CXX_DIR + '/*.h'],
        'src_exclude_glob': [],
        'extra_headers': []
    }

    if platform.system() == 'Darwin':
        config['clang_args'] = [
            '--sysroot=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk'
        ]

    return config


ContextDescriptor.get_var_def = Mock(return_value=ContextDescriptor.resolve_attr_aliases(load_yaml(
    os.path.join(PROJECT_CONFIG_DIR, "variable_definitions.yaml"))))
