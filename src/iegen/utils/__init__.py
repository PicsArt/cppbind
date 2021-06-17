"""
Common utils that can by used from different modules
"""
import datetime
import errno
import importlib.util
import os
import re
import sys

from iegen import DATETIME_FORMAT


def load_from_paths(loader, path_name, default_dirs):
    for d in default_dirs:
        try:
            return loader(os.path.join(d, path_name))
        except FileNotFoundError:
            continue
    else:
        raise FileNotFoundError(errno.ENOENT, os.strerror(errno.ENOENT), path_name)


def load_module_from_path(module_name, path_name):
    module_spec = importlib.util.spec_from_file_location(module_name, path_name)
    module = importlib.util.module_from_spec(module_spec)
    module_spec.loader.exec_module(module)
    return module


def load_module_from_paths(module_name, path_name, default_dirs):
    return load_from_paths(lambda path: load_module_from_path(module_name, path),
                           path_name, default_dirs)


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
    If sub_strings is specified then only replaces all sub_string occurrences with their snake cased version.
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
    If sub_strings is specified then only replaces all sub_string occurrences with their camel cased version.
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


def current_datetime():
    """
    Returns formatted current date time in utc.
    Returns:
        str: Formatted result.
    """
    return datetime.date.strftime(datetime.datetime.utcnow(), DATETIME_FORMAT)
