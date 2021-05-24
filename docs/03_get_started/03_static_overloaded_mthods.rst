Static and overloaded methods
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let's now bind a struct with static and overloaded methods:

.. literalinclude:: /../examples/primitives/cxx/overloads/utils.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


As you can see overloaded or static methods are like regular methods. There's nothing special to add in the **API** for them.

Here is the wrapper code:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/utils.kt
           :language: kotlin

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/overloads/utils_pygen.py
           :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/overloads/Utils.swift
           :language: swift

.. note::
    Python does not have method overloading, but here with bind decorator we have overloaded sum and concatenate methods.
    Sum is also a classmethod as it was static in original code.


We are ready to use it:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/main.kt
           :language: kotlin
           :start-after: [overload-usage]
           :end-before: [overload-usage]

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/overloads/main.py
           :language: py
           :start-after: [overload-usage]
           :end-before: [overload-usage]

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/overloads/main.swift
           :language: swift
           :start-after: [overload-usage]
           :end-before: [overload-usage]
