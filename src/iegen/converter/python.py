"""
Helper codes for python conversion
"""
import os
import re

import iegen.utils.clang as cutil
from iegen import logging
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


def is_first_overload(ctx):
    adjacents = ctx.find_adjacents([ctx.name], ctx.node.api)
    is_first = next(adjacents).cursor == ctx.cursor
    return is_first


def module_name_to_func_name(pybind_module):
    return ''.join([part.capitalize() for part in re.split('[_.]', pybind_module)])


def cxx_rel_path(filepath, cxx_filepath):
    return os.path.relpath(filepath, cxx_filepath)


def get_operator_name(spelling):
    operator = spelling.replace('operator', '').strip()
    return OPERATOR_MAPPING.get(operator, spelling)


def make_comment(pure_comment):
    if isinstance(pure_comment, str):
        pure_comment = pure_comment.split(NEW_LINE)
    if not pure_comment or all((not line or line.isspace() for line in pure_comment)):
        return ""
    start = '' if not pure_comment[0] or pure_comment[0].isspace() else NEW_LINE
    return f'"""{start}{NEW_LINE.join(pure_comment)}{NEW_LINE}"""'


def make_enum_case_comment(pure_comment):
    nl = f'{NEW_LINE}# '
    if not pure_comment:
        return ""
    return f'# {nl.join([c for c in pure_comment if c])}'


def is_overloaded_cursor(ctx):
    return [item for item in list(ctx.node.parent.clang_cursor.get_children()) if
            item.spelling == ctx.cursor.spelling and item != ctx.cursor]


def get_declaration_includes(ctx):
    includes = []
    _get_declaration_includes(ctx, ctx.cursor, includes)
    if includes:
        logging.debug(f"Including forward declaration headers {includes} for {ctx.name}")
    return includes


def _get_declaration_includes(ctx, cursor, includes):
    if cursor.kind == cli.CursorKind.NAMESPACE:
        for child in cursor.get_children():
            if cutil.is_declaration(child):
                ref_ctx = ctx.find_by_type(child.type)
                if ref_ctx:
                    includes.append(os.path.relpath(ref_ctx.cursor.location.file.name,
                                                    ctx.out_prj_dir))
    if cursor.lexical_parent:
        _get_declaration_includes(ctx, cursor.lexical_parent, includes)


def get_default_value(arg):
    if arg.default:
        pointee = cutil.get_pointee_type(arg.cursor.type)
        if arg.default in ('nullptr', 'NULL'):
            return f' = None'
        elif pointee.kind == cli.TypeKind.ENUM:
            return f' = {arg.converter.python.target_type_name}.{arg.default}'
        return f' = {arg.default}'
    return ''
