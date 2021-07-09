import copy
import hashlib
import os
import types

from collections import OrderedDict
from unittest.mock import patch

import pytest
import yaml

from iegen.builder.ir_builder import CXXPrintProcessor, CXXIEGIRBuilder
from iegen.common.error import Error
from iegen.common.yaml_process import YamlKeyDuplicationError, yaml_info_struct_to_dict
from iegen.context_manager.ctx_desc import ContextDescriptor
from iegen.context_manager.ctx_mgr import ContextManager
from iegen.ir.ast import Node, NodeType
from iegen.parser.ieg_api_parser import APIParser
from iegen.parser.ieg_parser import CXXParser


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
                "968fa15c9d1d04262b9edc7bbcf37fb7"
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
                "b64b94a831d388a32509fd7c296faa5c"
        )
    ]
)
def test_api_parser(test_data, res_md5):
    parser = APIParser(ContextDescriptor(None, 'linux', 'swift'))

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
def test_api_parser_negative(test_data):
    parser = APIParser(ContextDescriptor(None, 'linux', 'swift'))
    _, api_section = APIParser.separate_pure_and_api_comment(test_data)
    try:
        parser.parse_comments(api_section, {})
    except Exception:
        pass
    else:
        assert False, "should get error"


def test_external_api_parser_negative():
    ctx_desc = ContextDescriptor(None, 'linux', 'swift')
    api_rules_dir = os.path.join(SCRIPT_DIR, 'api_rules_dir', 'negative')

    for dir_ in os.listdir(api_rules_dir):
        context_def_glob = os.path.join(api_rules_dir, dir_, '*.yaml')
        try:
            ctx_desc.build_ctx_def_map(context_def_glob)
        except (YamlKeyDuplicationError, yaml.YAMLError):
            pass
        except Exception as err:
            assert False, f"unexpected exception: {err}"
        else:
            assert False, "should get error"


def test_external_api_parser_positive():
    ctx_desc = ContextDescriptor(None, 'linux', 'swift')
    api_rules_dir = os.path.join(SCRIPT_DIR, 'api_rules_dir', 'positive')

    results = {
        'with_many_files': 'a176d1e4fee490bdd04f0749e654c836',
        'with_nested_cfg': 'be98d78aa365a5ea45a835ff2b11c737',
        'with_mixed_cfg': 'a176d1e4fee490bdd04f0749e654c836',
        'with_simple_cfg': '6d4025adf843640d3ecdcfb7522bfc8e',
        'with_jinja_expr': '46060b5c7a6b72174f7729e6ce2f1ca0'
    }

    for dir_, res_md5 in results.items():
        context_def_glob = os.path.join(api_rules_dir, dir_, '*.yaml')
        try:
            res = yaml_info_struct_to_dict(ctx_desc.build_ctx_def_map(context_def_glob))
            print(res)

            ordered_res = OrderedDict()
            for key in sorted(res.keys()):
                ordered_res[key] = res[key]

            assert hashlib.md5(str(ordered_res).encode()).hexdigest() == res_md5,\
                "External API parser results has bean changed."

        except Exception:
            assert False, "should not get error"


def test_external_api_merging_positive():
    ctx_desc = ContextDescriptor(None, 'linux', 'swift')
    api_rules_dir = os.path.join(SCRIPT_DIR, 'api_rules_dir', 'positive')

    expected_res = {
        'code_snippets': {},
        'type_converters': {'a': {'f': {'g': {'h': 1}}, 'b': {'c': {'e': 1, 'd': ['e', 'f']}}}},
        'actions': []
    }

    context_def_glob = os.path.join(api_rules_dir, 'with_snippets_rules', '*.yaml')
    try:
        res = yaml_info_struct_to_dict(ctx_desc.build_ctx_def_map(context_def_glob))
        assert expected_res == res, "External API parser results has bean changed."
    except Exception:
        assert False, "should not get error"


def test_parser_errors(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'negative')

    parser = CXXParser()

    lang, plat = 'swift', 'linux'
    ctx_mgr = ContextManager(ContextDescriptor(None, plat, lang))
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    for file in os.listdir(test_dir):
        Error.has_error = False

        clang_cfg['src_glob'] = [os.path.join(test_dir, file)]
        parser.parse(ir_builder, **clang_cfg)
        assert Error.has_error is True, "Must cause an error"


def test_jinja_attrs(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'jinja_attr')
    parser = CXXParser()

    clang_cfg['src_glob'] = [os.path.join(test_dir, '*.hpp')]

    plat, lang = 'linux', 'swift'
    ctx_mgr = ContextManager(ContextDescriptor(None, plat, lang))
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)

    for name in ('pkg_exc_1', 'pkg_exc_2', 'pkgInt', 'pkgDouble', 'pkg_shared'):
        assert name in str(ir_builder.ir), "Wrong evaluation of jinja variable value"

@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, 'api_rules_dir', 'positive', 'with_empty_gen'))
def test_empty_gen_rule(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    working_dir = os.getcwd()

    lang, plat = 'python', 'linux'

    context_def_glob = os.path.join(working_dir, '*.yaml')
    clang_cfg['src_glob'] = [os.path.join(working_dir, '*.hpp')]

    parser = CXXParser()
    ctx_desc = ContextDescriptor(context_def_glob, plat, lang)
    ctx_mgr = ContextManager(ctx_desc)
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
    assert dir_pkg_value == cls_pkg_value == 'example_pkg',\
        "inheritance of variables doesn't work correctly"


@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, 'api_rules_dir', 'positive', 'with_root_config'))
def test_root_config(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    working_dir = os.getcwd()

    lang, plat = 'python', 'linux'

    context_def_glob = os.path.join(working_dir, '*.yaml')
    clang_cfg['src_glob'] = [os.path.join(working_dir, '*.hpp')]

    parser = CXXParser()
    ctx_mgr = ContextManager(ContextDescriptor(context_def_glob, plat, lang))
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
    context_def_glob = os.path.abspath(
        os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{file_api_folder}/*.yaml'))

    api_parser = APIParser(ContextDescriptor(context_def_glob, 'linux', 'swift'))

    example_file_key = os.path.abspath(
        os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{file_api_folder}/example.h'))

    api, args = api_parser.parse_yaml_api(example_file_key, {})

    assert api == Node.API_NONE
    assert args['package'] == 'test_cxx_inputs'


def test_dir_api_positive():
    dir_api_folder = 'dir_api_example'
    context_def_glob = os.path.abspath(
        os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{dir_api_folder}/*.yaml'))

    api_parser = APIParser(ContextDescriptor(context_def_glob, 'linux', 'python'))

    example_dir_key = os.path.relpath(os.path.abspath(
        os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{dir_api_folder}')), os.getcwd())

    api, args = api_parser.parse_yaml_api(example_dir_key, {})

    assert api == 'gen_package'
    assert args['name'] == 'inputs'
    assert args['code_fragment'] == ['import json']
