"""
Helper codes for python conversion
"""
import os

from isort.api import sort_code_string

from . import *

OPERATOR_MAPPING = {
    '*': '__mul__',
    '*=': '__imul__',
    '-': '__sub__',
    '-=': '__isub__',
    '+': '__add__',
    '+=': '__iadd__',
    '/': '__truediv__',
    '/=': '__itruediv__',
    '<': '__lt__',
    '<=': '__le__',
    '>': '__gt__',
    '>=': '__ge__',
    '==': '__eq__',
    '!=': '__ne__',
    '%': '__mod__',
    '&': '__and__',
    '|': '__or__',
    '|=': '__ior__',
    '^': '__xor__',
    '^=': '__ixor__',
    '~': '__invert__',
    '~=': '__iinvert__',
    '<<': '__lshift__',
    '>>': '__rshift__',
    '[]': '__getitem__',
}

sort_imports = sort_code_string


def is_first_overload(ctx):
    adjacents = ctx.find_adjacents([ctx.name], ctx.node.api)
    is_first = next(adjacents).cursor == ctx.cursor
    return is_first


def cxx_rel_path(filepath, cxx_filepath):
    return os.path.relpath(filepath, cxx_filepath)


def get_operator_name(spelling):
    operator = spelling.replace('operator', '').strip()
    return OPERATOR_MAPPING.get(operator, spelling)


def is_overloaded_cursor(ctx):
    return [item for item in list(ctx.node.parent.clang_cursor.get_children()) if
            item.spelling == ctx.cursor.spelling and item != ctx.cursor]
