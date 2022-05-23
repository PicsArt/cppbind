# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Helper functions working with clang
"""
import os
import re
import sys
from cachetools import cached, LRUCache
from ctypes import *
from ctypes.util import find_library
from itertools import chain

from cppbind.common.error import Error
import clang.cindex as cli


def template_type_name(type_):
    name = get_unqualified_type_name(type_)
    end_idx = name.find('<')
    if end_idx != -1:
        return name[:end_idx].strip()
    return name


def is_overloaded(cursor):
    return bool([child for child in list(cursor.semantic_parent.get_children()) if
            child.spelling == cursor.spelling and child != cursor])


def _get_unqualified_type_name(type_name):
    """
    TODO: python API is missing
    """
    qualifiers = ["const ", "volatile "]
    for qual in qualifiers:
        if type_name.startswith(qual):
            return _get_unqualified_type_name(type_name[len(qual):])
    return type_name


def get_unqualified_type_name(type_):
    return _get_unqualified_type_name(type_.spelling if isinstance(type_, cli.Type) else type_)


def get_semantic_ancestors(cursor):
    ancestors = []
    _cursor = cursor.semantic_parent

    while _cursor:
        ancestors.append(_cursor)
        _cursor = _cursor.semantic_parent

    return ancestors[::-1]


def join_type_parts(type_parts):
    return '::'.join(type_parts)


def get_full_displayname(cursor):
    ancestors = get_semantic_ancestors(cursor)
    spellings = [a.displayname for a in ancestors[1::] if a.displayname != '']
    spellings.append(cursor.displayname)
    return join_type_parts(spellings)


def get_signature(cursor):
    full_displayname = get_full_displayname(cursor)
    if cursor.kind == cli.CursorKind.NAMESPACE:
        # namespace cursors coming from #include directives has relative file name
        return join_type_parts([os.path.abspath(cursor.extent.start.file.name),
                                str(cursor.extent.start.line),
                                full_displayname])
    return full_displayname


def is_final_cursor(cursor):
    if cursor.kind == cli.CursorKind.CXX_METHOD:
        if not cursor.is_virtual_method():
            return True
        return cli.CursorKind.CXX_FINAL_ATTR in chain(
            (c.kind for c in cursor.get_children()),
            (c.kind for c in cursor.semantic_parent.get_children())
        )
    return cli.CursorKind.CXX_FINAL_ATTR in (c.kind for c in cursor.get_children())


@cached(cache=LRUCache(maxsize=128), key=lambda cursor: get_signature(cursor))
def is_polymorphic(cursor):
    """
    Returns true if the class/struct is polymorphic (contains or inherits a virtual function)
    Note: There is `isPolymorphic()` class in libclang `clang::CXXRecordDecl` class, but it is not exported
    """
    if cursor.kind not in (cli.CursorKind.STRUCT_DECL,
                           cli.CursorKind.CLASS_DECL,
                           cli.CursorKind.CLASS_TEMPLATE):
        Error.internal("Is polymorphic check is valid only for class/struct types")

    base_cursors = []
    for child in cursor.get_children():
        if child.kind in (cli.CursorKind.CXX_METHOD,
                          cli.CursorKind.DESTRUCTOR) and child.is_virtual_method():
            return True

        # collect all bases to process later (no need to dive into bases in case the type itself is virtual)
        if child.kind == cli.CursorKind.CXX_BASE_SPECIFIER:
            base_cursors.append(child.referenced)

    return any(is_polymorphic(base_cursor) for base_cursor in base_cursors)


@cached(cache=LRUCache(maxsize=128), key=lambda cursor: get_signature(cursor))
def has_multiple_base_branches(cursor):
    """Returns true if the class/struct has multiple base branches in its hierarchy"""
    if cursor.kind not in (cli.CursorKind.STRUCT_DECL,
                           cli.CursorKind.CLASS_DECL,
                           cli.CursorKind.CLASS_TEMPLATE):
        Error.internal("Has multiple bases check is valid only for class/struct types")

    base_cursors = [child for child in cursor.get_children() if child.kind == cli.CursorKind.CXX_BASE_SPECIFIER]
    if len(base_cursors) > 1:
        return True

    return has_multiple_base_branches(base_cursors[0].referenced) if base_cursors else False


def get_base_cursor(cursor):
    """
    Returns the base class cursor for the given cursor.
    If there are multiple branches(inheritance) then the left(first) base is taken.
    Args:
        cursor (clang.cindex.Cursor):
    Returns:
        clang.cindex.Cursor: The base class cursor.
    """
    bases = [base_specifier for base_specifier in cursor.get_children() if
             base_specifier.kind == cli.CursorKind.CXX_BASE_SPECIFIER]
    if bases:
        return get_base_cursor(bases[0].get_definition())
    return cursor


def extract_pure_comment(raw_comment, end_index=None):
    """
    Returns pure comment(without API part).
    Args:
        raw_comment(str): Doxygen comment.
        end_index(int): Index to where to consider,
                        if not specified then will consider the whole string.
    Returns:
        str: Characters removed type_name.
    """
    end_index = end_index or len(raw_comment)
    # using one lstrip(' ') before removing any of the given characters
    # and one at the end to remove all leading whitespaces
    comment_lines = [(comment_line.lstrip(' ')).lstrip('/*!').lstrip(' ')
                     for comment_line in raw_comment[:end_index].splitlines()]

    if comment_lines and not comment_lines[0]:
        comment_lines.pop(0)
    if comment_lines and not comment_lines[-1]:
        comment_lines.pop()

    return comment_lines

def replace_template_choice(type_name, template_choice):
    """
    Return type name with replaced template arguments,
    e.g. for a::Foo<T,V> will return a::Foo<Project,int>.
    Args:
        type_name(str): Type name. e.g. a::Foo<T,V>
        template_choice (dict): Containing template current value,
                                e.g. {"T": "a::Project", "V": "int"}
    Returns:
        str: Replaced type_name.
    """
    replaced = type_name
    if template_choice:
        if replaced in template_choice:
            return template_choice[replaced]
        for typename, value in template_choice.items():
            replaced = re.sub(rf'(^|[,<\s])(\s*){typename}([\s,>&*]|$)', rf'\g<1>\g<2>{value}\g<3>', replaced)
    return replaced


def get_libclang_full_path():
    """
    Return libclang full path.
    cindex.Config.library_file returns only file name for linux not a full path.
    """
    # linkmap structure, we only need the second entry
    if sys.platform.startswith('linux'):
        class LINKMAP(Structure):
            _fields_ = [
                ('l_addr', c_void_p),
                ('l_name', c_char_p)
            ]

        libc = CDLL(cli.Config.library_file)
        libdl = CDLL(find_library('dl'))

        dlinfo = libdl.dlinfo
        dlinfo.argtypes = c_void_p, c_int, c_void_p
        dlinfo.restype = c_int

        # gets typecasted later, I dont know how to create a ctypes struct pointer instance
        lmptr = c_void_p()

        # 2 equals RTLD_DI_LINKMAP, pass pointer by reference
        dlinfo(libc._handle, 2, byref(lmptr))

        # typecast to a linkmap pointer and retrieve the name.
        abspath = cast(lmptr, POINTER(LINKMAP)).contents.l_name
        return abspath.decode('utf-8')
    return cli.Config.library_file
