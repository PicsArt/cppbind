import copy
import git
import hashlib
import os
import types
from unittest.mock import patch, PropertyMock

import pytest
import yaml

from cppbind.builder.ir_builder import CXXPrintProcessor, CppBindIRBuilder
from cppbind.common.error import CppBindError
from cppbind.common.yaml_process import load_yaml
from cppbind.context_manager.ctx_desc import ContextDescriptor
from cppbind.context_manager.ctx_mgr import ContextManager
from cppbind.ir.ast import Node, RootNode
from cppbind.parser.cppbind_api_parser import APIParser
from cppbind.parser.cppbind_parser import CXXParser
from cppbind.utils import init_jinja_env

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
CXX_INPUTS_FOLDER = 'test_cxx_inputs'


def test_parser_processor(clang_config):
    processor = CXXPrintProcessor()
    parser = CXXParser(processor, False)
    parser.parse(**clang_config)


def test_parser_processor_cr_counter(clang_config):
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
    parser = CXXParser(count_processor, False)
    parser.parse(**clang_config)

    assert count == 9, "number of cursors has bean changed"
    assert max_dept == 3, "max depth has bean changed"


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
    jinja_env = init_jinja_env('swift')
    parser = APIParser(ContextDescriptor(None), jinja_env, 'linux', 'swift')

    _, api_section = APIParser.separate_pure_and_api_comment(test_data)
    api, args = parser.parse_comments(api_section)
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
        * comments
        *
        * __API__
        * action: gen_class
        * shared_ref
        */
        """
    ]
)
def test_api_parser_negative(test_data):
    jinja_env = init_jinja_env('swift')
    parser = APIParser(ContextDescriptor(None), jinja_env, 'linux', 'swift')
    _, api_section = APIParser.separate_pure_and_api_comment(test_data)
    try:
        parser.parse_comments(api_section)
    except CppBindError:
        pass
    else:
        assert False, "should get error"


def test_parser_errors(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, 'test_examples/negative')

    lang, plat = 'swift', 'linux'
    ctx_mgr = ContextManager(ContextDescriptor(None), plat, lang)
    ir_builder = CppBindIRBuilder(RootNode(), ctx_mgr)
    ir_builder.start_root()

    for file in os.listdir(test_dir):
        with pytest.raises(CppBindError):
            clang_cfg['src_glob'] = [os.path.join(test_dir, file)]
            parser = CXXParser(ir_builder, False)
            parser.parse(**clang_cfg)


def test_file_api_positive():
    file_api_folder = 'file_api_example'

    context_def_glob = os.path.abspath(os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{file_api_folder}/*.yaml'))
    jinja_env = init_jinja_env('swift')
    api_parser = APIParser(ContextDescriptor(context_def_glob), jinja_env, 'linux', 'swift')

    example_file_key = os.path.abspath(
        os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{file_api_folder}/example.h'))

    api, args = api_parser.parse_yaml_api(example_file_key, {})

    assert api == Node.API_NONE
    assert args['package'] == 'test_cxx_inputs'


def test_dir_api_positive():
    dir_api_folder = 'dir_api_example'

    context_def_glob = os.path.abspath(os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{dir_api_folder}/*.yaml'))
    jinja_env = init_jinja_env('swift')
    api_parser = APIParser(ContextDescriptor(context_def_glob), jinja_env, 'linux', 'python')

    example_dir_key = os.path.relpath(os.path.abspath(
        os.path.join(SCRIPT_DIR, f'../{CXX_INPUTS_FOLDER}/{dir_api_folder}')), os.getcwd())

    api, args = api_parser.parse_yaml_api(example_dir_key, {})

    assert api == 'gen_package'
    assert args['name'] == 'inputs'
    assert args['code_fragment'] == 'import json'


def test_var_def_validation():
    test_dir = os.path.join(SCRIPT_DIR, 'test_examples/jinja_attr/positive')

    with patch('cppbind.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock, \
            pytest.raises(CppBindError, match=r"Variable 'b' is required on 'dir' node*"):
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(test_dir, "example_var_def.yaml")))

        # add dummy 'required_on' node without having it in 'allowed_on' list
        var_def_mock.return_value['b']['required_on'] = ['dir']

        ContextDescriptor(None)


def test_attr_type_mismatch_negative():
    test_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'jinja_attr/negative')

    examples_dir = os.path.join(test_dir, "var_def_with_type_mismatch")
    for example_file in os.listdir(examples_dir):
        with patch('cppbind.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock, \
                pytest.raises(CppBindError,
                              match=r"Wrong template variable style"
                              if example_file == "with_wrong_template.yaml" else r"Type mismatch*"):
            var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
                load_yaml(os.path.join(examples_dir, example_file)))

            ctx_mgr = ContextManager(ContextDescriptor(None), 'linux', 'swift')
            ir_builder = CppBindIRBuilder(RootNode(), ctx_mgr)

            ir_builder.start_root()

@pytest.mark.parametrize(
    "var_def, api_section",
    [
        (
            """
            A:
              inheritable: false
              default: null
              allowed_on: [root]
              options: [opt_1, opt_2]
            """,
            """
             * A: opt_3
            """
        ),
        (
            """
            B:
              inheritable: false
              default: null
              type: int
              allowed_on: [root]
              options: [1, 2, 3]
            """,
            """
             * B: 4
            """
        ),
        (
            """
            C:
              inheritable: false
              default: null
              allowed_on: [root]
              type: int
              options: [1, 4]
            """,
            """
             * C: "{{1+1}}"
            """
        ),
        (
            """
            D:
              inheritable: false
              default: 4
              allowed_on: [root]
              type: int
              options: [1, 2, 3]
            """,
            """
             * D: 5
            """
        )
    ]
)
def test_attr_options_negative(var_def, api_section):

    with patch('cppbind.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock,\
            pytest.raises(CppBindError, match=r"Value mismatch*"):

        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(yaml.load(var_def, Loader=yaml.SafeLoader))
        ctx_mgr = ContextManager(ContextDescriptor(None), 'linux', 'python')
        ctx_mgr.eval_clang_attrs(None, "root", api_section, {}, None)


@pytest.mark.parametrize(
    "var_def, api_section",
    [
        (
            """
            A:
              inheritable: false
              default: null
              allowed_on: [root]
              options: [opt_1, opt_2]
            """,
            """
             * A: opt_1
            """
        ),
        (
            """
            B:
              inheritable: false
              default: null
              allowed_on: [root]
              type: int
              options: [1,2]
            """,
            """
             * B: "{{1+1}}"
            """
        ),
        (
            """
            C:
              inheritable: false
              default: null
              allowed_on: [root]
              type: dict
              options: [{i:1},{j:2}]
            """,
            """
             * C: {i:1}
            """
        ),
        (
            """
            D:
              inheritable: false
              default: 4
              allowed_on: [root]
              type: int
              options: [1, 2, 3]
            """,
            """
             * D: 3
            """
        )
    ]
)
def test_attr_options_positive(var_def, api_section):

    with patch('cppbind.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(yaml.load(var_def, Loader=yaml.SafeLoader))
        ctx_mgr = ContextManager(ContextDescriptor(None), 'linux', 'python')
        try:
            ctx_mgr.eval_clang_attrs(None, "root", api_section, {}, None)
        except CppBindError as e:
            assert False, e


@pytest.mark.parametrize(
    "test_data, result",
    [
        (
            """
                /**
                 *  ... text ...
                 *  __API__
                 *  action: gen_method
                 */
             """,
            "... text ..."
        ),
        (
            """
                /**
                    ... text ...
                    __API__
                    action: gen_method
                */
            """,
            "... text ..."
        ),
        (
            """
                /*!
                 *  ... text ...
                 *  __API__
                 *  action: gen_method
                 */
            """,
            "... text ..."
        ),
        (
            """
                /*!
                    ... text ...
                    __API__
                    action: gen_method
                */
            """,
            "... text ..."
        ),
        (
            """
                ///
                /// ... text ...
                /// __API__
                /// action: gen_method
                ///
            """,
            "... text ..."
        ),
        (
            """
                //!
                //! ... text ...
                //! __API__
                //! action: gen_method
                //!
            """,
            "... text ..."
        ),
        (
            """
                /********************************************//**
                 *  ... text ...
                 *  __API__
                 *  action: gen_method
                 ***********************************************/
            """,
            "... text ..."
        ),
        (
            """
                /////////////////////////////////////////////////
                /// ... text ...
                /// __API__
                /// action: gen_method
                /////////////////////////////////////////////////
            """,
            "... text ..."
        ),
        (
            """
                /************************************************
                 *  ... text ...
                 *  __API__
                 *  action: gen_method
                 ***********************************************/
            """,
            "... text ..."
        ),
        (
            """
                /**
                 *  **... text ...**
                 *  __API__
                 *  action: gen_method
                 */
            """,
            "**... text ...**"
        ),
        (
            """
                //!
                //! ///... text ...///
                //! __API__
                //! action: gen_method
                //!
            """,
            "///... text ...///"
        )
    ]
)
def test_doxygen_comments(test_data, result):
    jinja_env = init_jinja_env('swift')
    parser = APIParser(ContextDescriptor(None), jinja_env, 'linux', 'swift')

    pure_comment, api_section = APIParser.separate_pure_and_api_comment(test_data)
    api, args = parser.parse_comments(api_section)
    assert args['action'] == 'gen_method'
    assert pure_comment[1] == result


def test_get_git_repo_url():
    lang, plat = 'python', 'linux'
    ctx_mgr = ContextManager(ContextDescriptor(None), plat, lang)
    ir_builder = CppBindIRBuilder(RootNode(), ctx_mgr)
    _get_git_repo_url = ir_builder.get_sys_vars()['_get_git_repo_url']

    with patch('git.Repo.active_branch') as mock_git_repo_branch:
        with patch('git.Remote.urls', new_callable=PropertyMock) as mock_git_repo_urls:
            mock_git_repo_branch.name = "TestBranch"
            mock_git_repo_urls.return_value = iter(["TestRepo"])
            git_repo_url = _get_git_repo_url(os.path.abspath(SCRIPT_DIR + 3 * '/..'))
            assert git_repo_url == 'TestRepo/tree/TestBranch/'

    assert _get_git_repo_url('./dummy') is None
