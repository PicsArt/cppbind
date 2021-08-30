import hashlib
import os
import unittest
from collections import OrderedDict

import yaml

from iegen.common.yaml_process import YamlNode, YamlKeyDuplicationError, yaml_info_struct_to_dict
from iegen.context_manager.ctx_desc import ContextDescriptor
from iegen.ir.ast import RootNode

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestContextDescriptor(unittest.TestCase):

    def setUp(self) -> None:
        self.initial_config_file = SCRIPT_DIR + '/test_examples/api_rules_dir/positive/with_vars_var_def/iegen.yaml'
        self.ctx_desc = ContextDescriptor(self.initial_config_file)
        self.negative_rules_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'api_rules_dir', 'negative')
        self.positive_rules_dir = os.path.join(SCRIPT_DIR, 'test_examples', 'api_rules_dir', 'positive')

    def test_initial_config_is_loaded(self):
        # positive test case
        # asserts config is properly loaded
        # root section
        root_section = self.ctx_desc.get_yaml_api(RootNode.ROOT_KEY)
        self.assertEqual(root_section.file, self.initial_config_file)
        self.assertEqual(root_section.line_number, 1)
        value = yaml.load(root_section.value, Loader=yaml.SafeLoader)
        self.assertEqual(value['out_prj_dir'], '.')
        self.assertEqual(value['src_glob'], ['./**/*.h*'])
        self.assertEqual(value['src_exclude_glob'], [])

        # var_def section
        var_def_section = self.ctx_desc.get_yaml_api(ContextDescriptor.VAR_DEF_SECTION_KEY)
        self.assertEqual(var_def_section.file, self.initial_config_file)
        self.assertEqual(var_def_section.line_number, 7)
        value = var_def_section.value
        self.assertEqual(value['action'].file, self.initial_config_file)
        self.assertEqual(value['action'].line_number, 8)
        self.assertEqual(value['action'].value['default'], None)

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
            self.ctx_desc.load_merge_ctx_def_map({key: YamlNode('value', line, file)},
                                                 self.ctx_desc._ContextDescriptor__ctx_def_map)
        # assert error message
        self.assertTrue(f"Redefinition of '{key}' section in line {line} of {file}" in str(ctx.exception))

    def test_rules_merge_conflict_and_redefinition(self):
        # negative test case
        # asserts an YamlKeyDuplicationError is raised when there's a merge conflict or redefinition of a type api
        folders = ['with_merge_conflict', 'with_duplicate_in_two_files', 'with_duplicate_in_the_same_file']
        for folder in folders:
            context_def_glob = os.path.join(self.negative_rules_dir, folder, '*.yaml')
            with self.assertRaises(YamlKeyDuplicationError):
                self.ctx_desc.build_ctx_def_map(context_def_glob)

    def test_rules_load_with_yaml_error(self):
        # negative test case
        # asserts YAMLError is thrown when there's problem with yaml format
        context_def_glob = os.path.join(self.negative_rules_dir, 'with_invalid_yaml_format', '*.yaml')
        with self.assertRaises(yaml.YAMLError):
            self.ctx_desc.build_ctx_def_map(context_def_glob)

    def test_different_configs_loaded(self):
        # positive test case
        # asserts config is properly loaded for different scenarios
        results = {
            'with_many_files': 'a176d1e4fee490bdd04f0749e654c836',
            'with_nested_cfg': 'be98d78aa365a5ea45a835ff2b11c737',
            'with_mixed_cfg': 'a176d1e4fee490bdd04f0749e654c836',
            'with_simple_cfg': '6d4025adf843640d3ecdcfb7522bfc8e',
            'with_jinja_expr': '46060b5c7a6b72174f7729e6ce2f1ca0'
        }

        for dir_, res_md5 in results.items():
            context_def_glob = os.path.join(self.positive_rules_dir, dir_, '*.yaml')
            res = yaml_info_struct_to_dict(self.ctx_desc.build_ctx_def_map(context_def_glob))

            ordered_res = OrderedDict()
            for key in sorted(res.keys()):
                ordered_res[key] = res[key]

            self.assertEqual(hashlib.md5(str(ordered_res).encode()).hexdigest(), res_md5,
                             'External API parser results has bean changed.')

    def test_external_api_merging_positive(self):
        # positive test case
        # asserts rules are properly merged from different files
        context_def_glob = os.path.join(self.positive_rules_dir, 'with_snippets_rules', '*.yaml')
        res = yaml_info_struct_to_dict(self.ctx_desc.build_ctx_def_map(context_def_glob))

        self.assertEqual(res.get('code_snippets'), None, 'External API parser results has bean changed.')
        self.assertEqual(res.get('actions'), None, 'External API parser results has bean changed.')
        print(res)
        self.assertEqual(res['type_converters']['python']['linux'],
                         {'a': {'f': {'g': {'h': 1}}, 'b': {'c': {'e': 1, 'd': ['e', 'f']}}}},
                         'External API parser results has bean changed.')
