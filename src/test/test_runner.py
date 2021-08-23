from types import SimpleNamespace
from unittest import mock, TestCase

from iegen.common.error import IEGError
from iegen.runner import run


class TestRunner(TestCase):

    def test_run(self):
        args = SimpleNamespace(plat_lang_options=[])

        # positive test case
        run(args, None)

        # negative test case
        with mock.patch('iegen.runner.WrapperGenerator.run') as run_mock:
            run_mock.side_effect = IEGError('iegen error')
            with self.assertRaises(SystemExit):
                run(args, None)
