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
