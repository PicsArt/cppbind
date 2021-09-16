"""
Helper codes for swift conversion
"""
import re

from . import *

DECL_IMPORT_PREFIX_REGEX = r'^(import class |import enum |import func |import struct |import var )'
TEST_IMPORT_PREFIX = '@testable'


def get_c_func_name(hint_name):
    new_name = hint_name
    if "operator" in new_name:
        not_allowed = {
            '*': '_mul_',
            '*=': '_imul_',
            '-': '_sub_',
            '-=': '_isub_',
            '+': '_add_',
            '+=': '_iadd_',
            '/': '_truediv_',
            '/=': '_itruediv_',
            '<': '_lt_',
            '<=': '_le_',
            '>': '_gt_',
            '>=': '_ge_',
            '==': '_eq_',
            '!=': '_ne_',
            '%': '_mod_',
            '&': '_and_',
            '|': '_or_',
            '|=': '_ior_',
            '^': '_xor_',
            '^=': '_ixor_',
            '~': '_invert_',
            '~=': '_iinvert_',
            '<<': '_lshift_',
            '>>': '_rshift_',
            '[]': '_getitem_',
        }
        # we need to consider to use regular expression to avoid multiple passes thought string
        operator = new_name[new_name.rfind("operator") + 8:]
        if operator in not_allowed:
            new_name = new_name.replace(operator, not_allowed[operator])
    return "_func_" + new_name


def get_map_cxx_operator_name(name):
    return name[8:] if name.startswith("operator") else name


def imports_comparator(first: str, second: str):
    """
    Comparator for swift imports sorting.
     Swift imports should be in the following order:
        1. Regular imports like 'import ABC'
        2. Declaration imports like 'import func ABC.sort.
        3. Test modules imports like '@testable import ModuleUnderTest'
    """
    first_is_test = first.startswith(TEST_IMPORT_PREFIX)
    second_is_test = second.startswith(TEST_IMPORT_PREFIX)
    first_is_decl = re.match(DECL_IMPORT_PREFIX_REGEX, first)
    second_is_decl = re.match(DECL_IMPORT_PREFIX_REGEX, second)
    if first_is_test and second_is_test:
        return 1 if first > second else -1
    elif first_is_test:
        return 1
    elif second_is_test:
        return -1
    if first_is_decl and second_is_decl:
        return 1 if first > second else -1
    elif first_is_test:
        return 1
    elif second_is_decl:
        return -1
    else:
        return 1 if first > second else -1
