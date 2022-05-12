import os

from cppbind.utils import copy_yaml_config_template
from cppbind.utils import load_module_from_path
from . import TEST_RULES_DIR


def test_load_rule():
    rule = load_module_from_path("rules.java", os.path.join(TEST_RULES_DIR, "java.py"))
    assert rule


def test_config_is_copied():
    cfg_file = os.path.join(os.getcwd(), 'cppbind.yaml')
    assert os.path.exists(cfg_file) is False
    copy_yaml_config_template()
    assert os.path.exists(cfg_file) is True
    os.remove(cfg_file)
