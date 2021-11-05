import os
import shutil
import unittest

from .base import ComparisonTestsBaseClass

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestDummyLang(ComparisonTestsBaseClass, unittest.TestCase):

    def __init__(self, methodName='runTest'):
        source_glob = '**/*iegen.yaml'
        examples_dir = os.path.join(SCRIPT_DIR, '../../../examples/tests/')
        ComparisonTestsBaseClass.__init__(self,
                                          examples_dir=examples_dir,
                                          source_glob=source_glob,
                                          languages=['my_lang'])
        unittest.TestCase.__init__(self, methodName=methodName)

    def setUp(self) -> None:
        super().setUp()
        shutil.copytree(os.path.join(self.examples_root, 'cxx'), './cxx')
        shutil.copytree(os.path.join(self.examples_root, 'my_lang_snippets'), './my_lang_snippets')
        shutil.copyfile(os.path.join(self.examples_root, 'my_lang_iegen.yaml'), './my_lang_iegen.yaml')


if __name__ == '__main__':
    unittest.main()
