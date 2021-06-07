import hashlib
import os
import types
from collections import OrderedDict

import pytest
import yaml

from iegen import default_config
from iegen.builder.ir_builder import CXXPrintProcsessor, CXXIEGIRBuilder
from iegen.common.error import Error
from iegen.common.yaml_process import YamlKeyDuplicationError
from iegen.ir.ast import NodeType
from iegen.parser.ieg_api_parser import APIParser
from iegen.parser.ieg_parser import CXXParser

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


def test_parser(parser_config):
    parsser = CXXParser(parser_config=parser_config)
    print(parser_config)
    processor = CXXPrintProcsessor()
    for c in parsser.parss_x():
        processor(c)


def test_parser_processor(parser_config):
    parsser = CXXParser(parser_config=parser_config)
    # print(parser_config)
    processor = CXXPrintProcsessor()
    parsser.parse(processor)


def test_parser_processor_cr_counter(parser_config):
    parsser = CXXParser(parser_config=parser_config)
    # print(parser_config)
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
    parsser.parse(count_processor)

    assert count == 19, "number of cursors has bean changed"
    assert max_dept == 5, "max depth has bean changed"


@pytest.mark.parametrize(
    "attributes, api_start_kw, test_data, res_md5",
    [
        (
                'attributes',
                'api_start_kw',
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
                'api_start_kw',
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
    indirect=['attributes', 'api_start_kw']
)
def test_API_parser(attributes, api_start_kw, test_data, res_md5):
    parsser = APIParser(attributes=attributes, api_start_kw=api_start_kw)

    api, args, _ = parsser.parse_comments(test_data)
    str_res = f"api={api}, args={args}"
    print(str_res)
    assert hashlib.md5(str_res.encode()).hexdigest() == res_md5, \
        "API parser result has bean changed."


@pytest.mark.parametrize(
    "attributes, api_start_kw, test_data",
    [
        (
                'attributes',
                'api_start_kw',
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
                'api_start_kw',
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
    indirect=['attributes', 'api_start_kw']
)
def test_API_parser_negative(attributes, api_start_kw, test_data):
    parsser = APIParser(attributes=attributes, api_start_kw=api_start_kw)
    try:
        api, args = parsser.parse_comments(
            test_data
        )
    except Exception:
        pass
    else:
        assert False, "should get error"


def test_external_API_parser_negative(parser_config):
    api_rules_dir = os.path.join(SCRIPT_DIR, 'api_rules_dir', 'negative')
    for dir in os.listdir(api_rules_dir):
        parser_config.api_type_attributes_glob = os.path.join(api_rules_dir, dir, '*.yaml')
        try:
            APIParser.build_api_type_attributes(parser_config)
        except (YamlKeyDuplicationError, yaml.YAMLError):
            pass
        except Exception as e:
            assert False, f"unexpected exception: {e}"
        else:
            assert False, "should get error"


def test_external_API_parser_positive(parser_config):
    api_rules_dir = os.path.join(SCRIPT_DIR, 'api_rules_dir', 'positive')

    results = {
        'with_many_files': '61e1677833d942e27eae06854b3652e7',
        'with_nested_cfg': 'cb6548fb573f46ddead383ade7a712a1',
        'with_mixed_cfg': '61e1677833d942e27eae06854b3652e7',
        'with_simple_cfg': 'e7cee96cb9c30a9a13621db5324122b6',
        'with_jinja_expr': '292f69c0cbd4ea9447a3ab6dbeb2e6bf'
    }

    for dir, res_md5 in results.items():
        parser_config.api_type_attributes_glob = os.path.join(api_rules_dir, dir, '*.yaml')
        try:
            res = APIParser.build_api_type_attributes(parser_config)

            ordered_res = OrderedDict()
            for key in sorted(res.keys()):
                ordered_res[key] = res[key].attr

            assert hashlib.md5(str(ordered_res).encode()).hexdigest() == res_md5, \
                "External API parser results has bean changed."
        except Exception:
            assert False, "should not get error"


def test_parser_errors(parser_config):
    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'negative')
    parser = CXXParser(parser_config=parser_config)

    ir_builder = CXXIEGIRBuilder(attributes=default_config.attributes,
                                 api_start_kw=default_config.api_start_kw,
                                 parser_config=parser.config)

    for file in os.listdir(test_dir):
        Error.has_error = False

        parser_config.src_glob = os.path.join(test_dir, file)
        parser.parse(ir_builder)
        assert Error.has_error == True, "Must cause an error"


def test_jinja_attrs(parser_config):
    test_dir = os.path.join(os.path.dirname(os.path.realpath(__file__)), 'test_examples', 'jinja_attr')
    parser = CXXParser(parser_config=parser_config)

    parser_config.src_glob = os.path.join(test_dir, '*.hpp')

    ir_builder = CXXIEGIRBuilder(attributes=default_config.attributes,
                                 api_start_kw=default_config.api_start_kw,
                                 parser_config=parser.config)
    parser.parse(ir_builder)

    for name in ('pkg_exc_1', 'pkg_exc_2', 'pkgInt', 'pkgDouble', 'pkg_shared'):
        assert name in str(ir_builder.ir), "Wrong evaluation of jinja attribute value"


def test_parser_with_dir_api(parser_config):
    # change cwd
    os.chdir(SCRIPT_DIR)
    cxx_inputs_rel_path = '../test_cxx_inputs'

    api_rules_dir = os.path.abspath(os.path.join(SCRIPT_DIR, cxx_inputs_rel_path))
    parser_config.src_glob = os.path.abspath(os.path.join(SCRIPT_DIR, cxx_inputs_rel_path, '*.h'))

    parser_config.api_type_attributes_glob = os.path.join(api_rules_dir, '*.yaml')
    # load yaml file api
    APIParser(attributes=default_config.attributes,
              api_start_kw=default_config.attributes,
              parser_config=parser_config)

    parser = CXXParser(parser_config=parser_config)

    processor = CXXIEGIRBuilder(attributes=default_config.attributes,
                                api_start_kw=default_config.api_start_kw,
                                parser_config=parser_config)

    parser.parse(processor)
    assert len(processor.ir.roots) == 1
    root = processor.ir.roots[0]
    assert root.type is NodeType.DIRECTORY_NODE
    print('>>>>>>>>>>>>>>>>>>>>>>>>>>>.')
    print(parser_config.src_glob)

    print(SCRIPT_DIR)
    print(root.name)
    assert root.api == 'package'
    assert root.name == cxx_inputs_rel_path
    assert root.children[0].type == NodeType.CLANG_NODE
