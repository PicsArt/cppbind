import os
import shutil
import unittest

from .utils import RunCompare

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestDummyLang(unittest.TestCase):
    """Runs cppbind for dummy language examples and compares generated bindings with the examples."""

    def __init__(self, methodName='runTest'):
        super().__init__(methodName=methodName)
        self.examples_root = os.path.join(SCRIPT_DIR, '../../../examples/tests/')
        self.runner = RunCompare(examples_root=self.examples_root,
                                 source_glob='**/*cppbind.yaml',
                                 languages=['my_lang'])

    def setUp(self) -> None:
        self.runner.setup()
        # copy example sources and config to current tmp directory
        shutil.copytree(os.path.join(self.examples_root, 'cxx'), './cxx')
        shutil.copytree(os.path.join(self.examples_root, 'my_lang_snippets'), './my_lang_snippets')
        shutil.copyfile(os.path.join(self.examples_root, 'my_lang_cppbind.yaml'), './my_lang_cppbind.yaml')

    def tearDown(self) -> None:
        self.runner.teardown()

    def test_run_compare(self):
        # run cppbind
        self.runner.run()
        # compare generated bindings with golden ones
        self.runner.compare()


if __name__ == '__main__':
    unittest.main()
