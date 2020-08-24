"""
Module contains common fixtures used in iegnen related tests
"""
import copy

import pytest
from iegnen.common.config import config as default_config
from . import TEST_CXX_DIR


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
    cnfg.parser.source_dir = TEST_CXX_DIR

    return cnfg


@pytest.fixture(scope="session")
def parser_config(config):
    """
    Fixture returns ieg parser config for test.
    """
    return config.parser


@pytest.fixture(scope="session")
def attributes(config):
    """
    Fixture returns ieg attributes config for test.
    """
    return config.attributes


@pytest.fixture(scope="session")
def api_start_kw(config):
    """
    Fixture returns ieg attributes config for test.
    """
    return config.api_start_kw
