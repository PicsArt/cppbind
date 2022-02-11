import copy
import datetime
import os
import pytest
import types
from unittest.mock import patch, MagicMock

from iegen.builder.ir_builder import CXXIEGIRBuilder
from iegen.builder.ir_post_processor import IRPostProcessor
from iegen.common.error import IEGError
from iegen.common.yaml_process import load_yaml
from iegen.context_manager.ctx_desc import ContextDescriptor
from iegen.context_manager.ctx_mgr import ContextManager
from iegen.ir.ast import NodeType, Node, RootNode
from iegen.parser.filter import CXXParserFilter, CXXIegFilter
from iegen.parser.ieg_parser import CXXParser
from iegen.runner import WrapperGenerator
from iegen.utils import absolute_path_from_glob


SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
CXX_INPUTS_REL_PATH = '../test_cxx_inputs'


@patch('os.getcwd', lambda: SCRIPT_DIR)
def test_parser_with_dir_api(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    dir_example_folder = 'dir_api_example'
    api_rules_dir = os.path.abspath(os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH))

    plat, lang = 'linux', 'python'

    clang_cfg['src_glob'] = [os.path.abspath(
        os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH, dir_example_folder, '*.h'))]

    context_def_glob = os.path.join(api_rules_dir, dir_example_folder, '*.yaml')

    parser = CXXParser()
    ctx_desc = ContextDescriptor(context_def_glob)
    ctx_mgr = ContextManager(ctx_desc, plat, lang)

    processor = CXXIEGIRBuilder(RootNode(), ctx_mgr)
    CXXIEGIRBuilder._get_modification_time = MagicMock(return_value=datetime.datetime.utcnow())
    processor.start_root()
    parser.parse(processor, **clang_cfg)

    root = processor.ir
    dir_root = root.children[0]
    assert root.type is NodeType.ROOT_NODE
    assert dir_root.type is NodeType.DIRECTORY_NODE
    assert dir_root.name == CXX_INPUTS_REL_PATH
    assert len(dir_root.children) == 1
    dir_node = dir_root.children[0]
    assert dir_node.type == NodeType.DIRECTORY_NODE
    assert dir_node.api == 'gen_package'
    assert dir_node.name == f'{CXX_INPUTS_REL_PATH}/{dir_example_folder}'


@patch('os.getcwd', lambda: SCRIPT_DIR)
def test_parser_with_file_api(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    file_example_folder = 'file_api_example'

    api_rules_dir = os.path.abspath(os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH))
    clang_cfg['src_glob'] = [os.path.abspath(
        os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH, file_example_folder, '*.h'))]

    plat, lang = 'linux', 'python'
    context_def_glob = os.path.join(api_rules_dir, file_example_folder, '*.yaml')

    parser = CXXParser()
    ctx_desc = ContextDescriptor(context_def_glob)
    ctx_mgr = ContextManager(ctx_desc, plat, lang)
    processor = CXXIEGIRBuilder(RootNode(), ctx_mgr)
    CXXIEGIRBuilder._get_modification_time = MagicMock(return_value=datetime.datetime.utcnow())

    processor.start_root()
    parser.parse(processor, **clang_cfg)

    root = processor.ir
    assert root.type is NodeType.ROOT_NODE
    assert len(root.children) == 1
    root_dir = root.children[0]
    assert root_dir.name == CXX_INPUTS_REL_PATH
    assert len(root_dir.children) == 1
    dir_node = root_dir.children[0]
    assert dir_node.type == NodeType.DIRECTORY_NODE
    assert dir_node.api is None
    assert dir_node.name == f'{CXX_INPUTS_REL_PATH}/{file_example_folder}'
    assert len(dir_node.children) == 1
    file_node = dir_node.children[0]
    assert file_node.api == Node.API_NONE
    assert file_node.type == NodeType.FILE_NODE


def test_jinja_attrs(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, '../parser/test_examples/jinja_attr/positive')
    parser = CXXParser()

    clang_cfg['src_glob'] = [os.path.join(test_dir, 'with_jinja_attrs.hpp')]

    plat, lang = 'linux', 'swift'
    ctx_mgr = ContextManager(ContextDescriptor(None), plat, lang)
    ir_builder = CXXIEGIRBuilder(RootNode(), ctx_mgr)

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)

    for name in ('pkg_exc_1', 'pkg_exc_2', 'pkgInt', 'pkgDouble', 'pkg_shared'):
        assert name in str(ir_builder.ir), "Wrong evaluation of jinja variable value"


