"""
Helper codes for kotlin conversion
"""


def make_comment(pure_comment):
    nl = '\n * '
    if not pure_comment:
        return ""
    return f"""/**{nl.join(pure_comment)}
 */"""


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
        for old, n in not_allowed.items():
            new_name = new_name.replace(old, n)
    return "_func_" + new_name


def get_map_cxx_operator_name(name):
    return name[8:] if name.startswith("operator") else name
