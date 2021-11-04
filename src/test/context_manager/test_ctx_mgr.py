import os
import unittest
from unittest.mock import Mock, patch

from iegen.context_manager.ctx_desc import ContextDescriptor
from iegen.context_manager.ctx_mgr import ContextManager

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestContextManager(unittest.TestCase):

    def setUp(self) -> None:
        self.config_file = SCRIPT_DIR + '/test_examples/api_rules_dir/positive/with_null_values/iegen.yaml'
        self.ctx_descriptor = ContextDescriptor(self.config_file)
        # mock to return correct variables from config file
        self.var_def_patch = patch("iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def",
                                   new=Mock(return_value=self.ctx_descriptor._ContextDescriptor__var_def))
        self.var_def_patch.start()
        self.ctx_manager = ContextManager(self.ctx_descriptor, 'linux', 'kotlin')

    def tearDown(self) -> None:
        self.var_def_patch.stop()

    def test_evaluated_variable_values(self):
        root_ctx = {}
        root_api, root_args = self.ctx_manager.eval_root_attrs(root_ctx, {})
        # var_a default null value e.g. None
        assert root_args['var_a'] is None
        # var_b defined null value e.g. None
        assert root_args['var_b'] is None
        # var_c defined non null value
        assert root_args['var_c'] == 'CValue'
        # var_d not defined and has no default value
        assert 'var_d' not in root_args
        # var_e not defined has non null default value
        assert root_args['var_e'] == 'EDefault'
        # var_f not defined and has no default value
        assert 'var_f' not in root_args
        # var_g defined non null value
        assert root_args['var_g'] == 'GValue'

        # assert inherited and non inherited child values
        dir_ctx = {**root_args}
        dir_name = os.path.dirname(os.path.relpath(self.config_file, '.'))
        dir_api, dir_args = self.ctx_manager.eval_dir_attrs(dir_name, dir_ctx)

        # var_a inherited default null value e.g. None
        assert dir_args['var_a'] is None
        # var_b inherited defined null value e.g. None
        assert dir_args['var_b'] is None
        # var_c inherited defined non null value
        assert dir_args['var_c'] == 'CValue'
        # var_e defined has non null value
        assert dir_args['var_e'] == 'EValue'
        # var_d defined null value
        assert dir_args['var_d'] is None
        # var_f not defined and has no default value
        assert 'var_f' not in dir_args
        # var_g undefined, does not have a default and is not inherited
        assert 'var_g' not in dir_args
