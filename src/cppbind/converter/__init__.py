# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

from cppbind.common.error import Error
from cppbind.parser import TEMPLATE_TYPE_PARAMETER_KEY, TEMPLATE_NON_TYPE_PARAMETER_KEY

NEW_LINE = '\n'


def make_doxygen_comment(pure_comment):
    if isinstance(pure_comment, str):
        pure_comment = pure_comment.split(NEW_LINE)
    nl = f'{NEW_LINE} * '
    if not pure_comment or all((not line or line.isspace() for line in pure_comment)):
        return ''
    start = '' if not pure_comment[0] or pure_comment[0].isspace() else nl
    return f"""/**{start}{nl.join(pure_comment)}
*/"""


def validate_getter(cxx, vars, setter):
    if cxx.args:
        Error.critical(
            f'Getter should not have arguments: {cxx.parent.displayname}.{cxx.displayname}.')
    if setter:
        if len(setter['cxx'].args) != 1:
            Error.critical(
                f'Setter should have one argument: {cxx.parent.displayname}.{cxx.displayname}.')

        have_diff_nullability = (len(setter['vars'].nullable_arg) == 0) ^ (vars.nullable_return is False)
        if have_diff_nullability:
            Error.critical(
                f'Setter argument and getter return value should have the same nullability:'
                f' {cxx.parent.displayname}.{cxx.displayname}.')


def validate_template_getter_setter(cxx, vars, setter):
    if not setter or not cxx.is_template:
        return

    is_valid = len(vars.template) == len(setter['vars'].template)
    if is_valid:
        for template_arg, possible_types in vars.template.items():
            getter_types = {template.get(TEMPLATE_TYPE_PARAMETER_KEY) or template.get(TEMPLATE_NON_TYPE_PARAMETER_KEY)
                            for template in possible_types}
            setter_types = {template.get(TEMPLATE_TYPE_PARAMETER_KEY) or template.get(TEMPLATE_NON_TYPE_PARAMETER_KEY)
                            for template in setter['vars'].template[template_arg]}
            if getter_types != setter_types:
                is_valid = False
                break
    if not is_valid:
        parent_name = cxx.parent.displayname
        Error.critical(
            f'Template getter/setter should have the same template argument types: '
            f'{parent_name}.{cxx.displayname} and {parent_name}.{setter["cxx"].displayname}.')


def relative_package(namespace1, namespace2):
    ii = 0
    end_idx = 0
    l = min(len(namespace2), len(namespace1))
    while ii < l and namespace1[ii] == namespace2[ii]:
        if namespace1[ii] == '.':
            end_idx = ii + 1
        ii += 1

    return namespace1[end_idx:]


def is_inherited_from_enable_shared_from_this(cxx, directly=False):
    hase_direct_base = any('enable_shared_from_this' in base.type_name for base in cxx.base_types)
    if directly or hase_direct_base:
        return hase_direct_base
    if cxx.base_types:
        return any(is_inherited_from_enable_shared_from_this(base) for base in cxx.base_types)
    return False
