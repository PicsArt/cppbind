import os

from iegen.utils import load_module_from_path
from . import TEST_RULES_DIR


def test_load_rule():

    rule = load_module_from_path("rules.java", os.path.join(TEST_RULES_DIR, "java.py"))
    assert rule
