# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

"""
Helper module for processing yaml files
"""
import copy
import os

from collections.abc import MutableMapping
from functools import lru_cache

import yaml

from cppbind import Error
from cppbind.common.config import config, PROJECT_CONFIG_DIR
from cppbind.utils import list_files, filter_by_glob


class YamlNode(MutableMapping):
    """
    Class which implements MutableMapping interface to act like a dict
    while keeping additional information. This is implemented to be able to keep
    each yaml node line and file information while loading yaml files.
    """
    def __init__(self, value, line_num=None, file=None):
        self.value = value
        self.line_number = line_num
        self.file = file

    def __getitem__(self, key):
        return self.value[key]

    def __setitem__(self, key, val):
        self.value[key] = val

    def __delitem__(self, key):
        del self.value[key]

    def __iter__(self):
        return iter(self.value)

    def __len__(self):
        return len(self.value)

    def __str__(self):
        return str(self.value)

    def __contains__(self, item):
        return item in self.value

    def is_of_type(self, cls):
        """
        Method to check current node real value type.
        """
        return isinstance(self.value, cls)

    def __bool__(self):
        return bool(self.value)

    def __eq__(self, other):
        """
        This method is overloaded, to avoid usage of 'value' property
        when comparing YamlNode object with other simple object
        """
        if isinstance(other, YamlNode):
            return self.value == other.value
        return self.value == other


class YamlKeyDuplicationError(Exception):
    """
    Exception subclass to raise duplication errors when a key is redefined in yaml file.
    """


@lru_cache
def init_yaml_list(dirs):
    yaml_files = []
    for d in dirs:
        yaml_files.extend(list_files(d, ('.yaml', '.yml')))
    return yaml_files


class MyLoader(yaml.SafeLoader):
    """YAML MyLoader with `!include` constructor."""

    # the list of directories where included yaml files need to be searched
    custom_dirs = [PROJECT_CONFIG_DIR]
    if hasattr(config.application, 'custom_config_dir'):
        custom_dirs.append(config.application.custom_config_dir)

    def __init__(self, stream):
        """Initialise MyLoader."""

        try:
            self._root = os.path.split(stream.name)[0]
        except AttributeError:
            self._root = os.path.curdir

        self.dirs = [self._root]
        self.yaml_files = init_yaml_list(dirs=tuple(self.custom_dirs + [os.path.abspath(os.path.curdir)]))
        super().__init__(stream)

    def construct_yaml_map(self, node):
        """
        Original class is responsible for constructing yaml loader result nodes.
        In this overridden version dict is being replaced with custom class object.
        """
        yield self.construct_mapping(node)

    def construct_mapping(self, node, deep=False):
        """
        Original method is overridden to be able to get a custom class object
        instead of dict when loading yaml.
        """
        mapping = {}
        for key_node, value_node in node.value:
            key = self.construct_object(key_node, deep=deep)
            value = self.construct_object(value_node, deep=deep)
            mapping[key] = YamlNode(value,
                                    key_node.start_mark.line + 1,
                                    key_node.start_mark.name)
        return mapping


class UniqueKeyLoader(yaml.SafeLoader):
    """
    Custom yaml loader to raise an error when duplicate key is found in yaml file.
    """
    def construct_mapping(self, node, deep=False):
        mapping = []
        for key_node, _ in node.value:
            key = self.construct_object(key_node, deep=deep)
            if key in mapping:
                raise YamlKeyDuplicationError(f"Yaml error: duplicate key: {key}")
            mapping.append(key)
        return super().construct_mapping(node, deep)


def join_nodes(rdata, edata):
    """Join nodes defined after the !join constructor"""
    if rdata is None:
        rdata = copy.copy(edata)
    elif has_type(rdata, dict):
        rdata.update(edata)
    else:
        rdata += edata
    return to_value(rdata)


