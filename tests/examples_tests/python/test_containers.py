import unittest
from containers.containers_pygen import Containers


class TestContainersMap(unittest.TestCase):

    def setUp(self) -> None:
        self.map = Containers()

    def test_add_str_pair(self):
        self.map.add_string_pair(('info1', 'value1'))
        str_map = self.map.get_string_map()
        self.assertEqual(str_map['info1'], 'value1')
        self.assertEqual(len(str_map), 1)

    def test_add_str_pair_should_fail_with_non_str(self):
        with self.assertRaises(TypeError) as context:
            self.map.add_string_pair((1, 2))

        self.assertTrue('incompatible function arguments' in str(context.exception))

    def test_add_str_map(self):
        self.map.add_string_map({'a': 'a value', 'b': 'b value'})
        str_map = self.map.get_string_map()
        self.assertEqual(str_map['a'], 'a value')
        self.assertIn('a', str_map)
        self.assertIn('b', str_map)

    def test_add_str_map_should_fail_with_non_str(self):
        with self.assertRaises(TypeError) as context:
            self.map.add_string_map({1: 2})

        self.assertTrue('incompatible function arguments' in str(context.exception))


if __name__ == '__main__':
    unittest.main()
