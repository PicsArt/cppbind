import copy
import hashlib
import os
import types
import yaml
from collections import OrderedDict
from shutil import rmtree

import pytest
from unittest.mock import patch

from iegen import default_config
from iegen.builder.ir_builder import CXXPrintProcessor, CXXIEGIRBuilder
from iegen.builder.out_builder import Builder
from iegen.common.error import Error
from iegen.common.yaml_process import YamlKeyDuplicationError
from iegen.context_manager.ctx_desc import ContextDescriptor
from iegen.context_manager.ctx_mgr import ContextManager
from iegen.ir.ast import Node, NodeType
from iegen.ir.exec_rules import RunRule
from iegen.parser.ieg_api_parser import APIParser
from iegen.parser.ieg_parser import CXXParser
from iegen.utils import load_module_from_paths


SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
CXX_INPUTS_FOLDER = 'test_cxx_inputs'


def test_parser(parser_config, clang_config):
    parser = CXXParser(parser_config=parser_config)
    processor = CXXPrintProcessor()
    for c in parser.parse_x(**clang_config):
        processor(c)


def test_parser_processor(parser_config, clang_config):
    parser = CXXParser(parser_config=parser_config)
    processor = CXXPrintProcessor()
    parser.parse(processor, **clang_config)


def test_parser_processor_cr_counter(parser_config, clang_config):
    parser = CXXParser(parser_config=parser_config)
    count = 0
    max_dept = 0
    dept = 0

    count_processor = types.SimpleNamespace()

    def incr_dept(cursor):
        nonlocal max_dept
        nonlocal dept
        nonlocal count
        count += 1
        dept += 1
        max_dept = max(dept, max_dept)

    def decr_dept(cursor):
        nonlocal dept
        dept -= 1

    count_processor.start_cursor = incr_dept
    count_processor.end_cursor = decr_dept
    parser.parse(count_processor, **clang_config)

    assert count == 19, "number of cursors has bean changed"
    assert max_dept == 5, "max depth has bean changed"


@pytest.mark.parametrize(
    "test_data, res_md5",
    [
        (
                """
                /**
                * comments
                *
                * __API__
                * action: gen_class
                * kotlin.file: utils
                */
                """,
                "a9dd42fb3dd193871b8a49913180c08e"
        ),
        (
                """
                /**
                * commants
                *
                * __API__
                * action: gen_class
                * shared_ref: False
                */
                """,
                "9e1abee91024c0f427a0f5f04732823b"
        )
    ]
)
def test_API_parser(test_data, res_md5):
    parser = APIParser(ContextDescriptor(None))

    _, api_section = APIParser.separate_pure_and_api_comment(test_data)
    api, args = parser.parse_comments(api_section, {})
    str_res = f"api={api}, args={args}"
    assert hashlib.md5(str_res.encode()).hexdigest() == res_md5, \
        "API parser result has bean changed."


@pytest.mark.parametrize(
    "test_data",
    [
        """
        /**
        * comments
        *
        * __API__
        * kotlin.file: utils
        dd
        */
        """,

        """
        /**
        * commants
        *
        * __API__
        * action: gen_class
        * shared_ref
        */
        """
    ]
)
def test_API_parser_negative(test_data):
    parser = APIParser(ContextDescriptor(None))
    _, api_section = APIParser.separate_pure_and_api_comment(test_data)
    try:
        parser.parse_comments(api_section, {})
    except Exception:
        pass
    else:
        assert False, "should get error"


def test_external_API_parser_negative(parser_config):
    config = copy.deepcopy(parser_config)
    api_rules_dir = os.path.join(SCRIPT_DIR, 'api_rules_dir', 'negative')
    for dir in os.listdir(api_rules_dir):
        config.context_def_glob = os.path.join(api_rules_dir, dir, '*.yaml')
        try:
            ContextDescriptor.build_ctx_def_map(config.context_def_glob)
        except (YamlKeyDuplicationError, yaml.YAMLError):
            pass
        except Exception as e:
            assert False, f"unexpected exception: {e}"
        else:
            assert False, "should get error"


def test_external_API_parser_positive(parser_config):
    api_rules_dir = os.path.join(SCRIPT_DIR, 'api_rules_dir', 'positive')
    config = copy.deepcopy(parser_config)
    results = {
        'with_many_files': 'a63fb90fb3bed215e76b7338f3b9b902',
        'with_nested_cfg': 'be98d78aa365a5ea45a835ff2b11c737',
        'with_mixed_cfg': 'a63fb90fb3bed215e76b7338f3b9b902',
        'with_simple_cfg': '6d4025adf843640d3ecdcfb7522bfc8e',
        'with_jinja_expr': '7e3f74054ee36e9401d3028ca7856a4e'
    }

    for dir, res_md5 in results.items():
        config.context_def_glob = os.path.join(api_rules_dir, dir, '*.yaml')
        try:
            res = ContextDescriptor.build_ctx_def_map(config.context_def_glob)

            ordered_res = OrderedDict()
            for key in sorted(res.keys()):
                ordered_res[key] = res[key].attr

            assert hashlib.md5(str(ordered_res).encode()).hexdigest() == res_md5, \
                "External API parser results has bean changed."
        except Exception:
            assert False, "should not get error"


