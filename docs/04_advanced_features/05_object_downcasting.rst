Automatic object downcasting
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

When we have an inheritance tree it's possible to keep an object of subtype as an object of base type.
In this case we would construct base type object and in target bindings we would lose the information that the object
is of subtype. In purpose to deal with this problem IEGEN does automatic downcasting to the actual object type if needed.

IEGEN keeps track of the descendant classes/structs for each class/struct to be able to do downcasting of objects.
We pass the object's actual type information from C bindings to target language binding where the downcasting process is done.
IEGEN gives the user opportunity to define the list of descendants via **descendants** variable for each class, otherwise using the deduced one.
In the target bindings the object construction with the actual type is done with switch-case block by comparing type information
with the possible descendant types.

Here is an example of base class with user defined list of descendant classes, which shows possible subtypes we may downcast to if needed.

.. literalinclude:: /../examples/primitives/cxx/templates/container.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. collapse:: Implementation part of downcasting process in target language bindings (the main logic is inside "iegenDowncast" method)

    |

    .. tabs::
        .. tab:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/container.kt
                :language: java

        .. tab:: Python
            .. note::
                Automatic downcasting process for Python is done by PyBind.

        .. tab:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/templates/container.swift
               :language: swift

|
