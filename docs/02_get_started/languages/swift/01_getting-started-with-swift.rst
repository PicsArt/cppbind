Binding with Swift
==================
This section demonstrates binding examples for swift from simple to more complex cases.

.. _classes-label:

Classes/Structs
^^^^^^^^^^^^^^^
Let's generate a wrapper code for the following custom type.

.. literalinclude:: /../examples/primitives/cxx/simple/task.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


In a code above we are exporting all public methods and constructors.

.. note::
    Notice that the title method is marked as a getter, so it
    will be a read-only property for the target language.

Generated code for swift looks as follows.

.. literalinclude:: /../examples/primitives/swift/src/simple/task.swift
   :language: swift

.. note::
    In the class **__API__** there's a ``swift.include: CWrapper``. Besides the swift code iegen generates also c binding
    code. We should add appropriate include for our swift code.
    In our examples we are building a single CWrapper library for c code.

Now we are able to use it.

.. literalinclude:: /../examples/primitives/swift/src/simple/main.swift
   :language: swift
   :start-after: [task-usage]
   :end-before: [task-usage]

Let's assume we have another class using the one above.

.. literalinclude:: /../examples/primitives/cxx/simple/project.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
    Here we do not have include attribute for swift as for all our swift examples we build a single Wrapper library.
    If you want to to separate into different libraries it's mandatory to add appropriate include e.g.
    ``swift.include: MyWrapper``.


Here is the generated wrapper code for swift:

.. literalinclude:: /../examples/primitives/swift/src/simple/project.swift
   :language: swift

And the usage example:

.. literalinclude:: /../examples/primitives/swift/src/simple/main.swift
   :language: swift
   :start-after: [project-usage]
   :end-before: [project-usage]

Enums
^^^^^

Now let's generate a binding for an enum.
Here is Color enum definition:

.. literalinclude:: /../examples/primitives/cxx/enums/color.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

And the Frame struct using it:

.. literalinclude:: /../examples/primitives/cxx/enums/frame.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
    We are generating **property_setter** for public field **backgroundColor**.
    A writable property field will correspond to it in python. To generate read-only field we should use **property_getter** instead.

Here is the generated swift code for Color:

.. literalinclude:: /../examples/primitives/swift/src/enums/color.swift
   :language: swift
   :lines: 4-

And for Frame:

.. literalinclude:: /../examples/primitives/swift/src/enums/frame.swift
   :language: swift
   :lines: 4-

Now we are ready to use them:

.. literalinclude:: /../examples/primitives/swift/src/enums/main.swift
   :language: swift
   :start-after: [color-usage]
   :end-before: [color-usage]


Static and overloaded methods
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let's now bind struct with static and overloaded methods:

.. literalinclude:: /../examples/primitives/cxx/overloads/utils.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


As you can see overloaded or static methods are like regular methods. There's nothing special to add in the **API** for them.

Here is the wrapper code:

.. literalinclude:: /../examples/primitives/swift/src/overloads/utils.swift
   :language: swift
   :lines: 4-