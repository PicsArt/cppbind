import unittest
from operators.counter_pygen import Counter


class TestOperators(unittest.TestCase):

    def setUp(self) -> None:
        self.counter1 = Counter(1)
        self.counter2 = Counter(7)

    def test_add(self):
        res = self.counter1 + self.counter2
        self.assertEqual(res.count, 8)

    def test_iadd(self):
        self.counter1 += self.counter2
        self.assertEqual(self.counter1.count, 8)

    def test_greater(self):
        self.assertGreater(self.counter2, self.counter1)


if __name__ == '__main__':
    unittest.main()
