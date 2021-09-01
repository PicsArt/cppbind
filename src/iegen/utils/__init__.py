"""
Common utils that can by used from different modules
"""
import enum
import errno
import importlib.util
import os
import re
import shutil
import sys
from functools import cmp_to_key

from jinja2 import BaseLoader, Environment, StrictUndefined

from iegen import BANNER_LOGO
from iegen.common import JINJA_UNIQUE_MARKER, YAML_CONFIG_TEMPLATE_PATH
from iegen.common.error import Error


class DefaultValueKind(enum.IntEnum):
    CALL_EXPR = 1
    ENUM = 2
    LITERAL = 3
    NULL_PTR = 4


def load_from_paths(loader, path_name, default_dirs):
    for dir_ in default_dirs:
        try:
            return loader(os.path.join(dir_, path_name))
        except FileNotFoundError:
            continue
    raise FileNotFoundError(errno.ENOENT, os.strerror(errno.ENOENT), path_name)


def load_module_from_path(module_name, path_name):
    module_spec = importlib.util.spec_from_file_location(module_name, path_name)
    module = importlib.util.module_from_spec(module_spec)
    module_spec.loader.exec_module(module)
    return module


def load_module_from_paths(module_name, path_name, default_dirs):
    return load_from_paths(lambda path: load_module_from_path(module_name, path),
                           path_name, default_dirs)


def load_rule_module(language, rule, default_dirs):
    module = load_module_from_paths(f"{language}.rule",
                                    rule,
                                    default_dirs)
    module.set_language(language)
    return module


def get_host_platform():
    platform = sys.platform
    if platform.startswith('linux'):
        return 'linux'
    if platform.startswith('win'):
        return 'win'
    if platform == 'darwin':
        return 'mac'

    raise Exception(f"Not supported os platform: {platform}")


def make_snake_case(string, sub_strings=None):
    """
    Returns snake cased version of input string if sub_strings is None.
    If sub_strings is specified then only replaces all sub_string
    occurrences with their snake cased version.
    Args:
        string(str): String to replace
        sub_strings(list): List of sub_strings to be replaced with their snake cased version.
    Returns:
        str: Snake cased input string.
    """
    if sub_strings:
        for p in sub_strings:
            string = string.replace(p, make_snake_case(p))
        return string
    return re.sub(r'(?<!^)(?=[A-Z])', '_', string).lower()


def make_camel_case(string, sub_strings=None):
    """
    Returns camel cased version of input string if sub_strings is None.
    If sub_strings is specified then only replaces all sub_string
    occurrences with their camel cased version.
    Args:
        string(str): String to replace
        sub_strings(list): List of sub_strings to be replaced with their camel cased version.
    Returns:
        str: Camel cased input string.
    """
    if sub_strings:
        for p in sub_strings:
            string = string.replace(p, make_camel_case(p))
        return string
    init, *temp = string.split('_')
    return ''.join([init, *map(str.title, temp)])


def clear_iegen_generated_files(directory):
    """
    Traverses given directory and removes all files that contain IEGEN banner.
    Args:
        directory(str): Directory path.
    """
    # remove all spaces from banner logo
    banner = re.sub(r'\s+', '', BANNER_LOGO)
    for root, _, filenames in os.walk(directory):
        for file in filenames:
            remove = False
            file_path = os.path.join(root, file)
            with open(file_path, 'r') as file:
                content = file.read()
                # remove all *, / and spaces from banner
                content = re.sub(r'[/*\s+]', '', content)
                if banner in content:
                    remove = True
            if remove:
                os.remove(file_path)
        if not os.listdir(root):
            os.rmdir(root)


def copy_yaml_config_template():
    """
    Copies iegen yaml config template file containing default values into current directory.
    """
    shutil.copy(YAML_CONFIG_TEMPLATE_PATH, os.getcwd())


def get_var_real_type(type_name):
    """
    Returns real type of variable using 'type' parameter of variable property
    """
    if type_name is None:
        return None

    try:
        res = eval(type_name.value)
    except (NameError, SyntaxError, TypeError) as err:
        Error.critical(f"'{type_name.value}' cannot be used as a value for 'type' "
                       f"parameter since it's not python primitive type: {err}",
                       type_name.file,
                       type_name.line_number)

    if not isinstance(res, type):
        Error.critical(f"'{res}' cannot be used as a value for 'type' parameter since it's not python primitive type",
                       type_name.file,
                       type_name.line_number)

    return res


def init_jinja_env():
    """
    Function with initializes jinja environment with custom filters/tests
    """

    def path_join(inputs_):
        return os.path.join(*inputs_)

    def format_list(inputs_, format_string, arg_name=None):
        if arg_name is not None:
            return [format_string.format(**{arg_name: data}) for data in inputs_]
        return [format_string.format(data) for data in inputs_]

    def join_unique(inputs_):
        return JINJA_UNIQUE_MARKER.join(inputs_)

    def match_regexp(input_, *patterns):
        return any(re.match(pattern, input_) for pattern in patterns)

    def replace_regex(input_, pattern, repl, count=0):
        return re.sub(pattern, repl, input_, count)

    def _split(inputs_):
        parts = []
        if not isinstance(inputs_, list):
            inputs_ = [inputs_]
        for input_ in inputs_:
            if isinstance(input_, str):
                parts += input_.split(JINJA_UNIQUE_MARKER)
            else:
                for part in input_.parts:
                    parts += str(part).split(JINJA_UNIQUE_MARKER)
        return parts

    def _default_comparator(a, b):
        return 1 if a > b else -1

    def sort_snippets(inputs_, cmp=_default_comparator, reverse=False):
        parts = _split(inputs_)
        return sorted(parts, key=cmp_to_key(cmp), reverse=reverse)

    def unique_snippets(inputs_):
        parts = _split(inputs_)
        return set(parts)

    env = Environment(loader=BaseLoader(),
                      undefined=StrictUndefined,
                      extensions=['jinja2.ext.do', 'jinja2.ext.debug'])

    env.filters['path_join'] = path_join
    env.filters['format_list'] = format_list
    env.filters['to_snake_case'] = make_snake_case
    env.filters['to_camel_case'] = make_camel_case
    env.filters['join_unique'] = join_unique
    env.filters['replace_regex'] = replace_regex
    env.filters['sort_snippets'] = sort_snippets
    env.filters['unique_snippets'] = unique_snippets

    env.tests['match_regexp'] = match_regexp

    return env


JINJA2_ENV = init_jinja_env()
