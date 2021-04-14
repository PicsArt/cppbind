import unittest
from overloads.overload_pygen import OverloadedFunctions


class TestOverloadedFunctions(unittest.TestCase):

    def setUp(self) -> None:
        self.overloaded = OverloadedFunctions()
        self.strings = ('1', '2', '3', '4')

    def test_overloaded_concatenate(self):
        res = self.overloaded.concatenate(*self.strings[:2])
        self.assertEqual(res, ''.join(self.strings[:2]))
        res = self.overloaded.concatenate(*self.strings[:3])
        self.assertEqual(res, ''.join(self.strings[:3]))

    def test_overloaded_concatenate_incorrect(self):
        with self.assertRaises(TypeError) as context:
            self.overloaded.concatenate(*self.strings)

        self.assertTrue('incompatible function arguments' in str(context.exception))


if __name__ == '__main__':
    unittest.main()
