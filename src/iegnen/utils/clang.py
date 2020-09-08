"""
Helper functions working with clang
"""
import clang.cindex as cli


def get_pointee_type_name(type):
    return type.get_pointee().spelling or type.spelling


def get_pointee_type(type):
    return type.get_pointee() if type.get_pointee().spelling else type


def is_rval_referance(cursor):
    return cursor.kind == cli.TypeKind.LVALUEREFERENCE


def get_unqualified_type_name(type_name):
    """
    TODO: python API is missing
    """
    qualifiers = ["const ", "volatile "]
    for qual in qualifiers:
        if type_name.startswith(qual):
            return get_unqualified_type_name(type_name[len(qual):])
    return type_name
