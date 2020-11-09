"""
Helper module for processing yaml files
"""
import os
import copy
import yaml
import glob


class MyLoader(yaml.SafeLoader):
    """YAML MyLoader with `!include` constructor."""

    def __init__(self, stream):
        """Initialise MyLoader."""

        try:
            self._root = os.path.split(stream.name)[0]
        except AttributeError:
            self._root = os.path.curdir

        super().__init__(stream)


def join_nodes(rdata, edata):
    if rdata is None:
        rdata = copy.copy(edata)
    elif isinstance(rdata, dict):
        rdata.update(edata)
    else:
        rdata += edata
    return rdata


def construct_include(loader, node):
    """Include file referenced at node."""

    try:
        entries = loader.construct_sequence(node)
    except Exception:
        entries = [loader.construct_scalar(node)]

    def load_entry(entry):
        filename = entry
        sub_index = entry.rfind('&')
        sub_node = None
        if sub_index != -1:
            sub_node = entry[sub_index+1::]
            sub_node = sub_node.split('.')
            filename = entry[:sub_index]

        filename = os.path.abspath(os.path.join(loader._root, filename))
        extension = os.path.splitext(filename)[1].lstrip('.')

        rdata = None

        for fn in glob.glob(filename):
            sub_yaml = None
            with open(fn, 'r') as f:
                if extension in ('yaml', 'yml'):
                    sub_yaml = yaml.load(f, MyLoader)
                    if sub_node is not None:
                        for nselect in sub_node:
                            if isinstance(sub_yaml, list):
                                nselect = int(nselect)
                            sub_yaml = sub_yaml[nselect]
                else:
                    raise Exception('can only include yaml file')
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
        else:
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


yaml.add_constructor('!include', construct_include, MyLoader)

yaml.add_constructor('!join', construct_join, MyLoader)


def load_yaml(file_path):
    with open(file_path) as f:
        return yaml.load(f, MyLoader)
