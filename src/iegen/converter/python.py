"""
Helper codes for python conversion
"""
import clang.cindex as cli
import os
import iegen.utils.clang as cutil


def make_comment(pure_comment):
    nl = '\n'
    if not pure_comment:
        return ""
    return f'"""{nl.join(pure_comment)}"""'


def get_overload_cursors(ctx):
    return [item for item in list(ctx.node.parent.clang_cursor.get_children()) if
            item.spelling == ctx.name and item != ctx.cursor]


def get_include(cursor, config):
    return os.path.relpath(cursor.location.file.name,
                           config.out_prj_dir)


def get_declaration_includes(ctx, config):
    includes = []
    _get_declaration_includes(ctx, ctx.cursor, config, includes)
    if includes:
        print(includes)
    return includes


def _get_declaration_includes(ctx, cursor, config, includes):
    if cursor.kind == cli.CursorKind.NAMESPACE:
        for child in cursor.get_children():
            if cutil.is_declaration(child):
                ref_ctx = ctx.find_by_type(child.type)
                if ref_ctx:
                    includes.append(get_include(ref_ctx.cursor, config))
    if cursor.lexical_parent:
        _get_declaration_includes(ctx, cursor.lexical_parent, config, includes)