@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, '../parser/test_examples/jinja_attr/positive'))
def test_attrs_dependencies_and_jinja_usage_positive(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, '../parser/test_examples', 'jinja_attr/positive')
    parser = CXXParser()

    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(test_dir, "example_var_def.yaml")))

        clang_cfg['src_glob'] = [os.path.join(test_dir, 'with_attrs_dep.hpp')]
        context_def_glob = os.path.join(test_dir, 'example_iegen.yaml')

        ctx_mgr = ContextManager(ContextDescriptor(context_def_glob), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(RootNode(), ctx_mgr)

        ir_builder.start_root()
        parser.parse(ir_builder, **clang_cfg)

        namespace_node = ir_builder.ir.children[0].children[0].children[0]

        # checking root context
        assert ir_builder.ir.args['d'] == "NewValueOfCUsedInD", \
            "root variable is not evaluated with updated value of dependant variable"

        # checking the first class and method
        cls_node = namespace_node.children[0]
        assert cls_node.args['a'] == 'ParentValue', "class 'name' variable is not set correctly"
        assert cls_node.args['b'] == f"{cls_node.args['a']}UsedInB", \
            "variables dependency for default values doesn't work correctly"

        # checking not simple types (list and dict)
        assert cls_node.args['g'] == ["SingleValue"], \
            "single value must be put into list if 'type' attribute of variable is list"
        assert cls_node.args['h'] == [cls_node.args['g'][0] + str(i+1) for i in range(3)], \
            "evaluation of jinja dynamic for cycle doesn't work correctly"
        assert cls_node.args['i'] == {"T": "SingleValue1", "V": ["SingleValue1", "SingleValue2"]}, \
            "evaluation of jinja dict doesn't work correctly"

        method_node = cls_node.children[0]
        assert method_node.args['a'] == f"{cls_node.args['a']}InChild", \
            "inheritance of variables doesn't work correctly"
        assert method_node.args['b'] == f"Used{method_node.args['a']}", \
            "variables current evaluated context is ignored"
        assert method_node.args['h'] == [cls_node.args['h'][0], 'NewValue'], \
            "evaluation of each item of list doesn't work correctly"

        # checking the second class and method
        cls_node = namespace_node.children[1]
        assert cls_node.args['a'] == "DefaultValueOfA", "default value is not used correctly"
        assert cls_node.args['b'] == "DefaultValueOfAUsedInB", \
            "variables dependency for default values doesn't work correctly"

        # check that new lines of variable are preserving if they are written in yaml config file
        assert cls_node.args['k'] == ['row1\n\nrow2'], \
            "new lines are not preserved in yaml config section"

        method_node = cls_node.children[0]
        assert method_node.args['a'] == cls_node.args['a'], \
            "inheritance of variables doesn't work correctly"
        assert method_node.args['b'] == "DefaultValueOfAUsedInB", \
            "current variable couldn't managed to use parents context"
        assert method_node.args['d'] == f"{cls_node.args['c']}UsedInD", \
            "inheritance of variables doesn't work correctly"
        assert method_node.args['e'] == f"{method_node.args['f']}UsedInE", \
            "cyclic-like dependencies doesn't work correctly"
        assert(method_node.args['h'] == cls_node.args['h'] + ['NewValue']), \
            "evaluation of jinja list augmentation doesn't work correctly"
        assert method_node.args['j'] == {'T': 'SingleValue1'}, \
            "evaluation of platform/language specific field of default values doesn't work correctly"

        # check that new lines of variable are preserving if they are written in API comment section
        assert method_node.args['k'] == ['first row\n\n\nsecond row'], \
            "new lines are not preserved in API comments section"

        # check usage of "//" symbols as comment sign
        assert cls_node.children[1].args['a'] == cls_node.children[2].args['a'] == "ValueOfA", \
            "usage of '//' symbols as a start of api comment fails"


def test_attrs_dependencies_and_jinja_usage_negative(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    test_dir = os.path.join(SCRIPT_DIR, '../parser/test_examples/jinja_attr/negative')
    parser = CXXParser()

    # check wrong variables order in var def file
    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(test_dir, "var_def_with_wrong_order.yaml")))

        clang_cfg['src_glob'] = [os.path.join(test_dir, 'with_attrs_dep.hpp')]

        ctx_mgr = ContextManager(ContextDescriptor(None), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(RootNode(), ctx_mgr)

        try:
            ir_builder.start_root()
        except IEGError:
            pass
        except Exception as err:
            assert False, f"unexpected exception: {err}"
        else:
            assert False, "should get error: incorrect order of dependant variables in variables definition file"

    # check wrong dependency usage in root section (undefined variable)
    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(test_dir, "example_var_def.yaml")))

        clang_cfg['src_glob'] = [os.path.join(test_dir, 'with_attrs_dep.hpp')]

        context_def_glob = os.path.join(test_dir, 'with_wrong_order_iegen.yaml')
        ctx_mgr = ContextManager(ContextDescriptor(context_def_glob), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(RootNode(), ctx_mgr)

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

        ctx_mgr = ContextManager(ContextDescriptor(None), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(RootNode(), ctx_mgr)
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

        ctx_mgr = ContextManager(ContextDescriptor(None), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(RootNode(), ctx_mgr)

        try:
            ir_builder.start_root()
        except IEGError:
            pass
        except Exception as err:
            assert False, f"unexpected exception: {err}"
        else:
            assert False, "usage of unavailable variable inside jinja expression must be failed"


@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, '../parser/test_examples/with_empty_gen'))
def test_empty_gen_rule(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    working_dir = os.getcwd()

    lang, plat = 'python', 'linux'
    clang_cfg['src_glob'] = [os.path.join(working_dir, '*.hpp')]
    context_def_glob = os.path.join(working_dir, '*.yaml')

    parser = CXXParser()
    ctx_desc = ContextDescriptor(context_def_glob)
    ctx_mgr = ContextManager(ctx_desc, plat, lang)
    ir_builder = CXXIEGIRBuilder(RootNode(), ctx_mgr)

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


@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, '../parser/test_examples/with_root_config'))
def test_root_config(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    working_dir = os.getcwd()

    lang, plat = 'python', 'linux'
    clang_cfg['src_glob'] = [os.path.join(working_dir, '*.hpp')]
    context_def_glob = os.path.join(working_dir, '*.yaml')

    parser = CXXParser()
    ctx_mgr = ContextManager(ContextDescriptor(context_def_glob), plat, lang)
    ir_builder = CXXIEGIRBuilder(RootNode(), ctx_mgr)

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)
    root = ir_builder.ir

    assert root.api == Node.API_NONE, 'wrong root gen rule'
    assert root.type == NodeType.ROOT_NODE, 'wrong root node kind'
    assert root.children[0].type == NodeType.DIRECTORY_NODE, 'wrong directory node kind'
    assert root.children[0].children[0].children[0].api == 'gen_class', 'wrong class node api'

    root_clang_value = root.args['clang_args']
    assert root_clang_value == ['clang_args'], "inheritance of variables doesn't work correctly"


