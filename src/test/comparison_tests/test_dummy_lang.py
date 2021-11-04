import os
import shutil
import unittest
from unittest.mock import patch, Mock

from iegen.context_manager.ctx_desc import ContextDescriptor
from .base import ComparisonTestsBaseClass

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class TestDummyLang(unittest.TestCase, ComparisonTestsBaseClass):

    def __init__(self, methodName='runTest'):
        ctx_descriptor = ContextDescriptor(os.path.join(SCRIPT_DIR,
                                                        '../../../examples/tests/my_lang_iegen.yaml'))
        unittest.TestCase.__init__(self, methodName=methodName)
        ComparisonTestsBaseClass.__init__(self,
                                          examples_dir=os.path.join(SCRIPT_DIR, '../../../examples/tests/'),
                                          ctx_descriptor=ctx_descriptor,
                                          languages=['my_lang'])

    def setUp(self) -> None:
        self.var_def_patch = patch("iegen.context_manager.ctx_desc.ContextDescriptor.get_var_def",
                                   new=Mock(return_value=self.ctx_descriptor._ContextDescriptor__var_def))
        self.var_def_patch.start()
        os.makedirs('tmp')
        os.chdir('tmp')
        shutil.copytree(os.path.join(SCRIPT_DIR, '../../../examples/tests/cxx'), './cxx')

    def tearDown(self) -> None:
        self.var_def_patch.stop()
        os.chdir(self.test_dir)
        shutil.rmtree('tmp')


if __name__ == '__main__':
    unittest.main()
