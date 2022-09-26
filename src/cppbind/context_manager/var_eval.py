# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Module is responsible for evaluation of jinja expressions inside variables context definitions.
"""

import yaml
from jinja2.exceptions import TemplateSyntaxError

from cppbind.common.error import Error
from cppbind.common.yaml_process import (
    to_value,
    has_type,
    UniqueKeyLoader,
    YamlNode
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

    def eval_rec(self, name, val_node, ctx, file, line_number):
        """
        Evaluate structure value recursively using given context
        """
        if has_type(val_node, dict):
            return {k: self.eval_rec(name, v, ctx, file, line_number) for k, v in val_node.items()}
        if has_type(val_node, list):
            return [self.eval_rec(name, i, ctx, file, line_number) for i in val_node]
        if has_type(val_node, str):
            try:
                return self.jinja_env.from_string(to_value(val_node)).render(ctx)
            except TemplateSyntaxError as e:
                Error.critical(
                    f"Jinja syntax error in vars.{name} - {str(e)}",
                    file=file,
                    line=line_number)
            except Exception as e:
                Error.critical(f"Jinja render error in vars.{name} - {e}",
                               file,
                               line_number)
        return to_value(val_node)

    def eval_var_value(self, prop, val_node, ctx, att_name, location):
        """
        Method to eval/load variable value according to its type
        """
        file = line_number = None
        if location:
            # get file and line_number from location if it's passed
            file = location.file_name
            line_number = location.line_number
        elif isinstance(val_node, YamlNode):
            # otherwise try to take file and line_number from node if available
            file = val_node.file
            line_number = val_node.line_number

        val = to_value(val_node)
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
                                file,
                                line_number)
                val = self.eval_rec(att_name, val, ctx, file, line_number)

                # we load evaluated result to yaml if we have type mismatch but type is not str
                if actual_type is not str:
                    val = yaml.load(val, Loader=UniqueKeyLoader)
            else:
                # if we have type match, we need to call recursive evaluation function
                val = self.eval_rec(att_name, val, ctx, file, line_number)

        # we put single string element inside of list if 'type' attribute of variable is list
        if actual_type is list and isinstance(val, str):
            val = [val]
        # validate result type with actual type
        # we have cases when 'type' is specified but value can be null, that's why we need to check also val is not None
        elif val is not None and not isinstance(val, actual_type):
            Error.error(f"Type mismatch for '{att_name}' variable: "
                        f"it has value of {type(val)} type instead of required {actual_type}",
                        file,
                        line_number)

        return val
