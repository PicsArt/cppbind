import copy
import hashlib
import os
import types

from collections import OrderedDict
from unittest.mock import patch

import pytest
import yaml

from iegen.builder.ir_builder import CXXPrintProcessor, CXXIEGIRBuilder
from iegen.common.error import Error, IEGError
from iegen.common.yaml_process import YamlKeyDuplicationError, yaml_info_struct_to_dict, load_yaml
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
    parser = APIParser(ContextDescriptor(), 'linux', 'swift')

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
        dddd
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
    parser = APIParser(ContextDescriptor(), 'linux', 'swift')
    _, api_section = APIParser.separate_pure_and_api_comment(test_data)
    try:
        parser.parse_comments(api_section, {})
    except IEGError:
        pass
    else:
        assert False, "should get error"


def test_external_api_parser_negative():
    ctx_desc = ContextDescriptor()
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
    ctx_desc = ContextDescriptor()
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

            ordered_res = OrderedDict()
            for key in sorted(res.keys()):
                ordered_res[key] = res[key]

            assert hashlib.md5(str(ordered_res).encode()).hexdigest() == res_md5,\
                "External API parser results has bean changed."

        except IEGError:
            assert False, "should not get error"


def test_external_api_merging_positive():
    ctx_desc = ContextDescriptor()
    api_rules_dir = os.path.join(SCRIPT_DIR, 'api_rules_dir', 'positive')

    expected_res = {
        'code_snippets': {},
        'type_converters': {'a': {'f': {'g': {'h': 1}}, 'b': {'c': {'e': 1, 'd': ['e', 'f']}}}},
        'actions': []
    }

    context_def_glob = os.path.join(api_rules_dir, 'with_snippets_rules', '*.yaml')
    try:
        res = yaml_info_struct_to_dict(ctx_desc.build_ctx_def_map(context_def_glob))

        assert res['code_snippets'] == {}, "External API parser results has bean changed."
        assert res['actions'] == {}, "External API parser results has bean changed."
        assert res['type_converters']['linux']['python'] == \
               {'a': {'f': {'g': {'h': 1}}, 'b': {'c': {'e': 1, 'd': ['e', 'f']}}}}, \
            "External API parser results has bean changed."
    except IEGError:
        assert False, "should not get error"


def test_parser_errors(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'negative')

    parser = CXXParser()

    lang, plat = 'swift', 'linux'
    ctx_mgr = ContextManager(ContextDescriptor(), plat, lang)
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    for file in os.listdir(test_dir):
        Error.has_error = False

        clang_cfg['src_glob'] = [os.path.join(test_dir, file)]
        parser.parse(ir_builder, **clang_cfg)
        assert Error.has_error is True, "Must cause an error"


def test_jinja_attrs(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, 'test_examples/jinja_attr/positive')
    parser = CXXParser()

    clang_cfg['src_glob'] = [os.path.join(test_dir, 'with_jinja_attrs.hpp')]

    plat, lang = 'linux', 'swift'
    ctx_mgr = ContextManager(ContextDescriptor(), plat, lang)
    ir_builder = CXXIEGIRBuilder(ctx_mgr)

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)

    for name in ('pkg_exc_1', 'pkg_exc_2', 'pkgInt', 'pkgDouble', 'pkg_shared'):
        assert name in str(ir_builder.ir), "Wrong evaluation of jinja variable value"


