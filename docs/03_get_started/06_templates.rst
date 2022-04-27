Templates
^^^^^^^^^
In this section we will cover function and class templates.
For templates user must specify all expected values of template parameters with ``template`` variable.
The value of this variable is a mapping between template parameters and their expected arguments.

Let's see an example:

.. literalinclude:: /../examples/primitives/cxx/templates/template_methods.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Here we have two template member functions ``max`` and ``makePair``.
As you can see we have specified all possible types for each parameter.
IEGEN generates overloaded methods in target languages with each combination of template arguments.

.. note::
    Keys in **__API__** should be in the same order as in the template parameter list.

.. note::
    We specified template argument's type full name in **__API__** i.e iegen::example::Task not just Task.
    This is mandatory otherwise IEGEN won't be able to find required information about specified type.

.. collapse:: Generated bindings

    |

    .. tabs::
        .. tab:: kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/template_methods.kt
               :language: java

        .. tab:: python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/templates/template_methods_pygen.py
               :language: py

        .. tab:: swift

            .. literalinclude:: /../examples/primitives/swift/src/templates/template_methods.swift
               :language: swift

|

As we can see IEGEN generated two overloaded methods for both ``max`` and ``makePair``.
And here are some usage examples:

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


Class templates
~~~~~~~~~~~~~~~

For a class template IEGEN generates a new type for each specialization.
Let's generate bindings for a template class ``Stack``.
We should specify all expected types for template parameter ``T``.

Here is the code in C++:

.. literalinclude:: /../examples/primitives/cxx/templates/stack.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

We specified three possible values for template parameter ``T`` which means there can be three specializations of ``Stack``
(``iegen::example::Stack<iegen::example::Task>``, ``iegen::example::Stack<iegen::example::Project>``, ``iegen::example::Stack<iegen::example::Number<int>>``).
IEGEN will generate a new class for each of this specializations.

Note that we have specified ``name`` property for ``iegen::example::Project`` and ``iegen::example::Number<int>``.
This property is used as a type name postfix in target language i.e
``StackPrj`` will be generated for ``iegen::example::Stack<iegen::example::Project>`` and ``StackNumInt`` for ``iegen::example::Stack<iegen::example::Number<int>>``.

For ``iegen::example::Task`` we have not specified property ``name`` which means its name in target language will be used as a postfix i.e.
``StackPyTask`` will be generated for python and ``StackTask`` for other languages.

Now let's see what usages we can have for our example Stack. Here is the source code:

 .. literalinclude:: /../examples/primitives/cxx/templates/stack_usage.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Here we have four methods taking ``Stack`` as an argument and returning its first element.
The first three methods are supported by IEGEN but you cannot generate bindings for the fourth.
To generate bindings for a function taking template arguments you need to specify their full type names.
The fourth one does not meet this requirement.

.. note::
    IEGEN supports types inherited from a specialized template e.g. ``class TaskList : public Stack<Task>``.
    And to generate bindings for a type inherited from a template(has IEGEN API) you must specify base type's full name e.g. ``class TaskList<T> : public iegen::example::Stack<T>``.

.. collapse:: Generated bindings

    |

    .. tabs::
        .. tab:: kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/stack.kt
               :language: java

        .. tab:: python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/templates/stack_pygen.py
               :language: py

        .. tab:: swift

            .. literalinclude:: /../examples/primitives/swift/src/templates/stack.swift
               :language: swift

|

Template Getters/Setters
~~~~~~~~~~~~~~~~~~~~~~~~

Now let's see how ``name`` is used for template getters/setters.

.. literalinclude:: /../examples/primitives/cxx/getters/fruits.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


In the above example we have a template getter ``fruits`` and we have specified two possible types for parameter ``T``: ``iegen::example::Apple`` and ``iegen::example::Pineapple``.
Notice that ``name`` is specified for both. This means that it'll be used as a generated property name. As a result we'll have ``apple`` and ``pineapple``
correspondingly. If ``name`` is not specified then target language type name will be used.
For this example we would have ``Apple`` and ``Pineapple`` correspondingly.
In the above example we have another template getter/setter ``allFruits`` with two template parameters ``T`` and ``U``.
Again we have specified ``name`` for both parameters.
In case of multiple template parameters target property name is constructed by joining user provided names.
For this example it'll be ``applesWithPineapples`` for kotlin and swift, ``apples_with_pineapples``
for python. Notice that the name is snake cased for python.
The API for this getter could also be written in the following way

.. code-block:: yaml

     T:
       - type: iegen::example::Apple
         name: applesWithPineapples
     U:
       - type: iegen::example::Pineapple

The result will be the same.

If ``name`` is not specified then target property name will be constructed by joining target language types names.
For this example we would have ``applePineapple`` (swift, kotlin) and ``apple_pineapple`` (python).

And here are some usage examples:

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

        .. literalinclude:: /../examples/primitives/swift/src/getters/main.swift
           :language: swift
           :start-after: [template-get-usage]
           :end-before: [template-get-usage]

.. collapse:: Generated bindings for the target languages

    |

    .. tabs::
        .. tab:: kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/getters/fruits.kt
               :language: java

        .. tab:: python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/getters/fruits_pygen.py
               :language: py

        .. tab:: swift

            .. literalinclude:: /../examples/primitives/swift/src/getters/fruits.swift
               :language: swift

|
