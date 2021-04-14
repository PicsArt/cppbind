import unittest
from getters.person_pygen import Person


class TestPerson(unittest.TestCase):

    def setUp(self) -> None:
        self.person = Person("John Doe")

    def test_fullname(self):
        self.assertEqual(self.person.full_name, "John Doe")
        self.person.full_name = "Jane Doe"
        self.assertEqual(self.person.full_name, "Jane Doe")


if __name__ == '__main__':
    unittest.main()
