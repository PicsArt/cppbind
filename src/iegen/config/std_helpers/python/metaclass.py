import functools
import importlib
import os
import sys

__all__ = ['OriginalMethodsMetaclass']


class OriginalMethodsMetaclass(type):
    """
    Metaclass for all wrappers. This type is responsible for adding originals(dictionary which contains pybind´s
    original methods) to wrapper. It also replaces pybind´s methods with wrappers methods. So that instead of pybind´s
    method wrapper´s method is getting called, which in itś turn calls the original function for the originals dictionary.
    Also defines __new__ for the wrapper class to create an instance of pybind class.
    """

    def __init__(cls, future_class_name, future_class_parents, future_class_attrs):
        """
        Adds the originals to wrapper class and replaces pybind´s methods with wrappers methods.
        Also defines __new__ for the wrapper class to create an instance of pybind class.
        """
        # get the wrapper´s module
        module = importlib.import_module(future_class_attrs['__module__'])
        # get pybind´s corresponding module
        pybind_module = getattr(module, 'pybind_' + _find_module(cls))
        pybind_class = getattr(pybind_module, future_class_name)
        cls.originals = {}
        for parent in cls.mro():
            # add also parent´s originals
            if isinstance(parent, OriginalMethodsMetaclass):
                cls.originals.update(parent.originals)
        cls.originals.update(pybind_class.__dict__.copy())
        for attr in pybind_class.__dict__:
            if attr in future_class_attrs and attr not in ('__new__', '__init__'):
                # replace pybind method with wrapper method
                setattr(pybind_class, attr, future_class_attrs[attr])
        # set __new__  to return pybind instance
        setattr(cls, '__new__', functools.partial(_new_object, pybind_class))
        type.__init__(cls, future_class_name, future_class_parents, future_class_attrs)

    def __instancecheck__(self, instance):
        """
        This is responsible for correct instance check for wrapper class.
        As for wrapper´s an instance of pybind class is returned then we need this to return true for wrapper instances.
        """
        # get the wrapper´s module
        module = importlib.import_module(self.__module__)
        # get pybind´s corresponding module
        pybind_module = getattr(module, 'pybind_' + _find_module(self))
        # check if wrapper instance is instance of pybind type
        return isinstance(instance, getattr(pybind_module, self.__name__))


def _new_object(pybind_type, cls, *args, **kwargs):
    """Helper used with functools to override __new__."""
    return pybind_type(*args, **kwargs)


def _find_module(cls):
    """Retrieves last part from the module´s full module name."""
    cls_module = cls.__module__
    if cls_module == '__main__':
        filename = sys.modules[cls_module].__file__
        cls_module = os.path.splitext(os.path.basename(filename))[0]
    return cls_module.split('.')[-1]
