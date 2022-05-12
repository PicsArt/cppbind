from types import SimpleNamespace
from unittest import mock, TestCase

from cppbind.common.error import CppBindError
from cppbind.runner import run


class TestRunner(TestCase):

    def test_run(self):
        args = SimpleNamespace(plat_lang_options=[])

        # positive test case
        run(args, None)

        # negative test case
        with mock.patch('cppbind.runner.WrapperGenerator.run') as run_mock:
            run_mock.side_effect = CppBindError('cppbind error')
            with self.assertRaises(SystemExit):
                run(args, None)
