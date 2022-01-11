Operator Overloading
^^^^^^^^^^^^^^^^^^^^

In C++, we can make operators to work for user defined classes. This means C++ has the ability to
provide the operators with a special meaning for a data type, this ability is known as operator overloading.
For example, we can overload an operator ‘+’ in a class like String so that we can concatenate two strings
by just using +.


Overloading Arithmetic and Comparison Operators
~~~~~~~~~~~~~~~~~~

This is simple example of overloading arithmetic and comparison operators.
If the target language does not allows some of the operators to be overloaded or
we simply just don't want to do overloading in the target language we can set **is_operator** variable
to **False**. Also we can specify **name** for that operator so in target language will be used that name.


.. literalinclude:: /../examples/primitives/cxx/operators/counter.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


.. note::
    As there is no **operator>** in kotlin we generated it as a standard function not a operator.
    In this case it's very important to set **kotlin.is_operator** **False** and define name for the function using **kotlin.name** variable.
    All comparisons in kotlin are translated into calls to **compareTo**, that is required to return **Int**. For that we have
    **compareTo** operator. We can use **operator>** for python and swift and **compareTo** for kotlin but for the example we keep them both for all languages.

    And **+=** operator we are generating only for python and swift cause there is no return value for this in kotlin. We already have **+(plus)** operator in kotlin which
    also covers **+=** case.

And here are generated operators for target languages.


.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/operators/counter.kt
           :language: kotlin

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/operators/counter_pygen.py
           :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/operators/counter.swift
           :language: swift


Overloading operator[]
~~~~~~~~~~~~~~~~~~

The Subscript or Array Index Operator is denoted by ‘[]’. This operator is
generally used with arrays to retrieve and manipulate the array elements.

Here is the example of overloading **operator[]**.

.. literalinclude:: /../examples/primitives/cxx/operators/intarray.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

And here are overloaded subscript operators for target languages.

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/operators/intarray.kt
           :language: kotlin

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/operators/intarray_pygen.py
           :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/operators/intarray.swift
           :language: swift
