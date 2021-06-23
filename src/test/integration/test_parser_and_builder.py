import copy
import datetime
import os
from unittest.mock import patch, MagicMock

from iegen import default_config
from iegen.builder.ir_builder import CXXIEGIRBuilder
from iegen.context_manager.ctx_desc import ContextDescriptor
from iegen.context_manager.ctx_mgr import ContextManager
from iegen.ir.ast import NodeType, Node
from iegen.parser.ieg_parser import CXXParser

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
CXX_INPUTS_REL_PATH = '../test_cxx_inputs'


@patch('os.getcwd', lambda: SCRIPT_DIR)
def test_parser_with_dir_api(parser_config, clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    dir_example_folder = 'dir_api_example'
    api_rules_dir = os.path.abspath(os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH))

    plat, lang = 'linux', 'python'

    clang_cfg['src_glob'] = [os.path.abspath(os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH, dir_example_folder, '*.h'))]
    context_def_glob = os.path.join(api_rules_dir, dir_example_folder, '*.yaml')

    parser = CXXParser(parser_config=parser_config)
    ctx_desc = ContextDescriptor(context_def_glob)
    ctx_mgr = ContextManager(ctx_desc, plat, lang)

    processor = CXXIEGIRBuilder(ctx_mgr)
    processor._get_modification_time = MagicMock(return_value=datetime.datetime.utcnow())
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
def test_parser_with_file_api(parser_config, clang_config):
    clang_cfg = copy.deepcopy(clang_config)

    file_example_folder = 'file_api_example'

    api_rules_dir = os.path.abspath(os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH))
    clang_cfg['src_glob'] = [os.path.abspath(os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH, file_example_folder, '*.h'))]

    plat, lang = 'linux', 'python'
    context_def_glob = os.path.join(api_rules_dir, file_example_folder, '*.yaml')

    parser = CXXParser(parser_config=parser_config)
    ctx_desc = ContextDescriptor(context_def_glob)
    ctx_mgr = ContextManager(ctx_desc, plat, lang)
    processor = CXXIEGIRBuilder(ctx_mgr)
    processor._get_modification_time = MagicMock(return_value=datetime.datetime.utcnow())

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
