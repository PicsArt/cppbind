"""
Helper codes for kotlin conversion
"""


def make_comment(pure_comment):
    nl = '\n * '
    if not pure_comment:
        return ""
    return f"""/**{nl.join(pure_comment)}
 */"""


def get_c_func_name(package_name, class_name, template_suffix, method_name, args_type_name=None):
    return "test"
