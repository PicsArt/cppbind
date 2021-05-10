Binding with Python
===================
This section demonstrates binding examples for python from simple to more complex cases.
For python bindings iegen uses pybind11. Iegen generates types which are calling pybind code under the hood.


.. _classes-label:

Classes/Structs
^^^^^^^^^^^^^^^
Let's generate a wrapper code for the following custom type.

.. literalinclude:: /../examples/primitives/cxx/simple/task.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


In a code above we are exporting all public methods and constructors.

.. note::
    Notice that the title method is marked as a getter, so it
    will be a read-only property for the target language.

Generated code for python looks as follows.

.. literalinclude:: /../examples/primitives/python/src/simple/task_pygen.py
   :language: py

.. note::
    Here you can see metaclass and bind_utils module imports. These are iegen helper modules. Another thing to note here
    is import of **examples.simple.task** this is pytbind's task module corresponding to iegen's task module.

Now we are able to use it.

.. literalinclude:: /../examples/primitives/python/src/simple/main.py
   :language: py
   :start-after: [task-usage]
   :end-before: [task-usage]

Let's assume we have another class using the one above.

.. literalinclude:: /../examples/primitives/cxx/simple/project.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
    We are using **include** attribute based on which appropriate import will be generated for
    each target language.

Here is the generated wrapper code for python:

.. literalinclude:: /../examples/primitives/python/src/simple/project_pygen.py
   :language: py

And the usage example:

.. literalinclude:: /../examples/primitives/python/src/simple/main.py
   :language: py
   :start-after: [project-usage]
   :end-before: [project-usage]

Enums
^^^^^

Now let's generate a binding for an enum.
Here is Color enum definition:

.. literalinclude:: /../examples/primitives/cxx/enums/color.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

And the Frame struct using it:

.. literalinclude:: /../examples/primitives/cxx/enums/frame.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
    We are generating **property_setter** for public field **backgroundColor**.
    A writable property field will correspond to it in python. To generate read-only field we should use **property_getter** instead.

Here is the generated python code for Color:

.. literalinclude:: /../examples/primitives/python/src/enums/color_pygen.py
   :language: py
   :lines: 8-

And for Frame:

.. literalinclude:: /../examples/primitives/python/src/enums/frame_pygen.py
   :language: py
   :lines: 8-

Now we are ready to use them:

.. literalinclude:: /../examples/primitives/python/src/enums/main.py
   :language: py
   :start-after: [color-usage]
   :end-before: [color-usage]


Static and overloaded methods
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let's now bind struct with static and overloaded methods:

.. literalinclude:: /../examples/primitives/cxx/overloads/utils.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


As you can see overloaded or static methods are like regular methods. There's nothing special to add in the **API** for them.

Here is the wrapper for python:

.. literalinclude:: /../examples/primitives/python/src/overloads/utils_pygen.py
   :language: py
   :lines: 8-

.. note::
    Python does not have method overloading, but here with bind decorator we have overloaded sum and concatenate methods.
    Sum is also a classmethod as it was static in original code.

We are ready to use it:

.. literalinclude:: /../examples/primitives/python/src/overloads/main.py
   :language: py
   :start-after: [overload-usage]
   :end-before: [overload-usage]

Inheritance
^^^^^^^^^^^

This section covers single and multiple inheritance.

Single Inheritance
~~~~~~~~~~~~~~~~~~

Assume we have two types **Bicycle** inherited from **Vehicle**:

.. literalinclude:: /../examples/primitives/cxx/inheritance/vehicle.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. literalinclude:: /../examples/primitives/cxx/inheritance/bicycle.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
    For both classes we have used the same value for **shared_ref** attribute.
    This is mandatory. This attribute should be the same in type hierarchy.

.. note::
    Currently iegen supports inheritance with polymorphic types only.

.. note::
    If the type which is being parsed is inherited from another one which does not have an **__API__** i.e is not parsed
    by iegen then in the wrapper code it won't appear as a base type for the target type.

As this is a single inheritance we don't have to add something special.
Iegen will generate two python classes one inherited from the other:

.. literalinclude:: /../examples/primitives/python/src/inheritance/vehicle_pygen.py
   :language: py
   :lines: 8-

