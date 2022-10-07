import os
import unittest

from cppbind import PROJECT_CONFIG_DIR
from cppbind.common.error import CppBindError, Error
from cppbind.context_manager.ctx_desc import ContextDescriptor
from cppbind.runner import WrapperGenerator

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestContextDescriptor(unittest.TestCase):

    def setUp(self) -> None:
        Error.set_error_limit(0)

    # ---------- code snippets ---------- #
    def test_snippet_filepath_syntax_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/snippets/filepath.syntax.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 18, "
            f"msg -> Jinja syntax error in file:kotlin:file_path - unexpected 'end of print statement'"))

    def test_snippet_syntax_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/snippets/snippet.syntax.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 29, "
            f"msg -> Jinja syntax error in class:kotlin:body:content - unexpected 'end of print statement'"))

    def test_file_path_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/snippets/filepath.render.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 16, "
            f'msg -> Jinja render error in file:kotlin:file_path - expected str, bytes or os.PathLike object, '
            f'not StrictUndefined.'))

    def test_code_snippet_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/snippets/snippet.render.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 27, "
            f"msg -> Jinja render error in class:kotlin:body:content - 'types.SimpleNamespace object' has no attribute 'non_existing'."))

    # ---------- type converters ---------- #
    def test_type_load_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/converters/type.syntax.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 35, "
            f"msg -> Jinja syntax error in int:converters:kotlin_to_jdk - unexpected 'end of print statement'"))

    def test_type_converter_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/converters/type.converter.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 44, "
            "msg -> Jinja render error in int:converters:kotlin_to_jdk - expected str, "
            "bytes or os.PathLike object, not StrictUndefined."))

    def test_target_type_name_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/converters/type.info.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 38, "
            f"msg -> Jinja render error in int:types:kotlin - 'invalid' is undefined."))

    def test_type_custom_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/converters/type.custom.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 38, "
            "msg -> Jinja render error in int:custom:tname - 'invalid' is undefined."))

    # ---------- actions ---------- #
    def test_action_load_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/actions/action.syntax.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 31, "
            "msg -> Jinja syntax error in file:copy_to - unexpected 'end of statement block'"))

    def test_action_render_jinja_error(self):
        ctx_desc = ContextDescriptor(SCRIPT_DIR + '/test_examples/jinja_errors/actions/action.render.cppbind.yaml')

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {os.path.join(SCRIPT_DIR, 'test_examples/jinja_errors/utils.kt')}, "
            "line -> 1, "
            "msg -> Jinja syntax error - No filter named 'make_some_comment'."))

    def test_action_src_glob_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/actions/action.glob.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 27, "
            "msg -> Jinja render error in file:files_glob - join() argument must be str, bytes, or "
            "os.PathLike object, not 'StrictUndefined'."))

    def test_action_copy_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/actions/action.copy.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f'file -> {config_file}, '
            'line -> 29, '
            'msg -> Jinja render error in file:copy_to - expected str, '
            'bytes or os.PathLike object, not StrictUndefined.'))

    def test_action_variables_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/actions/action.variables.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 33, "
            "msg -> Jinja render error in file:variables:helper_includes - 'types.SimpleNamespace object' "
            "has no attribute 'helpers_package_prefixx'."))

    # ---------- variables ---------- #
    def test_variable_syntax_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/variables/var.syntax.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 4, "
            "msg -> Jinja syntax error in vars.src_glob - unexpected 'end of print statement'"))

    def test_variable_render_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/variables/var.render.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 4, "
            "msg -> Jinja render error in vars.src_glob - 'undefined' is undefined"))

    def test_variable_def_default_syntax_jinja_error(self):
        var_def_file = os.path.join(PROJECT_CONFIG_DIR, "variable_definitions.yaml")
        ctx_desc = ContextDescriptor(None)
        # update default value to be of invalid jinja syntax
        ctx_desc.get_var_def()['src_glob'].value['default'].value = ['{{"test" +}}']
        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {var_def_file}, "
            "line -> 278, "
            "msg -> Jinja syntax error in vars.src_glob - unexpected 'end of print statement'"))

    def test_variable_def_default_render_jinja_error(self):
        var_def_file = os.path.join(PROJECT_CONFIG_DIR, "variable_definitions.yaml")
        ctx_desc = ContextDescriptor(None)
        # update default value to use undefined variable
        ctx_desc.get_var_def()['src_glob'].value['default'].value = ['{{"test" + undefined}}']
        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {var_def_file}, "
            "line -> 278, "
            "msg -> Jinja render error in vars.src_glob - 'undefined' is undefined"))

    def test_variable_source_api_render_jinja_error(self):
        source_file = SCRIPT_DIR + '/test_examples/jinja_errors/api_var_render_example.hpp'
        ctx_desc = ContextDescriptor(None)
        # update src_glob value to use file with an invalid api
        ctx_desc.get_var_def()['src_glob'].value['default'].value = [source_file]

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {source_file}, "
            "line -> 5, "
            "msg -> Jinja render error in vars.action - 'undefined' is undefined"))

    def test_variable_source_api_syntax_jinja_error(self):
        source_file = SCRIPT_DIR + '/test_examples/jinja_errors/api_var_syntax_example.hpp'
        ctx_desc = ContextDescriptor(None)
        # update src_glob value to use file with an invalid api
        ctx_desc.get_var_def()['src_glob'].value['default'].value = [source_file]

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {source_file}, "
            "line -> 5, "
            "msg -> Jinja syntax error in vars.action - unexpected 'end of print statement'"))

    def test_variable_external_api_syntax_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/variables/var.syntax.external.api.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 11, "
            "msg -> Jinja syntax error in vars.action - unexpected 'end of print statement'"))

    def test_variable_external_api_render_jinja_error(self):
        config_file = SCRIPT_DIR + '/test_examples/jinja_errors/variables/var.render.external.api.cppbind.yaml'
        ctx_desc = ContextDescriptor(config_file)

        with self.assertRaises(CppBindError) as ctx:
            WrapperGenerator.run_for('linux', 'kotlin', ctx_desc, None)

        self.assertTrue(str(ctx.exception).endswith(
            f"file -> {config_file}, "
            "line -> 11, "
            "msg -> Jinja render error in vars.action - 'gen_class' is undefined"))
