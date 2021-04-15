import unittest
from classes.project_pygen import Project
from project_usage import create_project


class TestSimpleClasses(unittest.TestCase):

    def test_usage(self):
        create_project()


if __name__ == '__main__':
    unittest.main()
