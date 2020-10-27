"""
Helper functions working with clang
"""
import clang.cindex as cli
from itertools import chain


def get_pointee_type(clang_type):
    return clang_type.get_pointee() if clang_type.get_pointee().spelling else clang_type


def get_canonical_type(clang_type):
    return clang_type.get_canonical() if clang_type.get_canonical().spelling else clang_type


def is_template(clang_type):
    return clang_type.get_num_template_arguments() != -1


def template_argument_types(clang_type):
    return [clang_type.get_template_argument_type(num)
            for num in range(clang_type.get_num_template_arguments())]


def template_type_name(clang_type):
    name = get_unqualified_type_name(clang_type)
    end_indx = name.index('<')
    if end_indx != -1:
        return name[:end_indx].strip()
    return name


def is_rval_referance(cursor):
    return cursor.kind == cli.TypeKind.LVALUEREFERENCE


def _get_unqualified_type_name(type_name):
    """
    TODO: python API is missing
    """
    qualifiers = ["const ", "volatile "]
    for qual in qualifiers:
        if type_name.startswith(qual):
            return _get_unqualified_type_name(type_name[len(qual):])
    return type_name


def get_unqualified_type_name(clang_type):
    return _get_unqualified_type_name(clang_type.spelling)


def get_semantic_ancestors(cursor):
    ancestors = []
    _cursor = cursor.semantic_parent

    while(_cursor):
        ancestors.append(_cursor)
        _cursor = _cursor.semantic_parent

    return ancestors[::-1]


def get_full_name(cursor):
    ancestors = get_semantic_ancestors(cursor)
    ancestors = ancestors[1::] + [cursor]
    return '::'.join([c.spelling for c in ancestors])


def get_full_displayname(cursor):
    ancestors = get_semantic_ancestors(cursor)
    ancestors = ancestors[1::] + [cursor]
    return '::'.join([c.displayname for c in ancestors])


def is_final_cursor(cursor):
    if cursor.kind == cli.CursorKind.CXX_METHOD:
        if not cursor.is_virtual_method():
            return True
        return cli.CursorKind.CXX_FINAL_ATTR in chain(
            (c.kind for c in cursor.get_children()),
            (c.kind for c in cursor.semantic_parent.get_children())
        )
    else:
        return cli.CursorKind.CXX_FINAL_ATTR in (c.kind for c in cursor.get_children())
