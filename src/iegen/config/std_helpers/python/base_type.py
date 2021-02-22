import importlib
import os
import sys

__all__ = ['OriginalMethodsMetaclass']


class OriginalMethodsMetaclass(type):

    def __init__(cls, future_class_name, future_class_parents, future_class_attrs):
        pybind_module = importlib.import_module(_find_module(cls))
        pybind_type = getattr(pybind_module, future_class_name)
        cls.originals = pybind_type.__dict__.copy()
        for attr in pybind_type.__dict__:
            if attr in future_class_attrs and attr not in ('__new__', '__init__'):
                setattr(pybind_type, attr, future_class_attrs[attr])
        type.__init__(cls, future_class_name, future_class_parents, future_class_attrs)

    def __instancecheck__(cls, instance):
        # todo handle super
        pybind_module = importlib.import_module(_find_module(cls))
        return isinstance(instance, getattr(pybind_module, cls.__name__))


def _find_module(cls):
    cls_module = cls.__module__
    if cls_module == '__main__':
        filename = sys.modules[cls_module].__file__
        cls_module = os.path.splitext(os.path.basename(filename))[0]
    return 'pybind_' + cls_module.split('.')[-1]