def construct_include(loader, node):
    """Include file referenced at node."""
    try:
        entries = loader.construct_sequence(node)
    except Exception:
        entries = [loader.construct_scalar(node)]

    search_dirs = loader.dirs + loader.custom_dirs

    def load_entry(entry):
        filename = entry
        sub_index = entry.rfind('&')
        sub_node = None
        if sub_index != -1:
            sub_node = entry[sub_index + 1::]
            sub_node = sub_node.split('.')
            filename = entry[:sub_index]

        if os.path.isabs(filename):
            filenames = [filename]
        else:
            filenames = [os.path.abspath(os.path.join(f"{path}/**/", filename))
                         for path in search_dirs]
        extension = os.path.splitext(filename)[1].lstrip('.')

        rdata = None

        file_paths = set(item for pattern in filenames for item in filter_by_glob(loader.yaml_files, pattern))
        for file_path in file_paths:
            sub_yaml = None
            try:
                if extension in ('yaml', 'yml'):
                    sub_yaml = load_yaml(file_path)
                    if sub_node is not None:
                        for nselect in sub_node:
                            if isinstance(sub_yaml, list):
                                nselect = int(nselect)
                            sub_yaml = sub_yaml[nselect]
                else:
                    Error.critical(f'Can only include yaml file: {file_path} file has not supported extension "{extension}"')
            except OSError as err:
                Error.critical(f"Cannot read file {file_path}: {err}")

            rdata = join_nodes(rdata, sub_yaml)

        return rdata

    rdata = None
    for entry in entries:
        edata = load_entry(entry)
        rdata = join_nodes(rdata, edata)
    return rdata


def construct_join(loader, node):
    """join nodes."""

    original = loader.construct_object

    def construct_object(node, deep=False):
        if isinstance(node, yaml.MappingNode):
            return loader.construct_mapping(node, deep)
        if isinstance(node, yaml.SequenceNode):
            return loader.construct_sequence(node, deep)
        return original(node, deep)

    loader.construct_object = construct_object
    try:
        entries = loader.construct_sequence(node)
        rdata = None
        for entry in entries:
            rdata = join_nodes(rdata, entry)

        return rdata
    finally:
        loader.construct_object = original


def construct_concat(loader, node):
    """Custom constructor to create a node by concatenating string values of input nodes"""

    if not isinstance(node, yaml.SequenceNode):
        Error.critical(f"`concat` yaml constructor can operate only on sequence node")

    entries = loader.construct_sequence(node)
    res = ''
    for entry in entries:
        if not isinstance(entry, str):
            Error.critical(f"Items of `concat` yaml constructor must be strings, {entry} has type {type(entry)}")
        res = res + entry

    return res


yaml.add_constructor('!include', construct_include, MyLoader)
yaml.add_constructor('!join', construct_join, MyLoader)
yaml.add_constructor('!concat', construct_concat, MyLoader)

# add additional constructor to force MyLoader loader
# to call our custom construct_yaml_map method when constructing nodes.
MyLoader.add_constructor('tag:yaml.org,2002:map', MyLoader.construct_yaml_map)


@lru_cache
def load_yaml(file_path):
    """Load yaml file in specific dirs using MyLoader custom loader"""
    try:
        with open(file_path) as file:
            return yaml.load(file, MyLoader)
    except OSError as err:
        Error.critical(f"Cannot read file {file_path}: {err}")


def has_type(obj, type_cls):
    """
    A function to determine whether an object is an instance of given type,
    or is an instance of YamlNode which has value of given type.
    Used to eliminate some long checks.
    """
    return obj.is_of_type(type_cls) if isinstance(obj, YamlNode) else isinstance(obj, type_cls)


def to_value(obj):
    """
    A function to return real value of object
    """
    if isinstance(obj, YamlNode):
        return obj.value
    return obj


def yaml_info_struct_to_dict(struct):
    """
    A function to rebuild dict from nested YamlNode object.
    """
    if has_type(struct, dict):
        return {k: yaml_info_struct_to_dict(v) for k, v in struct.items()}
    if has_type(struct, list):
        return [yaml_info_struct_to_dict(i) for i in struct]
    if isinstance(struct, YamlNode):
        return struct.value
    return struct
