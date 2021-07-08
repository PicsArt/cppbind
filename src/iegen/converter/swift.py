"""
Helper codes for swift conversion
"""
import clang.cindex as cli
import iegen.utils.clang as cutil
from . import *


def make_comment(pure_comment):
    return make_doxygen_comment(pure_comment)


def make_enum_case_comment(pure_comment):
    return make_comment(pure_comment)


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


def _is_pointer(type_converter):
    return type_converter.ctx is not None and type_converter.ctx.cursor.kind in [cli.CursorKind.STRUCT_DECL,
                                                                                 cli.CursorKind.CLASS_DECL,
                                                                                 cli.CursorKind.CLASS_TEMPLATE]


def is_type_pointer(type_converter):
    if cutil.is_template(type_converter.original_clang_type):
        type_name = cutil.template_type_name(type_converter.original_clang_type)
        if type_name == 'std::shared_ptr':
            return _is_pointer(type_converter.template_args[0])
    return _is_pointer(type_converter)
