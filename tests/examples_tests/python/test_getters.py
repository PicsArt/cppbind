import unittest
from getters.getter_pygen import GetterSetter, GetterSetterExtended


class TestContainersMap(unittest.TestCase):

    def setUp(self) -> None:
        self.gs = GetterSetter()
        self.gse = GetterSetterExtended()

    def test_value(self):
        self.assertEqual(self.gs.value, "default value")
        self.gs.value = "updated value"
        self.assertEqual(self.gs.value, "updated value")

    def test_inherited_value(self):
        self.assertEqual(self.gse.value, "default value")
        self.gse.value = "updated value"
        self.assertEqual(self.gse.value, "updated value")


if __name__ == '__main__':
    unittest.main()
