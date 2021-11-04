import os
import shutil
import unittest

from iegen.context_manager.ctx_desc import ContextDescriptor
from test.comparison_tests.base import ComparisonTestsBaseClass

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestFilesIdentical(unittest.TestCase, ComparisonTestsBaseClass):

    def __init__(self, methodName='runTest'):
        ctx_descriptor = ContextDescriptor('../../../examples/primitives/cxx/**/*iegen.yaml')
        unittest.TestCase.__init__(self, methodName=methodName)
        ComparisonTestsBaseClass.__init__(self, examples_dir=os.path.join(SCRIPT_DIR, '../../../examples/primitives/'),
                                          ctx_descriptor=ctx_descriptor)

    def setUp(self) -> None:
        os.makedirs('tmp')
        os.chdir('tmp')
        # copy example sources and config
        shutil.copytree(os.path.join(SCRIPT_DIR, '../../../examples/primitives/cxx'), './cxx')
        shutil.copyfile(os.path.join(SCRIPT_DIR, '../../../examples/primitives/iegen_config.cfg'), './iegen_config.cfg')

    def tearDown(self) -> None:
        os.chdir(self.test_dir)
        # clear all generate file
        shutil.rmtree('tmp')


if __name__ == '__main__':
    unittest.main()