@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, 'test_examples/jinja_attr/positive'))
def test_attrs_dependencies_and_jinja_usage_positive(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'jinja_attr/positive')
    parser = CXXParser()

    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock, \
         patch('iegen.context_manager.ctx_desc.default_config') as parser_cfg_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(test_dir, "example_var_def.yaml")))

        clang_cfg['src_glob'] = [os.path.join(test_dir, 'with_attrs_dep.hpp')]
        parser_cfg_mock.application.context_def_glob = os.path.join(test_dir, 'example_iegen.yaml')

        ctx_mgr = ContextManager(ContextDescriptor(), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(ctx_mgr)

        ir_builder.start_root()
        parser.parse(ir_builder, **clang_cfg)

        namespace_node = ir_builder.ir.children[0].children[0].children[0]

        # checking root context
        assert ir_builder.ir.args['d'] == "NewValueOfCUsedInD",\
            "root variable is not evaluated with updated value of dependant variable"

        # checking the first class and method
        cls_node = namespace_node.children[0]
        assert cls_node.args['a'] == 'ParentValue', "class 'name' variable is not set correctly"
        assert cls_node.args['b'] == f"{cls_node.args['a']}UsedInB",\
            "variables dependency for default values doesn't work correctly"

        # checking not simple types (list and dict)
        assert cls_node.args['g'] == ["SingleValue"],\
            "single value must be put into list if 'type' attribute of variable is list"
        assert cls_node.args['h'] == [cls_node.args['g'][0] + str(i+1) for i in range(3)],\
            "evaluation of jinja dynamic for cycle doesn't work correctly"
        assert cls_node.args['i'] == {"T": "SingleValue1", "V": ["SingleValue1", "SingleValue2"]},\
            "evaluation of jinja dict doesn't work correctly"

        method_node = cls_node.children[0]
        assert method_node.args['a'] == f"{cls_node.args['a']}InChild",\
            "inheritance of variables doesn't work correctly"
        assert method_node.args['b'] == f"Used{method_node.args['a']}",\
            "variables current evaluated context is ignored"
        assert method_node.args['h'] == [cls_node.args['h'][0], 'NewValue'],\
            "evaluation of each item of list doesn't work correctly"

        # checking the second class and method
        cls_node = namespace_node.children[1]
        assert cls_node.args['a'] == "DefaultValueOfA", "default value is not used correctly"
        assert cls_node.args['b'] == "DefaultValueOfAUsedInB",\
            "variables dependency for default values doesn't work correctly"

        # check that new lines of variable are preserving if they are written in yaml config file
        assert cls_node.args['k'] == ['row1\n\nrow2'],\
            "new lines are not preserved in yaml config section"

        method_node = cls_node.children[0]
        assert method_node.args['a'] == cls_node.args['a'],\
            "inheritance of variables doesn't work correctly"
        assert method_node.args['b'] == "DefaultValueOfAUsedInB",\
            "current variable couldn't managed to use parents context"
        assert method_node.args['d'] == f"{cls_node.args['c']}UsedInD",\
            "inheritance of variables doesn't work correctly"
        assert method_node.args['e'] == f"{method_node.args['f']}UsedInE",\
            "cyclic-like dependencies doesn't work correctly"
        assert(method_node.args['h'] == cls_node.args['h'] + ['NewValue']),\
            "evaluation of jinja list augmentation doesn't work correctly"
        assert method_node.args['j'] == {'T': 'SingleValue1'},\
            "evaluation of platform/language specific field of default values doesn't work correctly"

        # check that new lines of variable are preserving if they are written in API comment section
        assert method_node.args['k'] == ['first row\n\n\nsecond row'],\
            "new lines are not preserved in API comments section"

        # check usage of "//" symbols as comment sign
        assert cls_node.children[1].args['a'] == cls_node.children[2].args['a'] == "ValueOfA",\
            "usage of '//' symbols as a start of api comment fails"


def test_attrs_dependencies_and_jinja_usage_negative(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'jinja_attr/negative')
    parser = CXXParser()

    # check wrong variables order in var def file
    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(test_dir, "var_def_with_wrong_order.yaml")))

        clang_cfg['src_glob'] = [os.path.join(test_dir, 'with_attrs_dep.hpp')]

        ctx_mgr = ContextManager(ContextDescriptor(), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(ctx_mgr)

        try:
            ir_builder.start_root()
        except IEGError:
            pass
        except Exception as err:
            assert False, f"unexpected exception: {err}"
        else:
            assert False, "should get error: incorrect order of dependant variables in variables definition file"

    # check wrong dependency usage in root section (undefined variable)
    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock, \
         patch('iegen.context_manager.ctx_desc.default_config') as parser_cfg_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(test_dir, "example_var_def.yaml")))

        clang_cfg['src_glob'] = [os.path.join(test_dir, 'with_attrs_dep.hpp')]

        parser_cfg_mock.application.context_def_glob = os.path.join(test_dir, 'with_wrong_order_iegen.yaml')
        ctx_mgr = ContextManager(ContextDescriptor(), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(ctx_mgr)

        try:
            ir_builder.start_root()
        except IEGError:
            pass
        except Exception as err:
            assert False, f"unexpected exception: {err}"
        else:
            assert False, "should get error: incorrect dependency used in root section"

    # check variables dependency in case when they are defined on different nodes
    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(test_dir, "var_def_with_diff_nodes.yaml")))
        clang_cfg['src_glob'] = [os.path.join(test_dir, 'with_diff_nodes.hpp')]

        ctx_mgr = ContextManager(ContextDescriptor(), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(ctx_mgr)
        ir_builder.start_root()

        try:
            parser.parse(ir_builder, **clang_cfg)
        except IEGError:
            pass
        except Exception as err:
            assert False, f"unexpected exception: {err}"
        else:
            assert False, "not inheritable variable cannot be used when evaluating context of child node"

    # check variables dependency in case when they are defined on different nodes
    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(test_dir, "var_def_with_unavailable_var.yaml")))

        ctx_mgr = ContextManager(ContextDescriptor(), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(ctx_mgr)

        try:
            ir_builder.start_root()
        except IEGError:
            pass
        except Exception as err:
            assert False, f"unexpected exception: {err}"
        else:
            assert False, "usage of unavailable variable inside jinja expression must be failed"


@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, 'api_rules_dir', 'positive', 'with_empty_gen'))
def test_empty_gen_rule(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    working_dir = os.getcwd()

    lang, plat = 'python', 'linux'
    clang_cfg['src_glob'] = [os.path.join(working_dir, '*.hpp')]

    with patch('iegen.context_manager.ctx_desc.default_config') as parser_cfg_mock:
        parser_cfg_mock.application.context_def_glob = os.path.join(working_dir, '*.yaml')

        parser = CXXParser()
        ctx_desc = ContextDescriptor()
        ctx_mgr = ContextManager(ctx_desc, plat, lang)
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
    clang_cfg['src_glob'] = [os.path.join(working_dir, '*.hpp')]

    with patch('iegen.context_manager.ctx_desc.default_config') as parser_cfg_mock:
        parser_cfg_mock.application.context_def_glob = os.path.join(working_dir, '*.yaml')

        parser = CXXParser()
        ctx_mgr = ContextManager(ContextDescriptor(), plat, lang)
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

    with patch('iegen.context_manager.ctx_desc.default_config') as parser_cfg_mock:
        parser_cfg_mock.application.context_def_glob = os.path.abspath(
            os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{file_api_folder}/*.yaml'))
        api_parser = APIParser(ContextDescriptor(), 'linux', 'swift')

        example_file_key = os.path.abspath(
            os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{file_api_folder}/example.h'))

        api, args = api_parser.parse_yaml_api(example_file_key, {})

        assert api == Node.API_NONE
        assert args['package'] == 'test_cxx_inputs'


def test_dir_api_positive():
    dir_api_folder = 'dir_api_example'

    with patch('iegen.context_manager.ctx_desc.default_config') as parser_cfg_mock:
        parser_cfg_mock.application.context_def_glob = os.path.abspath(
            os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{dir_api_folder}/*.yaml'))

        api_parser = APIParser(ContextDescriptor(), 'linux', 'python')

        example_dir_key = os.path.relpath(os.path.abspath(
            os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{dir_api_folder}')), os.getcwd())

        api, args = api_parser.parse_yaml_api(example_dir_key, {})

        assert api == 'gen_package'
        assert args['name'] == 'inputs'
        assert args['code_fragment'] == ['import json']


def test_var_def_validation():
    test_dir = os.path.join(SCRIPT_DIR, 'test_examples/jinja_attr/positive')

    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(test_dir, "example_var_def.yaml")))

        # add dummy 'required_on' node without having it in 'allowed_on' list
        var_def_mock.return_value['b']['required_on'] = ['dir']

        Error.has_error = False
        ContextDescriptor()

        assert Error.has_error is True, "variable cannot be required on a node on which it is not allowed"


def test_attr_type_mismatch_negative():
    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'jinja_attr/negative')

    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(test_dir, "var_def_with_type_mismatch.yaml")))

        ctx_mgr = ContextManager(ContextDescriptor(), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(ctx_mgr)

        Error.has_error = False
        ir_builder.start_root()
        assert Error.has_error is True, "evaluation of an expression must fail if its type doesn't match required one"
