import os
import shutil
import unittest

from test.comparison_tests.utils import RunCompare

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestArrayExampleFilesIdentical(unittest.TestCase):
    """Runs cppbind for array tutorial and compares generated bindings with the examples."""

    def __init__(self, methodName='runTest'):
        super().__init__(methodName=methodName)
        self.examples_root = os.path.abspath(os.path.join(SCRIPT_DIR, '../../../examples/tutorials/array/'))
        self.runner = RunCompare(examples_root=self.examples_root, working_dir='tmp_array')

    def setUp(self) -> None:
        self.runner.setup()
        # copy example sources and config to current tmp directory
        shutil.copytree(os.path.join(self.examples_root, 'cxx'), './cxx')
        shutil.copyfile(os.path.join(self.examples_root, 'cppbind.yaml'), './cppbind.yaml')
        self.runner.setup_config()

    def tearDown(self) -> None:
        self.runner.teardown()

    def test_run_compare(self):
        # run cppbind
        self.runner.run()
        # compare generated bindings with golden ones
        self.runner.compare()


if __name__ == '__main__':
    unittest.main()
