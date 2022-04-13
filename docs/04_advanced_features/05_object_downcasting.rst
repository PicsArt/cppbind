Automatic object down casting
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

When we have an inheritance tree it's possible to keep an object of subtype as an object of base type.
In this case we would construct base type object and in target wrappers we would lose the information that the object
is of subtype. In purpose to deal with this problem iegen does automatic down casting to the actual object type if needed.

Iegen keeps track of the descendant classes/structs for each class/struct to be able to do down casting of objects.
We pass the object actual type information from C wrappers to target language wrapper where the down casting process is done.
Iegen gives the user opportunity to define the list of descendants via **descendants** variable for each class, otherwise using the deduced one.
In the target wrappers the object construction with the actual type is done with switch-case block by comparing type information
with the possible descendant types.

Here is an example of base class with user defined list of descendant classes, which shows possible subtypes we may downcast to if needed.

.. literalinclude:: /../examples/primitives/cxx/templates/container.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. collapse:: Implementation part of down casting process in target language wrappers (the main logic is inside "iegenDowncast" method)

    |

    .. tabs::
        .. tab:: kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/templates/container.kt
                :language: java

        .. tab:: python
            .. note::
                Automatic down casting process for python is done by PyBind.

        .. tab:: swift

            .. literalinclude:: /../examples/primitives/swift/src/templates/container.swift
               :language: swift

|
