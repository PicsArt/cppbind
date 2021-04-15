import unittest
import filecmp

import pytest


@pytest.mark.parametrize(
    'golden_file, new_gen_file',
    [
        (
                'examples/python/src/operators/counter_pygen.py',
                'tests/examples_tests/python/src/operators/counter_pygen.py',
        ),
        (
                'examples/python/src/overloads/overload_pygen.py',
                'tests/examples_tests/python/src/overloads/overload_pygen.py',
        ),
        (
                'examples/python/src/templates/stack_pygen.py',
                'tests/examples_tests/python/src/templates/stack_pygen.py',
        ),
        (
                'examples/python/src/templates/stack_usage_pygen.py',
                'tests/examples_tests/python/src/templates/stack_usage_pygen.py',
        ),
        (
                'examples/python/src/getters/person_pygen.py',
                'tests/examples_tests/python/src/getters/person_pygen.py',
        ),

    ],
)
def test_py_files(golden_file, new_gen_file):
    assert filecmp.cmp(golden_file, new_gen_file) is True


# @pytest.mark.parametrize(
#     'golden_file, new_gen_file',
#     [
#         (
#                 'examples/python/operators/counter_pygen.py',
#                 'tests/examples_tests/python/src/operators/counter_pygen.py',
#         ),
#         (
#                 'examples/python/overloads/overload_pygen.py',
#                 'tests/examples_tests/python/src/overloads/overload_pygen.py',
#         ),
#         (
#                 'examples/python/templates/stack_pygen.py',
#                 'tests/examples_tests/python/src/templates/stack_pygen.py',
#         ),
#         (
#                 'examples/python/templates/stack_usage_pygen.py',
#                 'tests/examples_tests/python/src/templates/stack_usage_pygen.py',
#         ),
#         (
#                 'examples/python/getters/person_pygen.py',
#                 'tests/examples_tests/python/src/getters/person_pygen.py',
#         ),
#
#     ],
# )
# def test_pybind_files(golden_file, new_gen_file):
#     assert filecmp.cmp(golden_file, new_gen_file) is True


if __name__ == '__main__':
    raise SystemExit(pytest.main([__file__]))