@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, '../parser/test_examples/jinja_attr/positive'))
def test_sys_vars_available_in_api(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    parser = CXXParser()

    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(os.getcwd(), "example_var_def.yaml")))

        clang_cfg['src_glob'] = [os.path.join(os.getcwd(), 'with_sys_vars_in_api.hpp')]

        ctx_mgr = ContextManager(ContextDescriptor(None), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(RootNode(), ctx_mgr)
        ir_builder.start_root()
        parser.parse(ir_builder, **clang_cfg)

        class_node = ir_builder.ir.children[0].children[0].children[0]

        # asserts sys variable(_pure_comment) used and evaluated in API
        assert class_node.args['comment'] == 'An example class comment.\n Binding generated by iegen.'


@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, "../parser/test_examples/cmd_line/positive"))
def test_cmd_line_ctx_positive():
    with patch('iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def') as var_def_mock:
        var_def_mock.return_value = ContextDescriptor.resolve_attr_aliases(
            load_yaml(os.path.join(os.getcwd(), "var_def.yaml")))

        ctx_mgr = ContextManager(ContextDescriptor(os.path.join(os.getcwd(), "iegen.yaml")), 'linux', 'swift')
        ir_builder = CXXIEGIRBuilder(RootNode(), ctx_mgr)
        ir_builder.start_root(types.SimpleNamespace(b='CmdLineValueOfB'))
        assert ir_builder.ir.args['a'] == 'CmdLineValueOfBUsedInA', \
            "command line context must be available when evaluating root context"
        assert ir_builder.ir.args['b'] == 'CmdLineValueOfB', "command line context must overwrite root one"


