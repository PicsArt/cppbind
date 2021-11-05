import os
import shutil
import unittest

from test.comparison_tests.base import ComparisonTestsBaseClass

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestModulemap(ComparisonTestsBaseClass, unittest.TestCase):

    def __init__(self, methodName='runTest'):
        examples_dir = os.path.abspath(os.path.join(SCRIPT_DIR,
                                                    '../../../examples/features/modulemap/HelloExample/HelloExample'))
        source_glob = 'cxx/*iegen.yaml'
        ComparisonTestsBaseClass.__init__(self,
                                          examples_dir=examples_dir,
                                          source_glob=source_glob,
                                          languages=['swift'])
        unittest.TestCase.__init__(self, methodName=methodName)

    def setUp(self) -> None:
        super().setUp()
        shutil.copytree(os.path.join(self.examples_root, 'cxx'), './cxx')


if __name__ == '__main__':
    unittest.main()
