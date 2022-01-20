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

Generated code for the target language looks as follows.

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/task.kt
            :language: kotlin

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/simple/task/task_pygen.py
            :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/simple/task.swift
           :language: swift

.. note::
    By default iegen generates ``System.loadLibrary("wrapper_jni")`` for each kotlin class. To disable this behaviour define **c_wrapper_lib_name** with null value:
    ``c_wrapper_lib_name: null`` or ``c_wrapper_lib_name:``.

Now we are able to use them.

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/main.kt
            :language: kotlin
            :start-after: [task-usage]
            :end-before: [task-usage]

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/simple/main.py
            :language: python
            :start-after: [task-usage]
            :end-before: [task-usage]

    .. tab:: swift

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
    We are using **include** attribute based on which appropriate import will be generated for
    each target language. In case of kotlin we do not have this attribute, as both wrappers are generated under the same package.

Here are the generated wrappers:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/project.kt
           :language: kotlin

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/simple/project_pygen.py
            :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/simple/project.swift
           :language: swift


And the usage example:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/main.kt
            :language: kotlin
            :start-after: [project-usage]
            :end-before: [project-usage]

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/simple/main.py
            :language: py
            :start-after: [project-usage]
            :end-before: [project-usage]

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/simple/main.swift
            :language: swift
            :start-after: [project-usage]
            :end-before: [project-usage]

Nested Types
~~~~~~~~~~~~

Let's now generate bindings for nested types.
Here's a small example:

.. literalinclude:: /../examples/primitives/cxx/nested_types/list.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

And here are the generated bindings for the above types:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/nested_types/list.kt
           :language: kotlin

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/nested_types/list.swift
           :language: swift

As we can see nested types are nested in target languages as well.

And here are some usage examples:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/nested_types/main.kt
            :language: kotlin
            :start-after: [nested-types-usage]
            :end-before: [nested-types-usage]


    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/nested_types/main.swift
            :language: swift
            :start-after: [nested-types-usage]
            :end-before: [nested-types-usage]