.. literalinclude:: /../examples/primitives/python/src/inheritance/bicycle_pygen.py
   :language: py
   :lines: 9-

Now we can use them:

.. literalinclude:: /../examples/primitives/python/src/inheritance/main.py
   :language: py
   :start-after: [simple-inheritance-usage]
   :end-before: [simple-inheritance-usage]

Multiple Inheritance
~~~~~~~~~~~~~~~~~~~~
Now let's assume we have a type inherited from two others **Square** inherited from **Rectangle** and **Rhombus**.
The last two in their turn are based from **Parallelogram**:

.. literalinclude:: /../examples/primitives/cxx/inheritance/parallelogram.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. literalinclude:: /../examples/primitives/cxx/inheritance/rectangle.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. literalinclude:: /../examples/primitives/cxx/inheritance/rhombus.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. literalinclude:: /../examples/primitives/cxx/inheritance/square.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

In this case again we have used the same value for **shared_ref** for all 4 types.

.. note::
    Here we used **gen: interface** instead of **gen: class**. If you are using for python only then there's you can use
    **gen: class**. Here we use **gen: interface** as these examples are used for all languages and most of the do
    not support multiple inheritance.

.. note::
    It's important to note that in case of multiple inheritance all parent's should have the same root type,
    otherwise an error will be thrown and the code won't be parsed.

Here are the generated wrappers for python:

.. literalinclude:: /../examples/primitives/python/src/inheritance/parallelogram_pygen.py
   :language: py
   :lines: 9-


.. literalinclude:: /../examples/primitives/python/src/inheritance/rectangle_pygen.py
   :language: py
   :lines: 9-

.. literalinclude:: /../examples/primitives/python/src/inheritance/rhombus_pygen.py
   :language: py
   :lines: 9-

.. literalinclude:: /../examples/primitives/python/src/inheritance/square_pygen.py
   :language: py
   :lines: 10-

.. note::
    As Rectangle and Rhombus are interfaces then Parallelogram also should be an interface.

Now we are ready to use them:

.. literalinclude:: /../examples/primitives/python/src/inheritance/main.py
   :language: py
   :start-after: [multi-inheritance-usage]
   :end-before: [multi-inheritance-usage]

Templates
^^^^^^^^^
In this part we will cover template methods and classes/structs.
For templates we must explicitly specify all possible types in **__API__**.


Template Methods
~~~~~~~~~~~~~~~~

Let's assume we have a class with two template methods:

.. literalinclude:: /../examples/primitives/cxx/templates/template_functions.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

For all templates we specify **template** attribute in **__API__**.
It's value must be of JSON format and should contain all template arguments as keys. Values are lists. This lists should
contain either strings(all possible types) or objects with **name** and **type** keys. We will see example with **name** and it's usage later.
Now let's see how python wrappers look like:

.. note::
    Keys in **__API__** should be in the same order as in the template parameter list.

.. note::
    We gave template argument's type full name in **__API__** i.e iegen::example::Task not just Task.
    This is mandatory otherwise iegen won't be able to find Task type.

.. literalinclude:: /../examples/primitives/python/src/templates/template_functions_pygen.py
   :language: py
   :lines: 10-

As we can see for **makePair** two overloaded methods are generated with types **Project**, **Project** and **Task**, **Project**.
For **max** again two overloaded methods are generated with **String** and **Int**.
Now we can use them, here is an example:

.. literalinclude:: /../examples/primitives/python/src/templates/main.py
   :language: py
   :start-after: [template-funcs-examples]
   :end-before: [template-funcs-examples]


Template Classes/Structs
~~~~~~~~~~~~~~~~~~~~~~~~

Now let's generate bindings for a template class Stack. Assume it will hold Projects or Tasks from  :ref:`classes-label` section.
Here is the code in c++:

.. literalinclude:: /../examples/primitives/cxx/templates/stack.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Similarly to methods we shall have a new python class for each combination of types.
Let's take a look at generated python wrappers:

.. literalinclude:: /../examples/primitives/python/src/templates/stack_pygen.py
   :language: py
   :lines: 10-

Here we have two stacks one for Task and the other for Project. Iegen appends template arguments type names to the class name
i.e Task is appended to Stack an we have **StackTask**.

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