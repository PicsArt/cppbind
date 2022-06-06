Templates
^^^^^^^^^
This section covers function and class templates.
To generate bindings for function and class templates, we specify all expected values of template parameters with the ``template`` variable.
The value of ``template`` variable is a mapping between template parameters and their expected arguments.

Let's see an example:

.. literalinclude:: /../examples/primitives/cxx/templates/template_methods.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Here we have two template member functions: ``max`` and ``makePair``.
As you can see, we have specified all possible types for each parameter.
CppBind generates overloaded methods in target languages with each combination of template arguments.

.. note::
    Keys in **__API__** should be in the same order as the template parameter list.

.. note::
    We specified the template argument's type full name in **__API__**, i.e., cppbind::example::Task, not just Task.
    It is mandatory; otherwise, CppBind cannot find the required information about the specified type.

.. collapse:: Generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/template_methods.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/templates/template_methods_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/templates/template_methods.swift
               :language: swift

|

As we can see, CppBind generated two overloaded methods for both ``max`` and ``makePair``.
And here are some usage examples:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/main.kt
           :language: kotlin
           :start-after: [template-funcs-examples]
           :end-before: [template-funcs-examples]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/templates/main.py
           :language: py
           :start-after: [template-funcs-examples]
           :end-before: [template-funcs-examples]


    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/templates/main.swift
           :language: swift
           :start-after: [template-funcs-examples]
           :end-before: [template-funcs-examples]


Class templates
~~~~~~~~~~~~~~~
For a class template, CppBind generates a new type for each specialization. 
Let's generate bindings for a template class ``Stack``. 
We should specify all expected types for template parameter ``T``.

Here is the code in C++:

.. literalinclude:: /../examples/primitives/cxx/templates/stack.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

We specified three possible values for template parameter ``T`` which means there can be three specializations of ``Stack`` (``cppbind::example::Stack<cppbind::example::Task>``, ``cppbind::example::Stack<cppbind::example::Project>``, ``cppbind::example::Stack<cppbind::example::Number<int>>``). 
CppBind will generate a new class for each of this specializations.

Note that we have specified ``name`` property for ``cppbind::example::Project`` and ``cppbind::example::Number<int>``.
This property is used as a type name postfix in target language, i.e.
``StackPrj`` will be generated for ``cppbind::example::Stack<cppbind::example::Project>`` and ``StackNumInt`` for ``cppbind::example::Stack<cppbind::example::Number<int>>``.

For ``cppbind::example::Task``, we have not specified the property ``name``, which means its name in the target language is used as a postfix, i.e., ``StackPyTask`` is generated for Python and ``StackTask`` for other languages.


.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/main.kt
           :language: kotlin
           :start-after: [stack-examples]
           :end-before: [stack-examples]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/templates/main.py
           :language: py
           :start-after: [stack-examples]
           :end-before: [stack-examples]


    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/templates/main.swift
           :language: swift
           :start-after: [stack-examples]
           :end-before: [stack-examples]

Now let's see the usages of our example, Stack. Here is the source code:

.. literalinclude:: /../examples/primitives/cxx/templates/stack_usage.hpp
    :language: cpp
    :start-after: [example]
    :end-before: [example]

Here we have four methods to take ``Stack`` as an argument and return its first element.
CppBind supports the first three methods, but you cannot generate bindings for the fourth.
To generate bindings for a function taking template arguments, you must specify their full type names.
The fourth one does not meet this requirement.

.. note::
    CppBind supports types inherited from a specialized template, e.g., ``class TaskList: public Stack<Task>``. 
    And to generate bindings for a type inherited from a template(has CppBind API), you must specify the base type's full name, e.g., ``class TaskList<T>: public cppbind::example::Stack<T>``.

.. collapse:: Generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/stack.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/templates/stack_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/templates/stack.swift
               :language: swift

|

Template Getters/Setters
~~~~~~~~~~~~~~~~~~~~~~~~

Now let's see how the ``name`` is used for template getters/setters.


.. literalinclude:: /../examples/primitives/cxx/getters/fruits.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

In the above example, we have a template getter ``fruits``, and we have specified two possible types for parameter ``T``: ``cppbind::example::Apple`` and ``cppbind::example::Pineapple``. 
Notice that the ``name`` is specified for both, which is used as a generated property name. As a result, we'll have ``apple`` and ``pineapple`` correspondingly. If ``name`` is not specified, then the target language type name is used. 
For this example, we would have ``Apple`` and ``Pineapple`` correspondingly. 
In the above example, we have another template getter/setter, ``allFruits`` with two template parameters, ``T`` and ``U``. 
Again, we have specified ``name`` for both parameters. 
In the case of multiple template parameters, target property name is constructed by joining user-provided names. 
For this example, it is ``applesWithPineapples`` for Kotlin and Swift, ``apples_with_pineapples`` for Python. 
Notice that the name is snake-cased for Python. 
The API for this getter could also be written in the following way:

.. code-block:: yaml

     T:
       - type: cppbind::example::Apple
         name: applesWithPineapples
     U:
       - type: cppbind::example::Pineapple

The result will be the same.

If the ``name`` is not specified, the target property name is constructed by joining the names of target language types. 
For this example, we would have ``applePineapple`` (Swift, Kotlin) and ``apple_pineapple`` (Python).

And here are some usage examples:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/getters/main.kt
           :language: kotlin
           :start-after: [template-get-usage]
           :end-before: [template-get-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/getters/main.py
           :language: py
           :start-after: [template-get-usage]
           :end-before: [template-get-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/getters/main.swift
           :language: swift
           :start-after: [template-get-usage]
           :end-before: [template-get-usage]

.. collapse:: Generated bindings for the target languages

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/getters/fruits.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/getters/fruits_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/getters/fruits.swift
               :language: swift

|
