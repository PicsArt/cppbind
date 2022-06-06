Inheritance
^^^^^^^^^^^

This section covers single and multiple inheritances.

Single Inheritance
~~~~~~~~~~~~~~~~~~

Assume we have two types: ``Bicycle`` inherited from ``Vehicle``:


.. literalinclude:: /../examples/primitives/cxx/inheritance/vehicle.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. literalinclude:: /../examples/primitives/cxx/inheritance/bicycle.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

As this is a single inheritance, we don't have to add something special.
CppBind generates two classes, one inherited from the other.

.. note::
    We have used the same value for the **shared_ref** attribute for both classes.
    It is mandatory. This attribute should be the same in the type hierarchy.

.. note::
    If the type parsed is inherited from another one that does not have an **__API__**, i.e., is not parsed
    by CppBind, then in the binding code, it won't appear as a base type for the target type.

Usage examples:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/main.kt
           :language: kotlin
           :start-after: [simple-inheritance-usage]
           :end-before: [simple-inheritance-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/main.py
           :language: py
           :start-after: [simple-inheritance-usage]
           :end-before: [simple-inheritance-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/inheritance/main.swift
           :language: swift
           :start-after: [simple-inheritance-usage]
           :end-before: [simple-inheritance-usage]

.. collapse:: Generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/vehicle.kt
               :language: java

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/bicycle.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/vehicle_pygen.py
               :language: py

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/bicycle_pygen.py
               :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/vehicle.swift
               :language: swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/bicycle.swift
               :language: swift

|

.. _multiple-inheritance-label:

Multiple Inheritance
~~~~~~~~~~~~~~~~~~~~
Now let's assume we have a type inherited from two others: ``Square` inherited from ``Rectangle`` and ``Rhombus``.
The last two, in their turn, are derived from ``Parallelogram``:

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

Again, we have used the same value for **shared_ref** for all four types.


We used **action: gen_interface** instead of **action: gen_class** for the parent types. Most modern languages do not support multiple inheritance, so we have to tell CppBind to generate interfaces instead.

.. note::
    It's important to note that CppBind supports multiple inheritance for only polymorphic types (when the type has a virtual method/destructor or a polymorphic base).


.. note::
    As Rectangle and Rhombus are interfaces, Parallelogram should also be an interface.

Usage examples:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/main.kt
           :language: kotlin
           :start-after: [multi-inheritance-usage]
           :end-before: [multi-inheritance-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/main.py
           :language: py
           :start-after: [multi-inheritance-usage]
           :end-before: [multi-inheritance-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/inheritance/main.swift
           :language: swift
           :start-after: [multi-inheritance-usage]
           :end-before: [multi-inheritance-usage]

.. collapse:: Here are the generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/parallelogram.kt
               :language: java

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/rectangle.kt
               :language: java

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/rhombus.kt
               :language: java

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/square.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/parallelogram_pygen.py
               :language: py


            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/rectangle_pygen.py
               :language: py

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/rhombus_pygen.py
               :language: py

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/inheritance/square_pygen.py
               :language: py


        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/parallelogram.swift
               :language: swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/rectangle.swift
               :language: swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/rhombus.swift
               :language: swift

            .. literalinclude:: /../examples/primitives/swift/src/inheritance/square.swift
               :language: swift

|
