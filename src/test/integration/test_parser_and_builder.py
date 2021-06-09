import copy
import os
from unittest.mock import patch

from iegen import default_config
from iegen.builder.ir_builder import CXXIEGIRBuilder
from iegen.ir.ast import NodeType, Node
from iegen.parser.ieg_api_parser import APIParser
from iegen.parser.ieg_parser import CXXParser

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))
CXX_INPUTS_REL_PATH = '../test_cxx_inputs'


@patch('os.getcwd', lambda: SCRIPT_DIR)
def test_parser_with_dir_api(parser_config):
    dir_example_folder = 'dir_api_example'

    api_rules_dir = os.path.abspath(os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH))
    config = copy.deepcopy(parser_config)
    config.src_glob = os.path.abspath(os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH, dir_example_folder, '*.h'))

    config.api_type_attributes_glob = os.path.join(api_rules_dir, dir_example_folder, '*.yaml')
    # load yaml file api
    APIParser(attributes=default_config.attributes,
              api_start_kw=default_config.attributes,
              parser_config=config)

    parser = CXXParser(parser_config=config)

    processor = CXXIEGIRBuilder(attributes=default_config.attributes,
                                api_start_kw=default_config.api_start_kw,
                                parser_config=config)

    parser.parse(processor)

    assert len(processor.ir.roots) == 1
    root = processor.ir.roots[0]
    assert root.type is NodeType.DIRECTORY_NODE
    assert root.name == CXX_INPUTS_REL_PATH
    assert len(root.children) == 1
    dir_node = root.children[0]
    assert dir_node.type == NodeType.DIRECTORY_NODE
    assert dir_node.api == 'package'
    assert dir_node.name == f'{CXX_INPUTS_REL_PATH}/{dir_example_folder}'


@patch('os.getcwd', lambda: SCRIPT_DIR)
def test_parser_with_file_api(parser_config):
    file_example_folder = 'file_api_example'

    api_rules_dir = os.path.abspath(os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH))
    config = copy.deepcopy(parser_config)
    config.src_glob = os.path.abspath(os.path.join(SCRIPT_DIR, CXX_INPUTS_REL_PATH, file_example_folder, '*.h'))

    config.api_type_attributes_glob = os.path.join(api_rules_dir, file_example_folder, '*.yaml')
    # load yaml file api
    APIParser(attributes=default_config.attributes,
              api_start_kw=default_config.attributes,
              parser_config=config)

    parser = CXXParser(parser_config=config)

    processor = CXXIEGIRBuilder(attributes=default_config.attributes,
                                api_start_kw=default_config.api_start_kw,
                                parser_config=config)

    parser.parse(processor)
    assert len(processor.ir.roots) == 1
    root = processor.ir.roots[0]
    assert root.type is NodeType.DIRECTORY_NODE
    assert root.name == CXX_INPUTS_REL_PATH
    assert len(root.children) == 1
    dir_node = root.children[0]
    assert dir_node.type == NodeType.DIRECTORY_NODE
    assert dir_node.api is None
    assert dir_node.name == f'{CXX_INPUTS_REL_PATH}/{file_example_folder}'
    assert len(dir_node.children) == 1
    file_node = dir_node.children[0]
    assert file_node.api == Node.API_NONE
    assert file_node.type == NodeType.FILE_NODE
