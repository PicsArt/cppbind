Inheritance
^^^^^^^^^^^

This section covers single and multiple inheritance.

Single Inheritance
~~~~~~~~~~~~~~~~~~

Assume we have two types: **Bicycle** inherited from **Vehicle**:

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
    If the type which is being parsed is inherited from another one which does not have an **__API__** i.e. is not parsed
    by IEGEN then in the binding code it won't appear as a base type for the target type.

As this is a single inheritance we don't have to add something special.
IEGEN will generate two classes one inherited from the other.

Usage examples:

.. tabs::
    .. tab:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/main.kt
           :language: kotlin
           :start-after: [simple-inheritance-usage]
           :end-before: [simple-inheritance-usage]

    .. tab:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/main.py
           :language: py
           :start-after: [simple-inheritance-usage]
           :end-before: [simple-inheritance-usage]

    .. tab:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/inheritance/main.swift
           :language: swift
           :start-after: [simple-inheritance-usage]
           :end-before: [simple-inheritance-usage]

.. collapse:: Generated bindings

    |

    .. tabs::
        .. tab:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/vehicle.kt
               :language: java

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/bicycle.kt
               :language: java

        .. tab:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/vehicle_pygen.py
               :language: py

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/bicycle_pygen.py
               :language: py

        .. tab:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/vehicle.swift
               :language: swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/bicycle.swift
               :language: swift

|

.. _multiple-inheritance-label:

Multiple Inheritance
~~~~~~~~~~~~~~~~~~~~
Now let's assume we have a type inherited from two others: **Square** inherited from **Rectangle** and **Rhombus**.
The last two in their turn are derived from **Parallelogram**:

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
    Here we used **action: gen_interface** instead of **action: gen_class**.
    Most of the modern languages do not support multiple inheritance so we have to tell IEGEN to generate
    interfaces with implementations instead.

.. note::
    It's important to note that IEGEN supports multiple inheritance only for polymorphic types (when type has a virtual method/destructor or has a polymorphic base).

.. note::
    As Rectangle and Rhombus are interfaces then Parallelogram also should be an interface.

Usage examples:

.. tabs::
    .. tab:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/main.kt
           :language: kotlin
           :start-after: [multi-inheritance-usage]
           :end-before: [multi-inheritance-usage]

    .. tab:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/main.py
           :language: py
           :start-after: [multi-inheritance-usage]
           :end-before: [multi-inheritance-usage]

    .. tab:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/inheritance/main.swift
           :language: swift
           :start-after: [multi-inheritance-usage]
           :end-before: [multi-inheritance-usage]

.. collapse:: Here are the generated bindings

    |

    .. tabs::
        .. tab:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/parallelogram.kt
               :language: java

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/rectangle.kt
               :language: java

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/rhombus.kt
               :language: java

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/square.kt
               :language: java

        .. tab:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/parallelogram_pygen.py
               :language: py


            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/rectangle_pygen.py
               :language: py

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/rhombus_pygen.py
               :language: py

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/square_pygen.py
               :language: py


        .. tab:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/parallelogram.swift
               :language: swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/rectangle.swift
               :language: swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/rhombus.swift
               :language: swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/square.swift
               :language: swift

|