def test_parser_errors(parser_config, clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'negative')

    parser = CXXParser(parser_config=parser_config)

    lang, plat = 'swift', 'linux'
    ctx_mgr = ContextManager(ContextDescriptor(None), plat, lang)
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    for file in os.listdir(test_dir):
        Error.has_error = False

        clang_cfg['src_glob'] = [os.path.join(test_dir, file)]
        parser.parse(ir_builder, **clang_cfg)
        assert Error.has_error is True, "Must cause an error"


def test_jinja_attrs(parser_config, clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'jinja_attr')
    parser = CXXParser(parser_config=parser_config)

    clang_cfg['src_glob'] = [os.path.join(test_dir, '*.hpp')]

    plat, lang = 'linux', 'swift'
    ctx_mgr = ContextManager(ContextDescriptor(None), plat, lang)
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)

    for name in ('pkg_exc_1', 'pkg_exc_2', 'pkgInt', 'pkgDouble', 'pkg_shared'):
        assert name in str(ir_builder.ir), "Wrong evaluation of jinja variable value"

@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, 'api_rules_dir', 'positive', 'with_empty_gen'))
def test_empty_gen_rule(parser_config, clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    working_dir = os.getcwd()

    lang, plat = 'python', 'linux'
    lang_config = default_config.languages[lang]

    context_def_glob = os.path.join(working_dir, '*.yaml')
    clang_cfg['src_glob'] = [os.path.join(working_dir, '*.hpp')]

    parser = CXXParser(parser_config=parser_config)
    ctx_mgr = ContextManager(ContextDescriptor(context_def_glob), plat, lang)
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)

    ir = ir_builder.ir
    dir_root = ir.children[0]

    # check that directory gen rule is empty
    assert dir_root.api == Node.API_NONE, 'wrong directory gen rule'
    assert dir_root.type == NodeType.DIRECTORY_NODE, 'wrong directory node kind'
    assert dir_root.children[0].children[0].api == 'gen_class', 'wrong api type'

    # check that 'package' inheritable variable is inherited from dir to class
    dir_pkg_value = dir_root.args['package']
    cls_pkg_value = dir_root.children[0].children[0].args['package']
    assert dir_pkg_value == cls_pkg_value == 'example_pkg', "inheritance of variables doesn't work correctly"

    ir.args['out_dir'] = os.path.join(working_dir, 'example_out_dir')
    lang_rule = load_module_from_paths(f"{lang}.rule", lang_config.rule, default_config.default_config_dirs)
    run_rule = RunRule(ir, plat, lang, lang_config)
    builder = Builder()

    # check that empty gen rule doesn't crash the app
    try:
        run_rule.run(lang_rule, builder)
    except AttributeError:
        assert False, "empty gen rule should not get error"
    else:
        # remove generated new directory
        rmtree(os.path.join(working_dir, ir.args['out_dir']))

@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, 'api_rules_dir', 'positive', 'with_root_config'))
def test_root_config(parser_config, clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    working_dir = os.getcwd()

    lang, plat = 'python', 'linux'

    context_def_glob = os.path.join(working_dir, '*.yaml')
    clang_cfg['src_glob'] = [os.path.join(working_dir, '*.hpp')]

    parser = CXXParser(parser_config=default_config)
    ctx_mgr = ContextManager(ContextDescriptor(context_def_glob), plat, lang)
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)
    root = ir_builder.ir

    assert root.api == Node.API_NONE, 'wrong root gen rule'
    assert root.type == NodeType.ROOT_NODE, 'wrong root node kind'
    assert root.children[0].type == NodeType.DIRECTORY_NODE, 'wrong directory node kind'
    assert root.children[0].children[0].children[0].api == 'gen_class', 'wrong class node api'

    root_clang_value = root.args['clang_args']
    assert root_clang_value == ['clang_args'], "inheritance of variables doesn't work correctly"


def test_file_api_positive():
    file_api_folder = 'file_api_example'
    context_def_glob = os.path.abspath(os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{file_api_folder}/*.yaml'))

    api_parser = APIParser(ContextDescriptor(context_def_glob))

    example_file_key = os.path.abspath(os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{file_api_folder}/example.h'))

    api, args = api_parser.parse_yaml_api(example_file_key, {})

    assert api == Node.API_NONE
    assert args['package']['__all__']['__all__'] == 'test_cxx_inputs'


def test_dir_api_positive():
    dir_api_folder = 'dir_api_example'
    context_def_glob = os.path.abspath(os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{dir_api_folder}/*.yaml'))

    api_parser = APIParser(ContextDescriptor(context_def_glob))

    example_dir_key = os.path.relpath(
        os.path.abspath(os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{dir_api_folder}')), os.getcwd())

    api, args = api_parser.parse_yaml_api(example_dir_key, {})

    assert api == 'gen_package'
    assert args['name']['__all__']['__all__'] == 'inputs'
    assert args['code_fragment']['__all__']['python'] == ['import json']