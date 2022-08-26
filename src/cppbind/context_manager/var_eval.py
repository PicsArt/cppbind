# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Module is responsible for evaluation of jinja expressions inside variables context definitions.
"""

import yaml

from jinja2.exceptions import UndefinedError as JinjaUndefinedError

from cppbind.common.error import Error
from cppbind.common.yaml_process import (
    to_value,
    has_type,
    UniqueKeyLoader
)
from cppbind.utils import get_var_real_type


class VariableEvaluator:
    """
    A class to evaluate jinja expressions according to variables type
    """

    def __init__(self, jinja_env):
        self.jinja_env = jinja_env

    def eval_attr_template(self, attrs, ctx):
        """
        Evaluate jinja expressions in current yaml section.
        """

        # if the whole section is pure string, we just need to eval it (in case of '|' usage)
        if attrs.is_of_type(str):
            return yaml.load(self.jinja_env.from_string(attrs.value).render(ctx), Loader=UniqueKeyLoader)

        # if the section is not a string, i.e. values can contain jinja expressions,
        # we need to keep values to eval them later
        return attrs

    def eval_rec(self, struct, ctx):
        """
        Evaluate structure value recursively using given context
        """
        if has_type(struct, dict):
            return {k: self.eval_rec(v, ctx) for k, v in struct.items()}
        if has_type(struct, list):
            return [self.eval_rec(i, ctx) for i in struct]
        if has_type(struct, str):
            return self.jinja_env.from_string(to_value(struct)).render(ctx)
        return to_value(struct)

    def eval_var_value(self, prop, val, ctx, att_name, location):
        """
        Method to eval/load variable value according to its type
        """

        val = to_value(val)
        # we get actual type from 'type' parameter if it is defined, otherwise it is str
        actual_type = get_var_real_type(to_value(prop.get('type'))) or str
        # if 'type' is not defined and default value is null, actual_type still can be None
        # we still check val since for some languages/platforms it can be null
        if actual_type and val is not None:
            # we evaluate jinja expression when type is str, or when we have type mismatch
            if actual_type is str or not has_type(val, actual_type):
                if not has_type(val, str):
                    Error.error(f"Type mismatch for '{att_name}' variable: "
                                f"it has value of {type(val)} type instead of required {actual_type}",
                                location.file_name if location else None,
                                location.line_number if location else None)
                try:
                    val = self.jinja_env.from_string(val).render(ctx)
                except (JinjaUndefinedError, TypeError) as err:
                    Error.critical(
                        f"Jinja evaluation error for '{att_name}' variable: {err}",
                        location.file_name if location else None,
                        location.line_number if location else None
                    )
                # we load evaluated result to yaml if we have type mismatch but type is not str
                if actual_type is not str:
                    val = yaml.load(val, Loader=UniqueKeyLoader)
            else:
                try:
                    # if we have type match, we need to call recursive evaluation function
                    val = self.eval_rec(val, ctx)
                except (JinjaUndefinedError, TypeError) as err:
                    Error.critical(
                        f"Jinja evaluation error for '{att_name}' variable: {err}",
                        location.file_name if location else None,
                        location.line_number if location else None
                    )

        # we put single string element inside of list if 'type' attribute of variable is list
        if actual_type is list and isinstance(val, str):
            val = [val]
        # validate result type with actual type
        # we have cases when 'type' is specified but value can be null, that's why we need to check also val is not None
        elif val is not None and not isinstance(val, actual_type):
            Error.error(f"Type mismatch for '{att_name}' variable: "
                        f"it has value of {type(val)} type instead of required {actual_type}",
                        location.file_name if location else None,
                        location.line_number if location else None)

        return val
