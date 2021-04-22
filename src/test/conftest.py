"""
Module contains common fixtures used in iegen related tests
"""
import copy

import pytest
from iegen.common.config import config as default_config
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
    get_parser_config(cnfg).src_glob = TEST_CXX_DIR + '/*.h'

    return cnfg


@pytest.fixture(scope="session")
def parser_config(config):
    """
    Fixture returns ieg parser config for test.
    """
    return get_parser_config(config)


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


@pytest.fixture(scope="session")
def out_dir():
    """
    Fixture returns out_dir for test files.
    """
    return TEST_OUT_DIR
