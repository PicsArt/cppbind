import os
import shutil
import types
from pathlib import Path

import pytest

import clang.cindex as cli
import cppbind.utils.clang as cutil
from cppbind.common.error import CppBindError
from cppbind.ir.utils import available_on, allowed_after_build
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


def test_available_on_decorator():
    class _Node:
        def __init__(self, kind):
            self.kind = kind

        @property
        @available_on(cli.CursorKind.CXX_METHOD, cli.CursorKind.FUNCTION_TEMPLATE)
        def method_name(self):
            return "method_name"

    # positive test
    method_node = _Node(cli.CursorKind.CXX_METHOD)
    assert method_node.method_name == "method_name"

    # negative test
    ctor_node = _Node(cli.CursorKind.CONSTRUCTOR)
    with pytest.raises(AttributeError, match="_Node.method_name is invalid for CursorKind.CONSTRUCTOR node kind."):
        _ = ctor_node.method_name


def test_allowed_after_build_decorator():
    class _Node:
        def __init__(self, is_ir_built):
            # `allowed_after_build` decorator calls `node.root._is_built` method, so here we mock the `root` property
            self.root = types.SimpleNamespace(_is_built=lambda: is_ir_built)

        @property
        @allowed_after_build
        def kind(self):
            return "node_kind"

    # positive test
    complete_node = _Node(is_ir_built=True)
    assert complete_node.kind == "node_kind"

    # negative test
    partial_node = _Node(is_ir_built=False)
    with pytest.raises(CppBindError, match="INTERNAL: msg -> IR is not completely built. Access to "
                                           "'kind' property is forbidden"):
        _ = partial_node.kind


@pytest.mark.parametrize(
    "spelling, choice, result",
    [
        (
                'vector<T, Allocator>',
                {'T': 'int', 'Allocator': 'std::allocator<int>'},
                'vector<int, std::allocator<int>>'
        ),
        (
                'vector<T, Allocator>',
                {'T': 'int', 'Allocator': ''},
                'vector<int>'
        ),
        (
                'vector<T, Allocator>',
                {'T': '', 'Allocator': ''},
                'vector<>'
        ),
        (
                'tuple<T, Ts...>',
                {'T': 'int', 'Ts': ['int', 'double']},
                'tuple<int, int, double>'
        ),
        (
                'tuple<T, Ts...>',
                {'T': 'int', 'Ts': ''},
                'tuple<int>'
        ),
        (
                'tuple<Ts...>',
                {'Ts': ''},
                'tuple<>'
        ),
    ]
)
def test_template_template_choice(spelling, choice, result):
    assert cutil.replace_template_choice(spelling, choice) == result
