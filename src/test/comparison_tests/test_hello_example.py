import os
import shutil
import unittest

from iegen.common.config import config
from test.comparison_tests.base import ComparisonTestsBaseClass

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestHelloExampleFilesIdentical(ComparisonTestsBaseClass, unittest.TestCase):

    def __init__(self, methodName='runTest'):
        source_glob = 'cxx/*iegen.yaml'
        examples_dir = os.path.abspath(os.path.join(SCRIPT_DIR, '../../../examples/tutorials/hello_user/'))
        ComparisonTestsBaseClass.__init__(self, examples_dir=examples_dir,
                                          source_glob=source_glob)
        unittest.TestCase.__init__(self, methodName=methodName)

    def setUp(self) -> None:
        super().setUp()
        # copy example sources and config
        shutil.copytree(os.path.join(self.examples_root, 'cxx'), './cxx')
        shutil.copyfile(os.path.join(self.examples_root, 'iegen_config.cfg'), './iegen_config.cfg')


if __name__ == '__main__':
    unittest.main()
