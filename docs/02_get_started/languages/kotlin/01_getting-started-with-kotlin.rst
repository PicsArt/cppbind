Binding with Kotlin
===================
This section demonstrates binding examples from simple to more complex cases.

Classes/Structs
^^^^^^^^^^^^^^^
Let´s generate wrapper code for the following custom type.

.. literalinclude:: /../examples/primitives/cxx/simple/task.hpp
   :language: cpp

In a code above we are exporting all public methods and constructors.

.. note::
    Notice that the title method is marked as a getter, so it
    will be a read-only property for the target language.

Generated code for kotlin looks as follows.

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/task.kt
   :language: kotlin
   :lines: 6-

Now we are able to use it.

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/main.kt
   :language: kotlin
   :start-after: [task-usage]
   :end-before: [task-usage]

Let´s assume we have another class using the one above.

.. literalinclude:: /../examples/primitives/cxx/simple/project.hpp
   :language: cpp

.. note::
    We are using **include** attribute based on which appropriate import will be generated for
    each target language. In case of kotlin we do not have this attribute, as both wrappers are generated under the same package.

Here is the generated wrapper code for kotlin:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/project.kt
   :language: kotlin
   :lines: 6-

And the usage example:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/main.kt
   :language: kotlin
   :start-after: [project-usage]
   :end-before: [project-usage]

Enums
^^^^^

Now let´s generate a binding for an enum.
Here is Color enum definition:

.. literalinclude:: /../examples/primitives/cxx/enums/color.hpp
   :language: cpp

And the Frame struct using it:

.. literalinclude:: /../examples/primitives/cxx/enums/frame.hpp
   :language: cpp

.. note::
    We are generating **property_setter** for public field **backgroundColor**.
    A writable property field will correspond to it in kotlin. To generate read-only field we should use **property_getter** instead.

Here is the generated kotlin code for Color:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/color.kt
   :language: kotlin
   :lines: 6-

And for Frame:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/frame.kt
   :language: kotlin
   :lines: 6-

Now we are ready to use them:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/main.kt
   :language: kotlin
   :start-after: [color-usage]
   :end-before: [color-usage]


Static and overloaded methods
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let´s now bind struct with static and overloaded methods:

.. literalinclude:: /../examples/primitives/cxx/overloads/utils.hpp
   :language: cpp


As you can see overloaded or static method are like regular methods. There´s nothing special to add in the **API**  for them.

Here is the wrapper for kotlin:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/utils.kt
   :language: kotlin
   :lines: 6-

We are ready to use it:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/main.kt
   :language: kotlin
   :start-after: [overload-usage]
   :end-before: [overload-usage]

Inheritance
^^^^^^^^^^^

This section covers single and multiple inheritance.

Simple Inheritance
~~~~~~~~~~~~~~~~~~

Assume we have two types **Bicycle** inherited from **Vehicle**:

.. literalinclude:: /../examples/primitives/cxx/inheritance/vehicle.hpp
   :language: cpp

.. literalinclude:: /../examples/primitives/cxx/inheritance/bicycle.hpp
   :language: cpp

.. note::
    For both classes we have used the same value for **shared_ref** attribute.
    This is mandatory. This attribute should be the same in type hierarchy.

As this is a single inheritance we don´t have to add something special.
Iegen will generate two kotlin classes one inherited from the other:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/vehicle.kt
   :language: kotlin
   :lines: 6-

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/bicycle.kt
   :language: kotlin
   :lines: 6-

Now we can use them:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/main.kt
   :language: kotlin
   :start-after: [simple-inheritance-usage]
   :end-before: [simple-inheritance-usage]

Multiple Inheritance
~~~~~~~~~~~~~~~~~~~~
Now let´s assume we have a type inherited from two others **Square** inherited from **Rectangle** and **Rhombus**.
The last two in their turn are based from **Parallelogram**:

.. literalinclude:: /../examples/primitives/cxx/inheritance/parallelogram.hpp
   :language: cpp

.. literalinclude:: /../examples/primitives/cxx/inheritance/rectangle.hpp
   :language: cpp

.. literalinclude:: /../examples/primitives/cxx/inheritance/rhombus.hpp
   :language: cpp

.. literalinclude:: /../examples/primitives/cxx/inheritance/square.hpp
   :language: cpp

In this case again we have used the same value for **shared_ref** for all 4 types.

.. note::
    Here we used **gen: interface** instead of **gen: class**.
    Most of the modern languages do not support multiple inheritance so we have to tell iegen to generate
    interfaces with implementations instead.

Here are the generated wrappers for kotlin:

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/parallelogram.kt
   :language: kotlin
   :lines: 6-


.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/rectangle.kt
   :language: kotlin
   :lines: 6-

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/rhombus.kt
   :language: kotlin
   :lines: 6-

.. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/inheritance/square.kt
   :language: kotlin
   :lines: 6-
