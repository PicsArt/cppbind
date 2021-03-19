"""
Helper codes for python conversion
"""
import clang.cindex as cli
import os
import iegen.utils.clang as cutil
from iegen import logging

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

def overloaded_method_options(ctx):
    pass


def cxx_rel_path(filepath, cxx_filepath):
    return os.path.relpath(filepath, cxx_filepath)


def get_operator_name(spelling):
    operator = spelling.replace('operator', '').strip()
    return OPERATOR_MAPPING.get(operator, spelling)


def make_comment(pure_comment):
    nl = '\n'
    if not pure_comment:
        return ""
    return f'"""{nl.join(pure_comment)}"""'


def make_hashtag_comment(pure_comment):
    nl = '\n# '
    if not pure_comment:
        return ""
    return f'# {nl.join([c for c in pure_comment if c])}'


def is_overloaded_cursor(ctx):
    return [item for item in list(ctx.node.parent.clang_cursor.get_children()) if
            item.spelling == ctx.cursor.spelling and item != ctx.cursor]


def get_include(cursor, config):
    return os.path.relpath(cursor.location.file.name,
                           config.out_prj_dir)


def get_declaration_includes(ctx, config):
    includes = []
    _get_declaration_includes(ctx, ctx.cursor, config, includes)
    if includes:
        logging.debug(f"Including forward declaration headers {includes} for {ctx.name}")
    return includes


def replace_template_choice(type_name, template_choice):
    return cutil.replace_template_choice(type_name, template_choice)


def _get_declaration_includes(ctx, cursor, config, includes):
    if cursor.kind == cli.CursorKind.NAMESPACE:
        for child in cursor.get_children():
            if cutil.is_declaration(child):
                ref_ctx = ctx.find_by_type(child.type)
                if ref_ctx:
                    includes.append(get_include(ref_ctx.cursor, config))
    if cursor.lexical_parent:
        _get_declaration_includes(ctx, cursor.lexical_parent, config, includes)
