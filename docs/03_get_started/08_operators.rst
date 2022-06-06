Operator Overloading
^^^^^^^^^^^^^^^^^^^^

This section covers an example of overloading arithmetic and comparison operators.
CPP bind will generate apropriate operators or functions for target languages by default. 
If the target language does not allow some of the operators to be overloaded or
we don't want them to be overloaded, we can set the **is_operator** variable to **False**. 
In this case, we must specify the **name** variable so that CppBind will use it to generate a function with that name.


.. literalinclude:: /../examples/primitives/cxx/operators/counter.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


.. note::
    All comparisons in Kotlin are translated into calls to ``compareTo``, that is required to return **Int**.
    That's why we have ``compareTo`` method in C++ with kotlin.is_operator set to True (this is mandatory as compareTo is not a C++ operator and by default, is_operator is False for it).
    Also notice we didn't specify Kotlin instruction for ``operator>``.

.. note::
    We are generating bindings only for **operator+=** for Python and Swift. In Kotlin, the signature of operator **operator+=** is different, it is covered by **operator+**. In this case we specify instructions to generate only **operator+**  for Kotlin.

And the usage example:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/operators/main.kt
           :language: kotlin
           :start-after: [counter-usage]
           :end-before: [counter-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/operators/main.py
           :language: py
           :start-after: [counter-usage]
           :end-before: [counter-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/operators/main.swift
           :language: swift
           :start-after: [counter-usage]
           :end-before: [counter-usage]

.. collapse:: Generated operators for target languages

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/operators/counter.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/operators/counter_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/operators/counter.swift
               :language: swift

|

Overloading subscript operator
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Here is an example of overloading **operator[]**.

.. literalinclude:: /../examples/primitives/cxx/operators/intarray.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Usage example:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/operators/main.kt
           :language: kotlin
           :start-after: [subscript-operator-usage]
           :end-before: [subscript-operator-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/operators/main.py
           :language: py
           :start-after: [subscript-operator-usage]
           :end-before: [subscript-operator-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/operators/main.swift
           :language: swift
           :start-after: [subscript-operator-usage]
           :end-before: [subscript-operator-usage]

.. collapse:: Overloaded subscript operators for target languages

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/operators/intarray.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/operators/intarray_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/operators/intarray.swift
               :language: swift

|

.. note::
    As you can see, we have only generated one set operator. It is the case when the return value of the overloaded subscript operator is a non-const-qualified reference.
