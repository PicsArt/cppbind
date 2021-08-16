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
contain either strings(all possible types) or objects with **name** and **type** keys. We will see an example with **name** and it's usage later.
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

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/templates/template_methods_pygen.py
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

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/templates/main.py
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

Now let's generate bindings for a template class Stack. Assume it will hold Projects or Tasks from  :ref:`classes-label` section.
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

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/templates/stack_pygen.py
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


Template Getters/Setters
~~~~~~~~~~~~~~~~~~~~~~~~

Now let's see how **name** is used for template getters/setters.

.. literalinclude:: /../examples/primitives/cxx/getters/fruits.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


In the above example we have a template getter **fruits**. Here we have specified two possible types for parameter **T** Apple and Pineapple.
Notice that **name** is specified for both. This means that it'll be used as a property name in the target language. As a result we'll have apple and pineapple
correspondingly. If for template getter types no name is specified then **type** name will be used as a property name.
For this example we would have Apple And Pineapple correspondingly.
For the all tree target languages we will have apples and pineapple correspondingly.
In the above example we have another template getter/setter **allFruits** with two parameters **T** and **U**. Notice we have used name for both **T** and **U**.
In case of multiple parameters for each combination of template parameters appropriate names are joined.
For this example it'll be **applesWithPineapples** for kotlin and swift, **apples_with_pineapples**
for python. Notice that the name is snake cased for python.
The API for this getter could also be written in the following way

.. code-block:: yaml

     T:
       - type: iegen::example::Apple
         name: applesWithPineapples
     U:
       - type: iegen::example::Pineapple

The result will be the same.

If no name is specified then type names are being joined. For python additionally it'll be converted to snake case.
For this example we would have applePineapple(swift, kotlin) and apple_pineapple(python).

Let's see the generated APIs for the target languages.

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/getters/fruits.kt
           :language: kotlin

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/getters/fruits_pygen.py
           :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/python/src/getters/fruits.swift
           :language: swift

And the usage examples

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/getters/main.kt
           :language: kotlin
           :start-after: [template-get-usage]
           :end-before: [template-get-usage]

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/getters/main.py
           :language: py
           :start-after: [template-get-usage]
           :end-before: [template-get-usage]

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/python/src/getters/main.swift
           :language: swift
           :start-after: [template-get-usage]
           :end-before: [template-get-usage]
