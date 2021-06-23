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
from iegen.context_manager.ctx_mgr import ContextManager
from iegen.ir.ast import Node, NodeType
from iegen.ir.exec_rules import RunRule
from iegen.parser.ieg_api_parser import APIParser
from iegen.parser.ieg_parser import CXXParser
from iegen.utils import load_rule_module


SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
CXX_INPUTS_FOLDER = 'test_cxx_inputs'


def test_parser(clang_config):
    parser = CXXParser()
    processor = CXXPrintProcessor()
    for c in parser.parse_x(**clang_config):
        processor(c)


def test_parser_processor(clang_config):
    parser = CXXParser()
    processor = CXXPrintProcessor()
    parser.parse(processor, **clang_config)


def test_parser_processor_cr_counter(clang_config):
    parser = CXXParser()
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
    "attributes, test_data, res_md5",
    [
        (
                'attributes',
                """
                /**
                * comments
                *
                * __API__
                * gen: class
                * kotlin.file: utils
                * swift.prefix: PI
                */
                """,
                "e78e907d4c03cd4ae3644d27a3ad7e00"
        ),
        (
                'attributes',
                """
                /**
                * commants
                *
                * __API__
                * gen: class
                * shared_ref: False
                */
                """,
                "c4ef14239b668d5c4876742ca5f9da31"
        )
    ],
    indirect=['attributes']
)
def test_API_parser(attributes, test_data, res_md5):
    parser = APIParser(attributes=attributes)

    _, api_section = APIParser.separate_pure_and_api_comment(test_data)
    api, args = parser.parse_comments(api_section, {})
    str_res = f"api={api}, args={args}"
    assert hashlib.md5(str_res.encode()).hexdigest() == res_md5, \
        "API parser result has bean changed."


@pytest.mark.parametrize(
    "attributes, test_data",
    [
        (
                'attributes',
                """
                /**
                * comments
                *
                * __API__
                * kotlin.file: utils
                dd
                * swift_prefix: PI
                */
                """,
        ),
        (
                'attributes',
                """
                /**
                * commants
                *
                * __API__
                * gen: class
                * shared_ref
                */
                """,
        )
    ],
    indirect=['attributes']
)
def test_API_parser_negative(attributes, test_data):
    parser = APIParser(attributes=attributes)
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
        config.api_type_attributes_glob = os.path.join(api_rules_dir, dir, '*.yaml')
        try:
            APIParser.build_api_type_attributes(config)
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
        'with_many_files': '61e1677833d942e27eae06854b3652e7',
        'with_nested_cfg': 'cb6548fb573f46ddead383ade7a712a1',
        'with_mixed_cfg': '61e1677833d942e27eae06854b3652e7',
        'with_simple_cfg': 'e7cee96cb9c30a9a13621db5324122b6',
        'with_jinja_expr': '292f69c0cbd4ea9447a3ab6dbeb2e6bf'
    }

    for dir, res_md5 in results.items():
        config.api_type_attributes_glob = os.path.join(api_rules_dir, dir, '*.yaml')
        try:
            res = APIParser.build_api_type_attributes(config)

            ordered_res = OrderedDict()
            for key in sorted(res.keys()):
                ordered_res[key] = res[key].attr

            assert hashlib.md5(str(ordered_res).encode()).hexdigest() == res_md5, \
                "External API parser results has bean changed."
        except Exception:
            assert False, "should not get error"


def test_parser_errors(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'negative')

    parser = CXXParser()

    ctx_mgr = ContextManager(default_config.attributes, 'linux', 'swift')
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    for file in os.listdir(test_dir):
        Error.has_error = False

        clang_cfg['src_glob'] = [os.path.join(test_dir, file)]
        parser.parse(ir_builder, **clang_cfg)
        assert Error.has_error == True, "Must cause an error"


