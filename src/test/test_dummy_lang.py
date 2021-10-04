import difflib
import os
import shutil
import sys
import types
import unittest

from iegen.context_manager.ctx_desc import ContextDescriptor
from iegen.runner import run

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestDummyLang(unittest.TestCase):
    def setUp(self) -> None:
        self.test_dir = os.getcwd()
        self.gen_root = './%s/'
        self.examples_root = os.path.join(SCRIPT_DIR, '../../examples/tests/%s/')
        TestDummyLang._prepare_config_and_examples()

    def tearDown(self) -> None:
        os.chdir(self.test_dir)
        shutil.rmtree('tmp')

    def test_dummy_lang(self):
        run(types.SimpleNamespace(plat_lang_options=['my_lang']),
            ContextDescriptor('../examples/tests/my_lang_iegen.yaml'))

        gen_root = self.gen_root % 'my_lang'
        examples_root = self.examples_root % 'my_lang'
        for root, _, files in os.walk(gen_root):
            common_path = root[len(gen_root):]
            for file in files:
                examples_file = os.path.join(examples_root, common_path, file)
                gen_file = os.path.join(root, file)
                print(f'comparing {examples_file}, {gen_file}')
                with open(examples_file, "rt") as f1, open(gen_file, "rt") as f2:
                    identical = all(x == y for x, y in zip(f1, f2))
                    if not identical:
                        sys.stderr.write(f'Diff for {gen_file} - {examples_file}\n')
                        sys.stderr.writelines(difflib.unified_diff(
                            open(examples_file, "rt").readlines(),
                            open(gen_file, "rt").readlines()))
                        raise AssertionError

    @staticmethod
    def _prepare_config_and_examples():
        os.makedirs('tmp')
        os.chdir('tmp')
        shutil.copytree(os.path.join(SCRIPT_DIR, '../../examples/tests/cxx'), './cxx')


if __name__ == '__main__':
    unittest.main()
