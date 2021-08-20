import os
import unittest

import yaml

from iegen.common.yaml_process import YamlNode, YamlKeyDuplicationError
from iegen.context_manager.ctx_desc import ContextDescriptor
from iegen.ir.ast import RootNode

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestContextDescriptor(unittest.TestCase):

    def setUp(self) -> None:
        self.yaml_path = SCRIPT_DIR + '/data/test_prj/iegen.yaml'
        self.ctx_desc = ContextDescriptor(self.yaml_path, 'linux', 'kotlin')

    def test_config_is_loaded(self):
        # positive test case
        # asserts config is properly loaded
        # root section
        root_section = self.ctx_desc.ctx_def_map[RootNode.ROOT_KEY]
        self.assertEquals(root_section.file, self.yaml_path)
        self.assertEquals(root_section.line_number, 1)
        value = yaml.load(root_section.value)
        self.assertEquals(value['out_prj_dir'], ".")
        self.assertEquals(value['src_glob'], ['./**/*.h*'])
        self.assertEquals(value['src_exclude_glob'], [])

        # var_def section
        var_def_section = self.ctx_desc.ctx_def_map[ContextDescriptor.VAR_DEF_SECTION_KEY]
        self.assertEquals(var_def_section.file, self.yaml_path)
        self.assertEquals(var_def_section.line_number, 7)
        value = var_def_section.value
        self.assertEquals(value['action'].file, self.yaml_path)
        self.assertEquals(value['action'].line_number, 8)
        self.assertEquals(value['action'].value['default'], None)

        # rules section
        code_snippets = self.ctx_desc.ctx_def_map[ContextDescriptor.CODE_SNIPPETS_KEY]
        self.assertEquals(code_snippets['class'].value, 'Class Test')
        type_converters = self.ctx_desc.ctx_def_map[ContextDescriptor.TYPE_CONVERTER_SNIPPETS_KEY]
        self.assertEquals(type_converters, {})

    def test_vars_should_be_unique(self):
        # negative case
        # asserts that an error is thrown when vars key is defined twice
        self._assert_duplicate_error_is_raised(self.ctx_desc.ROOT_SECTION_KEY)

    def test_var_def_should_be_unique(self):
        # negative case
        # asserts that an error is thrown when var_def key is defined twice
        self._assert_duplicate_error_is_raised(self.ctx_desc.VAR_DEF_SECTION_KEY)

    def _assert_duplicate_error_is_raised(self, key):
        file = 'test.iegen.yaml'
        line = 1
        # assert YamlKeyDuplicationError is thrown when key which should be unique is defined in two files
        with self.assertRaises(YamlKeyDuplicationError) as ctx:
            # ctx_desc ctx_def_map already contains <key>, pass new attributes with the same key to raise an error
            self.ctx_desc.load_merge_ctx_def_map({key: YamlNode('value', line, file)}, self.ctx_desc.ctx_def_map)
        # assert error message
        self.assertTrue(f"Redefinition of '{key}' section in line {line} of {file}" in str(ctx.exception))
