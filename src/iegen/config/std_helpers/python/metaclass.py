import functools
import importlib
import os
import sys

__all__ = ['OriginalMethodsMetaclass']


class PyBindOriginals:
    """
    Singleton class that holds pybind types original methods.
    """

    __instance = None

    def __init__(self):
        if self.__instance is None:
            self.originals_map = dict()
            PyBindOriginals.__instance = self
        else:
            raise Exception("Cannot instantiate PyBindOriginals again.")

    @staticmethod
    def get_instance():
        if PyBindOriginals.__instance is None:
            PyBindOriginals()
        return PyBindOriginals.__instance

    def get(self, pybind_class):
        return self.originals_map.get(pybind_class, None)

    def set(self, pybind_class, originals):
        if pybind_class not in self.originals_map:
            self.originals_map[pybind_class] = originals


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
        originals_map = PyBindOriginals.get_instance()
        # get the wrapper´s module
        module = importlib.import_module(future_class_attrs['__module__'])
        # get pybind´s corresponding module
        pybind_module = getattr(module, 'pybind_' + _find_module(cls))
        pybind_class = getattr(pybind_module, future_class_name)
        originals = {}
        # exclude itself and type
        for parent in reversed(cls.mro()[1:-1]):
            # add also parent´s originals
            if isinstance(parent, OriginalMethodsMetaclass):
                originals.update(parent.originals)
        pybind_originals = originals_map.get(pybind_class)

        if not pybind_originals:
            pybind_originals = pybind_class.__dict__.copy()
            originals_map.set(pybind_class, pybind_class.__dict__.copy())
        originals.update(pybind_originals)
        for attr in pybind_class.__dict__:
            if attr in future_class_attrs and attr not in ('__new__', '__init__'):
                # replace pybind method with wrapper method
                setattr(pybind_class, attr, future_class_attrs[attr])
        setattr(cls, 'originals', originals)
        # set __new__ to return pybind instance
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
