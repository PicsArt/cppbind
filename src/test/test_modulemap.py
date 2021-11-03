import difflib
import os
import shutil
import sys
import types
import unittest
from unittest.mock import Mock

from iegen.common.config import config
from iegen.context_manager.ctx_desc import ContextDescriptor
from iegen.runner import run
from .utils import filter_iegen_date_line

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestModulemap(unittest.TestCase):

    def setUp(self) -> None:
        self.test_dir = os.getcwd()
        self.example_root = os.path.join(SCRIPT_DIR, '../../examples/features/modulemap/HelloExample/HelloExample')
        config.application.context_def_glob = 'cxx/*iegen.yaml'
        os.makedirs('tmp')
        os.chdir('tmp')
        shutil.copytree(os.path.join(self.example_root, 'cxx'), './cxx')

    def tearDown(self) -> None:
        del config.application.context_def_glob
        os.chdir(self.test_dir)
        shutil.rmtree('tmp')

    def test_modulmaps_are_identical(self):
        ctx_desc = ContextDescriptor(config.application.context_def_glob)
        # mock to return all variables(including modulemap variables)
        ContextDescriptor.get_var_def = Mock(return_value=ctx_desc._ContextDescriptor__var_def)
        # run iegen
        run(types.SimpleNamespace(plat_lang_options=['swift']), ctx_desc)
        modulemap_name = 'public.modulemap'
        generated_modulemap = f'./{modulemap_name}'
        example_modulemap = os.path.join(self.example_root, modulemap_name)
        # compare modulemap is identical to the example
        with open(generated_modulemap, "rt") as f1, open(example_modulemap, "rt") as f2:
            f1 = filter(filter_iegen_date_line, f1)
            f2 = filter(filter_iegen_date_line, f2)
            identical = all(x == y for x, y in zip(f1, f2))
            if not identical:
                sys.stderr.write(f'Different modulemaps: {generated_modulemap} - {example_modulemap}\n')
                sys.stderr.writelines(difflib.unified_diff(
                    open(generated_modulemap, "rt").readlines(),
                    open(example_modulemap, "rt").readlines()))
                raise AssertionError


if __name__ == '__main__':
    unittest.main()
