import functools
import importlib
import inspect

__all__ = ['bind']

from metaclass import OriginalMethodsMetaclass


class Function:
    """
    Function is a wrap over standard python function.
    """

    def __init__(self, original_function):
        self.function = original_function

    def __call__(self, *args, **kwargs):
        """
        Overriding the __call__ function which makes the
        instance callable.
        """

        fn = Namespace.get_instance().get(self.function, *args)
        if not fn:
            raise Exception("no matching function found.")

        return fn(*args, **kwargs)

    @property
    def classname(self):
        return self.function.__qualname__.split('.')[0]

    @property
    def name(self):
        return self.function.__name__


class Namespace:
    """
    Namespace is the singleton class that is responsible
    for holding all the functions.
    """
    __instance = None

    def __init__(self):
        if self.__instance is None:
            self.function_map = dict()
            Namespace.__instance = self
        else:
            raise Exception("cannot instantiate a virtual Namespace again")

    @staticmethod
    def get_instance():
        if Namespace.__instance is None:
            Namespace()
        return Namespace.__instance

    @staticmethod
    def _key(fn):
        """
        Returns the tuple of module+name and signature of the function.
        """

        signature = str(inspect.signature(fn))
        # fn is a function not a method to get it´s class name using __qualname__
        classname = fn.__qualname__.split('.')[0]
        return (fn.__module__ + classname + fn.__name__,
                signature)

    def register(self, fn):
        """
        registers the function in the virtual namespace and returns
        an instance of callable Function that wraps the
        function fn.
        """
        key = self._key(fn)
        name, signature = key
        if name not in self.function_map:
            self.function_map[name] = {signature: fn}
        else:
            self.function_map[name][signature] = fn

        func = Function(fn)
        return func

    def get(self, fn):
        """
        Returns the matching function from the virtual namespace.

        return None if it did not fund any matching function.
        """
        key = self._key(fn)
        name, signature = key
        return self.function_map.get(name).get(signature)

    def overloads_signature(self, fn):
        """
        Returns overloaded options string if the function is overloaded and an empty string otherwise.
        """
        key = self._key(fn)
        name = key[0]
        overloads = self.function_map.get(name)
        signatures = []
        if len(overloads) > 1:
            for s in overloads:
                signatures.append(fn.__name__ + s)

        return '\n\t'.join(signatures)


class bind:
    """
    Decorator which is responsible for binding wrapper classes with actual pybind classes.
    For overloaded method it appends the overloaded options to it´s docstring.
    """

    def __init__(self, fn):
        namespace = Namespace.get_instance()
        self.fn = namespace.register(fn)
        overloads = namespace.overloads_signature(fn)
        # for properties setting in constructor to not show overloads
        if overloads:
            setattr(self.fn.function, '__doc__', f'{self.fn.function.__doc__}\nOverloads:\n\t{overloads}')
        # for instance methods
        functools.update_wrapper(self, self.fn.function)

        self.cls = None

    def __get__(self, instance, owner):
        """Support instance methods."""

        @functools.wraps(self.fn.function)
        def _decorator(*args, **kwargs):
            if inspect.isclass(instance):
                return instance.originals[self.fn.name].__get__(self.fn.name)(*args, **kwargs)
            return self.cls.originals[self.fn.name](instance, *args, **kwargs)

        return _decorator

    def __set_name__(self, owner, name):
        # set methods class
        self.name = name
        self.cls = owner

    def __call__(self, *args, **kwargs):
        """
        This is called when the decorator is decorated with other decorators.
        Particularly in case of properties and static methods.
        """
        if inspect.isclass(args[0]):
            # case of static method, e.g decorated with @classmethod
            # update self docstring to add overload docstring
            functools.update_wrapper(self, self.fn.function)
            # the first argument is cls
            return args[0].originals[self.fn.name].__get__(self.fn.name)(*args[1:], **kwargs)
