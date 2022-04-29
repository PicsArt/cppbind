Operator Overloading
^^^^^^^^^^^^^^^^^^^^

An example of overloading arithmetic and comparison operators.
If the target language does not allow some of the operators to be overloaded or
we just don't want to overload them in the target language we can set **is_operator** variable
to **False**. In that case we should also specify **name** for that operator so in target language will be used that name.


.. literalinclude:: /../examples/primitives/cxx/operators/counter.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


.. note::
    All comparisons in Kotlin are translated into calls to **compareTo**, that is required to return **Int**.
    That's why we have **compareTo** method in C++ with kotlin.is_operator set to True(This is mandatory as compareTo is not a C++ operator and by default, is_operator is False for it ).
    Also notice we do not have Kotlin action for **operator>**.

.. note::
    For **+=** operator we are generating bindings only for Python and Swift because for Kotlin the signature of this operator is different and
    we already have generated binding for **+** operator which covers also **+=** operator.

And the usage example:

.. tabs::
    .. tab:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/operators/main.kt
           :language: kotlin
           :start-after: [counter-usage]
           :end-before: [counter-usage]

    .. tab:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/operators/main.py
           :language: py
           :start-after: [counter-usage]
           :end-before: [counter-usage]

    .. tab:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/operators/main.swift
           :language: swift
           :start-after: [counter-usage]
           :end-before: [counter-usage]

.. collapse:: Generated operators for target languages

    |

    .. tabs::
        .. tab:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/operators/counter.kt
               :language: java

        .. tab:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/operators/counter_pygen.py
               :language: py

        .. tab:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/operators/counter.swift
               :language: swift

|

Overloading subscript operator
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Here is the example of overloading **operator[]**.

.. literalinclude:: /../examples/primitives/cxx/operators/intarray.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Usage example:

.. tabs::
    .. tab:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/operators/main.kt
           :language: kotlin
           :start-after: [subscript-operator-usage]
           :end-before: [subscript-operator-usage]

    .. tab:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/operators/main.py
           :language: py
           :start-after: [subscript-operator-usage]
           :end-before: [subscript-operator-usage]

    .. tab:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/operators/main.swift
           :language: swift
           :start-after: [subscript-operator-usage]
           :end-before: [subscript-operator-usage]

.. collapse:: Overloaded subscript operators for target languages

    |

    .. tabs::
        .. tab:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/operators/intarray.kt
               :language: java

        .. tab:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/operators/intarray_pygen.py
               :language: py

        .. tab:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/operators/intarray.swift
               :language: swift

|

.. note::
    As we can see we have only generated one set operator. This is the case when the return value of overloaded subscript operator is a non const qualified reference.
