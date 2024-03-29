"""
  ______ .______   .______   .______    __  .__   __.  _______  
 /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
|  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
|  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
|  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 

This file is generated by cppbind on 11/24/2022-07:17.
Please do not change it manually.
"""
from __future__ import annotations

from typing import *

import examples.templates.stack as pybind_stack_pygen
import examples_lib.templates.container_pygen as container_pygen
from examples_lib.cppbind.cppbind_metaclass_pygen import *
from examples_lib.cppbind.cppbind_utils_pygen import *

if TYPE_CHECKING:
    import examples_lib.getters.number_pygen as getters_number_pygen
    import examples_lib.simple.project_pygen as simple_project_pygen
    import examples_lib.simple.task.task_pygen as simple_task_task_pygen


class StackPrj(container_pygen.Container, metaclass=CppBindMetaclass):
    """
    An example of a class template.
    """
    
    @bind
    def __init__(self):
        
        pass

    @bind
    def __init__(self, stack: StackPrj):
        """
        Full type name(i.e., cppbind::example::Stack<T> not just Stack<T>) should be explicitly specified otherwise
        cppbind won't be able to generate a converter for the argument, as for templates libclang does not provide
        enough information.
        """
        pass

    @bind
    def __init__(self, st: simple_project_pygen.Project):
        
        pass
    
    @bind
    def push(self, item: simple_project_pygen.Project) -> None:
        
        pass

    @bind
    def pop(self) -> None:
        
        pass

    @bind
    def top(self) -> simple_project_pygen.Project:
        
        pass

    @bind
    def empty(self) -> bool:
        
        pass


class StackPyTask(container_pygen.Container, metaclass=CppBindMetaclass):
    """
    An example of a class template.
    """
    
    @bind
    def __init__(self):
        
        pass

    @bind
    def __init__(self, stack: StackPyTask):
        """
        Full type name(i.e., cppbind::example::Stack<T> not just Stack<T>) should be explicitly specified otherwise
        cppbind won't be able to generate a converter for the argument, as for templates libclang does not provide
        enough information.
        """
        pass

    @bind
    def __init__(self, st: simple_task_task_pygen.PyTask):
        
        pass
    
    @bind
    def push(self, item: simple_task_task_pygen.PyTask) -> None:
        
        pass

    @bind
    def pop(self) -> None:
        
        pass

    @bind
    def top(self) -> simple_task_task_pygen.PyTask:
        
        pass

    @bind
    def empty(self) -> bool:
        
        pass


class StackNumInt(container_pygen.Container, metaclass=CppBindMetaclass):
    """
    An example of a class template.
    """
    
    @bind
    def __init__(self):
        
        pass

    @bind
    def __init__(self, stack: StackNumInt):
        """
        Full type name(i.e., cppbind::example::Stack<T> not just Stack<T>) should be explicitly specified otherwise
        cppbind won't be able to generate a converter for the argument, as for templates libclang does not provide
        enough information.
        """
        pass

    @bind
    def __init__(self, st: getters_number_pygen.NumberInt):
        
        pass
    
    @bind
    def push(self, item: getters_number_pygen.NumberInt) -> None:
        
        pass

    @bind
    def pop(self) -> None:
        
        pass

    @bind
    def top(self) -> getters_number_pygen.NumberInt:
        
        pass

    @bind
    def empty(self) -> bool:
        
        pass
