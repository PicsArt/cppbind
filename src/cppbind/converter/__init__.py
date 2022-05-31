# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

from cppbind.common.error import Error

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


def validate_getter(cxx, vars, args, owner_class, setter):
    if args:
        Error.critical(
            f'Getter should not have arguments: {owner_class.cxx.displayname}.{cxx.displayname}.')
    if setter:
        if len(setter['args']) != 1:
            Error.critical(
                f'Setter should have one argument: {owner_class.cxx.displayname}.{cxx.displayname}.')

        have_diff_nullability = (len(setter['vars'].nullable_arg) == 0) ^ (vars.nullable_return is False)
        if have_diff_nullability:
            Error.critical(
                f'Setter argument and getter return value should have the same nullability:'
                f' {owner_class.cxx.displayname}.{cxx.displayname}.')


def validate_template_getter_setter(cxx, vars, owner_class, setter):
    if not setter or not cxx.is_template:
        return

    is_valid = len(vars.template) == len(setter['vars'].template)
    if is_valid:
        for template_arg, possible_types in vars.template.items():
            getter_types = {template['type'] for template in possible_types}
            setter_types = {template['type'] for template in setter['vars'].template[template_arg]}
            if getter_types != setter_types:
                is_valid = False
                break
    if not is_valid:
        parent = owner_class.cxx.displayname
        Error.critical(
            f'Template getter/setter should have the same template argument types: '
            f'{parent}.{cxx.displayname} and {parent}.{setter["cxx"].displayname}.')


def relative_package(namespace1, namespace2):
    ii = 0
    end_idx = 0
    l = min(len(namespace2), len(namespace1))
    while ii < l and namespace1[ii] == namespace2[ii]:
        if namespace1[ii] == '.':
            end_idx = ii + 1
        ii += 1

    return namespace1[end_idx:]
