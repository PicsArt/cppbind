"""
Module contains common fixtures used in iegen related tests
"""
import copy
import pytest
import os
import yaml

from unittest.mock import Mock

from iegen import PROJECT_CONFIG_DIR
from iegen.common.config import config as default_config
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


def get_parser_config(config):
    """
    Fixture returns ieg parser config for test.
    """
    return config.languages['kotlin']


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
    return get_parser_config(config)


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
    return {
        'clang_args': ['-D__ANDROID__'],
        'include_dirs': ['.'],
        'src_glob': [TEST_CXX_DIR + '/*.h'],
        'src_exclude_glob': []
    }


ContextDescriptor.get_var_def = Mock(return_value=yaml.load(open(os.path.join(PROJECT_CONFIG_DIR, "variable_definitions.yaml")), Loader=yaml.SafeLoader))