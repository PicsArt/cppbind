import unittest
from enums.color_pygen import Color


class TestEnums(unittest.TestCase):

    def test_value(self):
        self.assertEqual(Color.Red.value, 1)
        self.assertEqual(Color.Green.value, 2)
        self.assertEqual(Color.Blue.value, 20)


if __name__ == '__main__':
    unittest.main()
