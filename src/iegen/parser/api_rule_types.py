import os
from abc import abstractmethod, ABC
from enum import Enum

from iegen.utils.clang import join_type_parts


class ApiRuleType(ABC):

    def __init__(self, name):
        self.name = name

    @abstractmethod
    def key(self, *args, **kwargs):
        pass


class TypeRuleType(ApiRuleType):

    def __init__(self):
        super().__init__('type')

    def key(self, *args, **kwargs):
        return join_type_parts(kwargs['ancestors'])


class FileRuleType(ApiRuleType):

    def __init__(self):
        super().__init__('file')

    def key(self, *args, **kwargs):
        file_name = kwargs['src_dict'][self.name]
        if os.path.isabs(file_name):
            # if an absolute path is specified then we assume it's absolute to current dir
            flat_key = file_name.replace('/', '', 1)
            flat_key = os.path.join(flat_key, os.getcwd())
        else:
            flat_key = os.path.abspath(os.path.join(os.path.dirname(kwargs['current_file']), file_name))
        return flat_key


class DirApiType(ApiRuleType):

    def __init__(self):
        super().__init__('dir')

    def key(self, *args, **kwargs):
        dir_name = kwargs['src_dict'][self.name]
        if os.path.isabs(dir_name):
            # if an absolute path is specified then we assume it's absolute to current dir
            flat_key = dir_name.replace('/', '', 1)
            flat_key = os.path.relpath(os.path.join(flat_key, os.getcwd()), os.getcwd())
        else:
            flat_key = os.path.relpath(
                os.path.abspath(os.path.join(os.path.dirname(kwargs['current_file']), dir_name)),
                os.getcwd())
        return flat_key


class NodeApiType(Enum):
    TYPE = TypeRuleType()
    DIR = DirApiType()
    FILE = FileRuleType()

    @staticmethod
    def assert_has_one(source):
        count = 0
        for rule in NodeApiType:
            if rule.value.name in source:
                count += 1
        if count != 1:
            raise AssertionError(f'API can contain only one of the keywords: {[r.value.name for r in NodeApiType]}')

    @staticmethod
    def get_rule(source):
        for rule in NodeApiType:
            if rule.value.name in source:
                return rule.value
