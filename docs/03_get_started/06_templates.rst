Templates
^^^^^^^^^
In this part we will cover template methods and classes/structs.
For templates we must explicitly specify all possible types in **__API__**.


Template Methods
~~~~~~~~~~~~~~~~

Let's assume we have a class with two template methods:

.. literalinclude:: /../examples/primitives/cxx/templates/template_methods.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

For all templates we specify **template** attribute in **__API__**.
It's value must be of JSON format and should contain all template arguments as keys. Values are lists. This lists should
contain either strings(all possible types) or objects with **name** and **type** keys. We will see example with **name** and it's usage later.
Now let's see how kotlin wrappers look like:

.. note::
    Keys in **__API__** should be in the same order as in the template parameter list.

.. note::
    We gave template argument's type full name in **__API__** i.e iegen::example::Task not just Task.
    This is mandatory otherwise iegen won't be able to find Task type.

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/template_methods.kt
           :language: kotlin
           :lines: 5-

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/templates/template_methods_pygen.py
           :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/templates/template_methods.swift
           :language: swift


As we can see for **makePair** two overloaded methods are generated with types **Project**, **Project** and **Task**, **Project**.
For **max** again two overloaded methods are generated with **String** and **Int**.
Now we can use them, here are the examples:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/main.kt
           :language: kotlin
           :start-after: [template-funcs-examples]
           :end-before: [template-funcs-examples]

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/templates/main.py
           :language: py
           :start-after: [template-funcs-examples]
           :end-before: [template-funcs-examples]


    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/templates/main.swift
           :language: swift
           :start-after: [template-funcs-examples]
           :end-before: [template-funcs-examples]




Template Classes/Structs
~~~~~~~~~~~~~~~~~~~~~~~~

Now let's generate bindings for a template class Stack. Assume it will hold Projects or Tasks from  :ref:`classes-label-kt` section.
Here is the code in c++:

.. literalinclude:: /../examples/primitives/cxx/templates/stack.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Similarly to methods we shall have a new kotlin class for each combination of types.
Let's take a look at generated wrappers:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/stack.kt
           :language: kotlin
           :lines: 6-

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/templates/stack_pygen.py
           :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/templates/stack.swift
           :language: swift


Here we have two stacks one for Task and the other for Project. Iegen appends template arguments type names to the class name
i.e Task is appended to Stack and we have **StackTask**. For Python as we have used different name(``python.name: PyTask`` in Task's __API__) we have **StackPyTask** instead.

.. note::
    Currently iegen does not support templates with template type as an argument, for example we can't generate a Stack wrapper
    to hold items of type Stack<Task>.

Now let's see what usages we can have for our example Stack. Here is the source code:

 .. literalinclude:: /../examples/primitives/cxx/templates/stack_usage.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Here we have tree methods. First one takes specialized Stack as an argument. It's important to notice that again we have
specified Stack's full name i.e **iegen::example::Stack<Project>**. Namespace is mandatory here.
Second one takes template Stack as an argument and again we have specified it's full name.
Notice that in third one we haven't specified namespace and it does not have an iegen **__API__**. This is an example which is not supported by iegen.

.. note::
    We can have a type inherited for specialized Stack, e.g ``class TaskList : public Stack<Task>``.
    But currently iegen does not support types inherited from template Stack e.g. ``class TaskList<T> : public Stack<T>``.