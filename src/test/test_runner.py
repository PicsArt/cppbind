from types import SimpleNamespace
from unittest import mock, TestCase

from iegen.runner import run


class TestRunner(TestCase):

    def test_run(self):
        args = SimpleNamespace(languages=[])

        # positive test case
        run(args)

        # negative test case
        with mock.patch('iegen.runner.WrapperGenerator.run') as run_mock:
            run_mock.side_effect = Exception('iegen error')
            with self.assertRaises(SystemExit) as ctx:
                run(args)


