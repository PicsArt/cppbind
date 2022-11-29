# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Common utils that can by used from different modules
"""
import enum
import errno
import glob
import importlib.util
import logging
import os
import re
import shutil
import sys
from collections.abc import Iterable
from functools import cmp_to_key, lru_cache
from types import SimpleNamespace

from isort.api import sort_code_string
from jinja2 import BaseLoader, Environment, StrictUndefined
from wcmatch import glob as wcglob

from cppbind import BANNER_LOGO
from cppbind import default_config
from cppbind.common import JINJA_UNIQUE_MARKER, YAML_CONFIG_TEMPLATE_PATH
from cppbind.common.error import Error
from cppbind.ir import ElementKind

DEFAULT_HELPER = 'cppbind_helper'


class DefaultValueKind(enum.IntEnum):
    CALL_EXPR = 1
    ENUM = 2
    LITERAL = 3
    NULL_PTR = 4


def absolute_path_from_glob(src_glob):
    """
    Finds all the absolute file paths matching a specified pattern
    Args:
        src_glob(list): List of glob paths
    Returns:
        list: List of absolute paths
    """
    all_absolute_paths = set()
    for file in src_glob:
        abs_paths = (os.path.abspath(file_path)
                     for file_path in glob.glob(file.strip(), recursive=True))
        all_absolute_paths.update(abs_paths)

    return all_absolute_paths


def list_files(path, extentions=None):
    """ List all files in a directory specified by path
    Args:
        path - the root directory path
        extensions - a iterator of file extensions to include, pass None to get all files.
    Returns:
        A list of files specified by extensions
    """
    file_paths = []
    for root, _, files in os.walk(path):
        for file in files:
            if extentions is None:
                file_paths.append(os.path.join(os.path.abspath(root), file))
            else:
                for ext in extentions:
                    if file.endswith(ext):
                        file_paths.append(os.path.join(os.path.abspath(root), file))

    return file_paths


def filter_by_glob(files, pattern):
    """ Filter list of files by specified pattern
    Args:
        files - list of file paths
        pattern - filter that describes a set of strings that matches the pattern
    Returns:
        A list of files filtered by specified pattern
    """
    return [file for file in files if wcglob.globmatch(file, pattern, flags=wcglob.GLOBSTAR)]


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


def get_android_ndk_sysroot(ndk_path):
    """
    Construct android ndk sysroot path for target platform
    """
    platform = get_host_platform()

    # now we check only for mac, win, linux platforms, but we also have ios, android platforms (also there is win32)
    platform_section = 'linux-x86_64'
    if platform == 'mac':
        platform_section = 'darwin-x86_64'
    elif platform == 'win':
        platform_section = 'windows-x86_64'

    sysroot_path = os.path.join(ndk_path if ndk_path is not None else '/usr/local/share/android-ndk',
                                'toolchains/llvm/prebuilt', platform_section, 'sysroot')

    if not os.path.isdir(sysroot_path):
        Error.critical(f"'ANDROID_NDK' environment variable is not set properly: "
                       f"{sysroot_path} directory doesn't exist")

    return sysroot_path


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


def make_camel_case(string, sub_strings=None, capitalize=False):
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
    init, *temp = string.strip('_').split('_')
    return ''.join([init.title() if capitalize else init, *map(str.title, temp)])


def clear_cppbind_generated_files(directory):
    """
    Traverses given directory and removes all files that contain CppBind banner.
    Args:
        directory(str): Directory path.
    """
    # remove all spaces from banner logo
    banner = re.sub(r'\s+', '', BANNER_LOGO)
    # We are using topdown=False to make sure that walk visits deepest
    # directories at first so no empty directory will be left.
    for root, _, filenames in os.walk(directory, topdown=False):
        for file in filenames:
            remove = False
            file_path = os.path.join(root, file)
            try:
                with open(file_path, 'r') as file:
                    content = file.read()
                    # remove all * and spaces from banner
                    content = re.sub(r'[*\s+]', '', content)
                    if banner in content:
                        remove = True
                if remove:
                    os.remove(file_path)
            except Exception as err:
                Error.warning(f"Cannot process {os.path.abspath(file_path)} file: {err}")
        if not os.listdir(root):
            try:
                os.rmdir(os.path.abspath(root))
            except OSError as err:
                Error.warning(f"Cannot delete {os.path.abspath(root)} directory: {err}")


def copy_yaml_config_template():
    """
    Copies cppbind yaml config template file containing default values into current directory.
    """
    cwd = os.getcwd()
    config_file_name = os.path.basename(YAML_CONFIG_TEMPLATE_PATH)
    if not os.path.exists(os.path.join(cwd, config_file_name)):
        shutil.copy(YAML_CONFIG_TEMPLATE_PATH, cwd)
    else:
        Error.critical(f"'{config_file_name}' project config file already exists in '{cwd}' directory. "
                       f"CppBind will skip config file initialisation.")


def get_var_real_type(type_name):
    """
    Returns real type of variable using 'type' parameter of variable property
    """
    if type_name is None:
        return None

    try:
        res = eval(type_name)
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


def get_public_attributes(attrs):
    """Filter and return only "public" attributes"""
    return {k: v for k, v in attrs.items() if not k.startswith('_')}


@lru_cache
def init_jinja_env(language):
    """
    Function which initializes jinja environment with custom filters/tests
    """

    def path_join(inputs_):
        return os.path.join(*inputs_)

    def format_list(inputs_, format_string, arg_name=None):
        if arg_name is not None:
            return [format_string.format(**{arg_name: data}) for data in inputs_]
        return [format_string.format(data) for data in inputs_]

    def join_unique(inputs_):
        return JINJA_UNIQUE_MARKER.join(inputs_)

    def match_regex(input_, *patterns):
        return any(re.match(pattern, input_) for pattern in patterns)

    def contains(input_, item):
        return item in input_

    def startswith(input_, prefix):
        return input_.startswith(prefix)

    def replace_regex(input_, pattern, repl, count=0):
        return re.sub(pattern, repl, input_, count)

    def _zip(*args):
        if len(args) < 2:
            Error.critical("'zip' filter requires at least 2 arguments")
        for arg in args:
            if not isinstance(arg, Iterable):
                Error.critical("Arguments of the 'zip' filter must be iterable objects")

        return (SimpleNamespace(**{f"_{idx + 1}": item for idx, item in enumerate(group)}) for group in zip(*args))

    def _split(inputs_):
        parts = []
        if not isinstance(inputs_, list):
            inputs_ = [inputs_]
        for input_ in inputs_:
            if isinstance(input_, str):
                parts += input_.split(JINJA_UNIQUE_MARKER)
            else:
                # input_ is a scope
                for part in input_.parts:
                    for part_ in str(part).split(JINJA_UNIQUE_MARKER):
                        if part_:
                            parts.append(part_)
        return parts

    def _default_comparator(a, b):
        return 1 if a > b else -1

    def sort_snippets(inputs_, cmp=_default_comparator, reverse=False):
        parts = _split(inputs_)
        return sorted(parts, key=cmp_to_key(cmp), reverse=reverse)

    def unique_snippets(inputs_):
        parts = _split(inputs_)
        return set(parts)

    def sort_python_code(source):
        return sort_code_string(source).strip()

    class DoxygenCommentStyle(enum.IntEnum):
        JAVADOC = 1
        CPP = 2

    def make_doxygen_comment(comment, style=DoxygenCommentStyle.JAVADOC):
        if not isinstance(style, DoxygenCommentStyle):
            raise ValueError(f'Incorrect doxygen style. Supported styles are: '
                             f'{",".join([f"DoxygenCommentStyle.{c.name}" for c in DoxygenCommentStyle])}')

        if isinstance(comment, str):
            comment = [comment]
        lines = []
        for line in comment:
            lines += line.split('\n')
        nl = '\n/// ' if style != DoxygenCommentStyle.JAVADOC else '\n * '
        if not lines or all((not line or line.isspace() for line in lines)):
            return ''
        if not lines[0] or lines[0].isspace():
            start = ''
        else:
            start = '/// ' if style != DoxygenCommentStyle.JAVADOC else nl
        _comment = f"""{start}{nl.join(lines)}"""
        return f"""{_comment}""" if style != DoxygenCommentStyle.JAVADOC else f"""/**{_comment}\n */"""

    def make_py_docstring(comment):
        nl = '\n'
        if isinstance(comment, str):
            comment = [comment]
        lines = []
        for line in comment:
            lines += line.split(nl)
        if not lines or all((not line or line.isspace() for line in lines)):
            return ""
        start = '' if not lines[0] or lines[0].isspace() else nl
        return f'"""{start}{nl.join(lines)}{nl}"""'

    def make_py_comment(comment):
        return '# ' + '\n# '.join(comment)

    def decapitalize(input_):
        return input_[0].lower() + input_[1:]

    def increment(input_, amount=1):
        return input_ + amount

    def map_callback(input_, callback, **kwargs):
        if isinstance(input_, Iterable):
            return [callback(item, **kwargs) for item in input_]
        return callback(input_, **kwargs)

    def map_type(input_):
        if isinstance(input_, Iterable):
            return [map_type(item) for item in input_]

        if not hasattr(input_, 'type'):
            Error.critical(f"'type' filter is acceptable only for objects (list of objects) with 'type' property. "
                           f"{type(input_)} doesn't have 'type' property.")

        return input_.type

    env = Environment(loader=BaseLoader(),
                      undefined=StrictUndefined,
                      extensions=['jinja2.ext.do', 'jinja2.ext.debug', 'jinja2.ext.loopcontrols'])

    env.filters['all'] = all
    env.filters['any'] = any
    env.filters['path_join'] = path_join
    env.filters['format_list'] = format_list
    env.filters['to_snake_case'] = make_snake_case
    env.filters['to_camel_case'] = make_camel_case
    env.filters['join_unique'] = join_unique
    env.filters['replace_regex'] = replace_regex
    env.filters['zip'] = _zip
    env.filters['sort_snippets'] = sort_snippets
    env.filters['unique_snippets'] = unique_snippets
    env.filters['sort_python_code'] = sort_python_code
    env.filters['make_doxygen_comment'] = make_doxygen_comment
    env.filters['make_py_docstring'] = make_py_docstring
    env.filters['make_py_comment'] = make_py_comment
    env.filters['decapitalize'] = decapitalize
    env.filters['increment'] = increment
    env.filters['map_callback'] = map_callback
    env.filters['type'] = map_type
    env.filters['set'] = lambda x: set(x)

    env.tests['match_regex'] = match_regex
    env.tests['contains'] = contains
    env.tests['startswith'] = startswith

    env.globals['Error'] = Error
    env.globals['DoxygenCommentStyle'] = DoxygenCommentStyle
    env.globals['path'] = os.path
    env.globals['pat_sep'] = os.sep
    env.globals['marker'] = JINJA_UNIQUE_MARKER
    env.globals['ElementKind'] = ElementKind

    # add default and custom helpers to jinja env
    for name, module in get_helper_modules(language).items():
        env.globals[name] = module

    return env


def get_language_helper_module(language):
    try:
        language_helper_module = importlib.import_module(f'cppbind.converter.{language}')
        logging.info(f"Loaded helper module for '{language}' language")
    except ModuleNotFoundError:
        language_helper_module = importlib.import_module('cppbind.converter')
        logging.info(f"Helper module is not found for '{language}' language, loading default instead")

    return language_helper_module


def get_helper_modules(language):
    default_module = get_language_helper_module(language)
    modules = {DEFAULT_HELPER: default_module}
    sys.modules[DEFAULT_HELPER] = default_module
    if hasattr(default_config.application, 'custom_helpers_dir'):
        helpers_paths = glob.glob(os.path.join(default_config.application.custom_helpers_dir, f'**/{language}/**/*.py'),
                                  recursive=True)
        for module_path in helpers_paths:
            module_name = os.path.splitext(os.path.basename(module_path))[0]
            spec = importlib.util.spec_from_file_location(module_name, os.path.abspath(module_path))
            module = importlib.util.module_from_spec(spec)
            spec.loader.exec_module(module)
            modules[module_name] = module

    return modules
