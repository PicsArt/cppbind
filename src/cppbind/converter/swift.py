# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Helper codes for swift conversion
"""
import re

from . import *

DECL_IMPORT_PREFIX_REGEX = r'^(import class |import enum |import func |import struct |import var )'
TEST_IMPORT_PREFIX = '@testable'


def get_c_func_name(prefix, name, postfix):
    new_name = name
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
    if name in not_allowed:
        new_name = not_allowed[name]
    return f"_func_{prefix}_{new_name}{postfix}"


def imports_comparator(first: str, second: str):
    """
    Comparator for swift imports sorting.
     Swift imports should be in the following order:
        1. Regular imports like 'import ABC'
        2. Declaration imports like 'import func ABC.sort.'
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


def get_operator_name(name):
    return name[8:] if name.startswith("operator") else name
