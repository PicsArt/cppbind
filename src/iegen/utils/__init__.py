"""
Common utils that can by used from different modules
"""
import os
import errno

import importlib.util


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