@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, "test_examples/exclude_glob"))
def test_src_exclude_glob(clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    plat, lang = 'linux', 'python'

    clang_cfg['src_glob'] = [os.path.abspath(os.path.join(os.getcwd(), 'main.hpp'))]
    clang_cfg['src_exclude_glob'] = [os.path.abspath(os.path.join(os.getcwd(), 'module.hpp'))]
    exclude_files = absolute_path_from_glob(clang_cfg['src_exclude_glob']) if clang_cfg['src_exclude_glob'] else None
    cxx_ieg_filter = CXXParserFilter(exclude_files=exclude_files)
    parser = CXXParser(filter_=cxx_ieg_filter)
    ctx_desc = ContextDescriptor(None)
    ctx_mgr = ContextManager(ctx_desc, plat, lang)

    processor = CXXIEGIRBuilder(RootNode(), ctx_mgr)
    processor.start_root()
    parser.parse(processor, **clang_cfg)

    assert len(processor.ir.children[0].children[0].children) == 1
    assert processor.ir.children[0].children[0].children[0].full_displayname == 'TestStruct'


@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, "test_examples/ir_process"))
def test_descendants_list(clang_config):
    clang_cfg = copy.deepcopy(clang_config)
    clang_cfg['src_glob'] = [os.path.join(os.getcwd(), 'descendants.hpp')]

    parser = CXXParser()
    ir_builder = CXXIEGIRBuilder(RootNode(), ContextManager(ContextDescriptor(None), 'linux', 'swift'))

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)
    ir_builder.end_root()

    ir = IRPostProcessor().process_ir(ir_builder.ir)

    cls_nodes = ir.children[0].children[0].children
    cls_node_map = {cls_node.full_displayname : cls_node for cls_node in cls_nodes}

    get_nodes_display_names = lambda nodes: [node.full_displayname for node in nodes]

    # check descendants list for each class node
    assert get_nodes_display_names(cls_node_map["C1"].descendants) == ['C4', 'C5', 'C10', 'C9', 'C7', 'C8', 'C6', 'C2', 'C3']
    assert get_nodes_display_names(cls_node_map["C2"].descendants) == ['C4', 'C5']
    assert get_nodes_display_names(cls_node_map["C3"].descendants) == ['C10', 'C9', 'C7', 'C8', 'C6']
    assert get_nodes_display_names(cls_node_map["C4"].descendants) == []
    assert get_nodes_display_names(cls_node_map["C5"].descendants) == []
    assert get_nodes_display_names(cls_node_map["C6"].descendants) == ['C10', 'C9', 'C7', 'C8']
    assert get_nodes_display_names(cls_node_map["C7"].descendants) == ['C10', 'C9']
    assert get_nodes_display_names(cls_node_map["C8"].descendants) == ['C10', 'C9']
    assert get_nodes_display_names(cls_node_map["C9"].descendants) == ['C10']
    assert get_nodes_display_names(cls_node_map["C10"].descendants) == []


@patch('os.getcwd', lambda: os.path.join(SCRIPT_DIR, "test_examples/node_reuse"))
def test_node_reuse(clang_config):
    clang_cfg = copy.deepcopy(clang_config)
    clang_cfg['src_glob'] = [os.path.join(os.getcwd(), '*.hpp')]

    ir = RootNode()
    parser = CXXParser(filter_=CXXIegFilter(ir))
    ir_builder = CXXIEGIRBuilder(ir, ContextManager(ContextDescriptor(None), 'linux', 'swift'))

    ir_builder.start_root()
    parser.parse(ir_builder, **clang_cfg)
    ir_builder.end_root()

    incl_file_node, main_file_node = ir.children[0].children
    incl_ns_node_from_main, incl_cls_node_from_main, incl_func_node_from_main, main_ns_node = main_file_node.children
    incl_ns_node, incl_cls_node, incl_func_node = incl_file_node.children

    assert incl_ns_node is incl_ns_node_from_main, "two namespaces from the same file are not equivalent"
    assert main_ns_node is not incl_ns_node, "two namespaces from different files are equivalent"

    assert incl_cls_node is incl_cls_node_from_main, "two function nodes from the same file are not equivalent"
    assert incl_func_node is incl_func_node_from_main, "two function nodes from different files are equivalent"


def test_shared_ref():
    with pytest.raises(IEGError, match=r"Child_A ancestors have different values for shared_ref variable"):
        ctx_desc = ContextDescriptor("*/**/shared_ref.yaml")
        WrapperGenerator.run_for('linux', 'swift', ctx_desc, None)
