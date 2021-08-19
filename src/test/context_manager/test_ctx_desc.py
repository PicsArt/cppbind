import os
import unittest
from iegen.context_manager.ctx_desc import ContextDescriptor
from iegen.common.yaml_process import YamlNode, YamlKeyDuplicationError

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))

class TestContextDescriptor(unittest.TestCase):

    def setUp(self) -> None:
        self.ctx_desc = ContextDescriptor(SCRIPT_DIR + '/data/test_prj/iegen.yaml', 'linux', 'kotlin')

    def test_vars_should_be_unique(self):
        self._assert_duplicate_error_is_raised(self.ctx_desc.ROOT_SECTION_KEY)

    def test_var_def_should_be_unique(self):
        self._assert_duplicate_error_is_raised(self.ctx_desc.VAR_DEF_SECTION_KEY)

    def _assert_duplicate_error_is_raised(self, key):
        file = 'test.iegen.yaml'
        line = 1
        with self.assertRaises(YamlKeyDuplicationError) as ctx:
            self.ctx_desc.load_merge_ctx_def_map({key: YamlNode('value', line, file)}, self.ctx_desc.ctx_def_map)
        self.assertTrue(f"Redefinition of '{key}' section in line {line} of {file}" in str(ctx.exception))