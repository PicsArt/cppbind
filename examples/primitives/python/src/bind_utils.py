import functools
import importlib
import inspect

__all__ = ['bind']


class Function:
    """
    Function is a wrap over standard python function.
    """

    def __init__(self, original_function, is_overloaded=False):
        self.original_function = original_function
        self.is_overloaded = is_overloaded

    @property
    def classname(self):
        return self.original_function.__qualname__.split('.')[0]

    @property
    def name(self):
        return self.original_function.__name__


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
        func = Function(fn)
        if name not in self.function_map:
            self.function_map[name] = {signature: func}
        else:
            overloads = self.overloads_signature(fn)
            setattr(func.original_function, '__doc__', f'{func.original_function.__doc__}\nOverloads:\n\t{overloads}')
            func.is_overloaded = True
            self.function_map[name][signature] = func

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
        # for instance methods
        functools.update_wrapper(self, self.fn.original_function)
        self.cls = None

    def __get__(self, instance, owner):
        """Support instance methods."""

        @functools.wraps(self.fn.original_function)
        def _decorator(*args, **kwargs):
            if inspect.isclass(instance):
                # for python >= 3.9
                # case of static method, e.g decorated with @classmethod
                if not hasattr(instance, 'originals'):
                    # called on an instance which is of pybind type
                    cls = getattr(importlib.import_module(instance.__module__), instance.__name__)
                else:
                    # instance is iegen generated cls
                    cls = instance
                return cls.originals[self.fn.name].__get__(self.fn.name)(
                    **_map_to_kwargs(self.fn, *args, **kwargs))
            return self.cls.originals[self.fn.name](instance, **_map_to_kwargs(self.fn, *args, **kwargs))

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
            # for python <= 3.8
            # case of static method, e.g decorated with @classmethod
            # update self docstring to add overload docstring
            functools.update_wrapper(self, self.fn.original_function)
            if not hasattr(args[0], 'originals'):
                # called on an instance which is of pybind type i.e the first argument is pybind cls
                cls = getattr(importlib.import_module(args[0].__module__), args[0].__name__)
            else:
                # the first argument is iegen generated cls
                cls = args[0]
            return cls.originals[self.fn.name].__get__(self.fn.name)(
                **_map_to_kwargs(self.fn, *args[1:], **kwargs))
        # get the non pybind class
        cls = getattr(importlib.import_module(args[0].__module__), args[0].__class__.__name__)
        original = cls.originals[self.fn.name]
        if isinstance(original, property):
            if len(args) == 2:
                # setter
                annotation = next(iter(inspect.getfullargspec(self.fn.original_function).annotations.values()))
                # first is self, second is the value
                value = _convert_arg(args[1], annotation)
                return original.fset(args[0], value)
            else:
                # getter
                return original.fget(*args)


def _convert_arg(arg, type_hint):
    try:
        if False:
            pass
        

        elif type_hint == 'int':
            python_to_pybind_arg = int(arg)
            return python_to_pybind_arg
        elif type_hint == 'float':
            python_to_pybind_arg = float(arg)
            return python_to_pybind_arg
        elif type_hint == 'str':
            python_to_pybind_arg = str(arg)
            return python_to_pybind_arg
        return arg
    except TypeError:
        raise TypeError(
            f'To cast {type(arg)} to {type_hint} please provide a __{type_hint}__ method for {type(arg)}.')


def _map_to_kwargs(func, *args, **kwargs):
    all_kwargs = _get_default_args(func.original_function)
    signature = inspect.getfullargspec(func.original_function)
    annotations = signature.annotations
    args_names = signature.args
    'self' in args_names and args_names.remove('self')
    'cls' in args_names and args_names.remove('cls')
    for ii, arg in enumerate(args):
        arg_name = args_names[ii]
        annotation = annotations[arg_name]
        all_kwargs[arg_name] = arg if func.is_overloaded else _convert_arg(arg, annotation)
    for k, v in kwargs.items():
        all_kwargs[k] = v if func.is_overloaded else _convert_arg(v, annotations[k])
    return all_kwargs


def _get_default_args(func):
    signature = inspect.signature(func)
    return {
        k: v.default
        for k, v in signature.parameters.items()
        if v.default is not inspect.Parameter.empty
    }

