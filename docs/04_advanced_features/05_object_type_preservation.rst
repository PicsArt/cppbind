Object type preservation
^^^^^^^^^^^^^^^^^^^^^^^^

When we have an inheritance tree it's possible to keep an object of subtype as an object of base type.
In this case we would construct base type object and in target bindings we would lose the information that the object
is of subtype. In purpose to deal with this problem IEGEN does object type preservation when constructing an object
of user defined type. Later saved type information is used to recover the original object in C bindings and
construct the object in target language bindings with correct type.

To implement this feature IEGEN keeps track of the descendant classes/structs for each class/struct.
We pass the object's actual type information from C bindings to target language binding where the object construction process is done.
IEGEN gives the user opportunity to define the list of descendants via **descendants** variable for each class, otherwise using the deduced one.
In the target bindings the object construction with the actual type is done with switch-case blocks where we compare preserved type information
with the possible descendant subtypes.

Here is an example of a base class with user-defined list of descendant classes:

.. literalinclude:: /../examples/primitives/cxx/templates/container.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. collapse:: Implementation part of above-described process in target language bindings (the main logic is inside "iegenConstructObject" method)

    |

    .. tab-set::

        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/container.kt
                :language: java

        .. tab-item:: Python

            .. note::
                Object type preservation process for Python is done by pybind.

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/templates/container.swift
               :language: swift

|
