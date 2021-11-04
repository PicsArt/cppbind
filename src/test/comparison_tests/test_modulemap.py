import os
import shutil
import unittest
from unittest.mock import Mock, patch

from iegen.common.config import config
from iegen.context_manager.ctx_desc import ContextDescriptor
from test.comparison_tests.base import ComparisonTestsBaseClass

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestModulemap(unittest.TestCase, ComparisonTestsBaseClass):

    def __init__(self, methodName='runTest'):
        examples_dir = os.path.join(SCRIPT_DIR, '../../../examples/features/modulemap/HelloExample/HelloExample')
        ctx_descriptor = ContextDescriptor(os.path.join(examples_dir, 'cxx/*iegen.yaml'))
        unittest.TestCase.__init__(self, methodName=methodName)
        ComparisonTestsBaseClass.__init__(self,
                                          examples_dir=examples_dir,
                                          ctx_descriptor=ctx_descriptor,
                                          languages=['swift'])

    def setUp(self) -> None:
        self.var_def_patch = patch("iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def",
                                   new=Mock(return_value=self.ctx_descriptor._ContextDescriptor__var_def))
        self.var_def_patch.start()
        os.makedirs('tmp')
        os.chdir('tmp')
        shutil.copytree(os.path.join(self.examples_root, 'cxx'), './cxx')

    def tearDown(self) -> None:
        self.var_def_patch.stop()
        del config.application.context_def_glob
        os.chdir(self.test_dir)
        shutil.rmtree('tmp')


if __name__ == '__main__':
    unittest.main()