def test_jinja_attrs(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'jinja_attr')
    parser = CXXParser()

    clang_cfg['src_glob'] = [os.path.join(test_dir, '*.hpp')]

    ctx_mgr = ContextManager(default_config.attributes, 'linux', 'swift')
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)

    for name in ('pkg_exc_1', 'pkg_exc_2', 'pkgInt', 'pkgDouble', 'pkg_shared'):
        assert name in str(ir_builder.ir), "Wrong evaluation of jinja attribute value"

@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, 'api_rules_dir', 'positive', 'with_empty_gen'))
def test_empty_gen_rule(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    working_dir = os.getcwd()

    lang, plat = 'python', 'linux'
    lang_config = default_config.application

    lang_config.api_type_attributes_glob = os.path.join(working_dir, '*.yaml')
    clang_cfg['src_glob'] = [os.path.join(working_dir, '*.hpp')]

    parser = CXXParser()
    ctx_mgr = ContextManager(default_config.attributes, plat, lang)
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)

    ir = ir_builder.ir
    dir_root = ir.children[0]

    # check that directory gen rule is empty
    assert dir_root.api == Node.API_NONE, 'wrong directory gen rule'
    assert dir_root.type == NodeType.DIRECTORY_NODE, 'wrong directory node kind'
    assert dir_root.children[0].children[0].api == 'class', 'wrong api type'

    # check that 'package' inheritable attribute is inherited from dir to class
    dir_pkg_value = dir_root.args['package']
    cls_pkg_value = dir_root.children[0].children[0].args['package']
    assert dir_pkg_value == cls_pkg_value == 'example_pkg', "inheritance of attributes doesn't work correctly"

    ir.args['out_dir'] = os.path.join(working_dir, 'example_out_dir')
    lang_rule = load_rule_module(lang, default_config.application.rule, default_config.default_config_dirs)
    run_rule = RunRule(ir, plat, lang)
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
def test_root_config(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    working_dir = os.getcwd()

    lang, plat = 'python', 'linux'
    lang_config = default_config.application

    lang_config.api_type_attributes_glob = os.path.join(working_dir, '*.yaml')
    clang_cfg['src_glob'] = [os.path.join(working_dir, '*.hpp')]

    parser = CXXParser()
    ctx_mgr = ContextManager(default_config.attributes, plat, lang)
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)
    root = ir_builder.ir

    assert root.api == Node.API_NONE, 'wrong root gen rule'
    assert root.type == NodeType.ROOT_NODE, 'wrong root node kind'
    assert root.children[0].type == NodeType.DIRECTORY_NODE, 'wrong directory node kind'
    assert root.children[0].children[0].children[0].api == 'class', 'wrong class node api'

    root_clang_value = root.args['clang_args']
    assert root_clang_value == ['clang_args'], "inheritance of attributes doesn't work correctly"


def test_file_api_positive(parser_config):
    config = copy.deepcopy(parser_config)
    file_api_folder = 'file_api_example'
    api_rules_dir = os.path.abspath(os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{file_api_folder}/*.yaml'))
    config.api_type_attributes_glob = api_rules_dir

    api_parser = APIParser(attributes=default_config.attributes,
                           parser_config=config)

    example_file_key = os.path.abspath(os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{file_api_folder}/example.h'))

    api, args = api_parser.parse_yaml_api(example_file_key, {})

    assert api == Node.API_NONE
    assert args['package']['__all__']['__all__'] == 'test_cxx_inputs'


def test_dir_api_positive(parser_config):
    config = copy.deepcopy(parser_config)
    dir_api_folder = 'dir_api_example'
    api_rules_dir = os.path.abspath(os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{dir_api_folder}/*.yaml'))
    config.api_type_attributes_glob = api_rules_dir

    api_parser = APIParser(attributes=default_config.attributes,
                           parser_config=config)

    example_dir_key = os.path.relpath(
        os.path.abspath(os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{dir_api_folder}')), os.getcwd())

    api, args = api_parser.parse_yaml_api(example_dir_key, {})

    assert api == 'package'
    assert args['name']['__all__']['__all__'] == 'inputs'
    assert args['code_fragment']['__all__']['python'] == ['import json']
