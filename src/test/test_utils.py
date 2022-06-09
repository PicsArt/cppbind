import os
import shutil
from pathlib import Path
from cppbind.utils import copy_yaml_config_template, load_module_from_path, clear_cppbind_generated_files
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


def test_clean():
    src_gen_files = os.path.join(os.path.abspath(__file__ + "/../../../"),
                                 "examples/primitives/swift/wrappers/nested_types")
    dst_gen_files = os.path.join(os.path.dirname(Path(__file__)), "wrappers")
    destination = shutil.copytree(src_gen_files, dst_gen_files)
    clear_cppbind_generated_files(destination)
    assert os.path.exists(destination) is False
