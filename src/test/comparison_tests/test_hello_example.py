import os
import shutil
import unittest
from unittest.mock import patch, Mock

from iegen.context_manager.ctx_desc import ContextDescriptor
from test.comparison_tests.base import ComparisonTestsBaseClass

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestHelloExampleFilesIdentical(unittest.TestCase, ComparisonTestsBaseClass):

    def __init__(self, methodName='runTest'):
        ctx_descriptor = ContextDescriptor('../../../examples/tutorials/hello_user/cxx/*iegen.yaml')
        unittest.TestCase.__init__(self, methodName=methodName)
        ComparisonTestsBaseClass.__init__(self, examples_dir=os.path.join(SCRIPT_DIR,
                                                                          '../../../examples/tutorials/hello_user/'),
                                          ctx_descriptor=ctx_descriptor)

    def setUp(self) -> None:
        self.var_def_patch = patch("iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def",
                                   new=Mock(return_value=self.ctx_descriptor._ContextDescriptor__var_def))
        self.var_def_patch.start()
        os.makedirs('tmp')
        os.chdir('tmp')
        # copy example sources and config
        shutil.copytree(os.path.join(SCRIPT_DIR, '../../../examples/tutorials/hello_user/cxx'), './cxx')
        shutil.copyfile(os.path.join(SCRIPT_DIR, '../../../examples/tutorials/hello_user/iegen_config.cfg'),
                        './iegen_config.cfg')

    def tearDown(self) -> None:
        self.var_def_patch.stop()
        os.chdir(self.test_dir)
        # clear all generate file
        shutil.rmtree('tmp')


if __name__ == '__main__':
    unittest.main()
