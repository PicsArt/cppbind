from __future__ import annotations
from typing import *
import examples.getters.many_type_template_getter as pybind_many_type_template_getter_pygen
from bind_utils import *
from metaclass import *


class Foo(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    @property
    @bind
    def value(self) -> int:
        """
        comments
        """
        pass

    @value.setter
    @bind
    def value(self, value: int):
        """
        comments
        """
        pass


class Bar(metaclass=OriginalMethodsMetaclass):
    """
    comments
    """
    
    @property
    @bind
    def value(self) -> int:
        """
        comments
        """
        pass

    @value.setter
    @bind
    def value(self, value: int):
        """
        comments
        """
        pass


class ManyTypeTemplateGetter(metaclass=OriginalMethodsMetaclass):
    """
    An example class containing template getters that depend on more than one type.
    """
    
    @bind
    def __init__(self):
        pass
    
    @property
    @bind
    def foo_bar(self) -> tuple:
        """
        Template getter example with return type from more than one template argument.
        As we don´t specify a name here then type names(Foo and Bar) will be used with appropriate naming convention.
        E.g. for python will be foo_bar.
        """
        pass

    @property
    @bind
    def foo_bar_pair(self) -> tuple:
        """
        Template getter example with return type from more than one template argument.
        Giving a name here is important as we have another template getter that can have the same types.
        If we won´t specify the name here then both will have the same name retrieved from types names
        thus this one will override the previous one or the code won´t compile.
        In this case we can specify name only for the first arguments, as for the second we have one option and this way all cases will be covered.
        """
        pass

    @property
    @bind
    def bar_bar_pair(self) -> tuple:
        """
        Template getter example with return type from more than one template argument.
        Giving a name here is important as we have another template getter that can have the same types.
        If we won´t specify the name here then both will have the same name retrieved from types names
        thus this one will override the previous one or the code won´t compile.
        In this case we can specify name only for the first arguments, as for the second we have one option and this way all cases will be covered.
        """
        pass
