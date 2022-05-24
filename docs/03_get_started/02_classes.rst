.. _classes-label:

Classes/Structs
^^^^^^^^^^^^^^^
Let's generate a binding code for the following custom type.

.. literalinclude:: /../examples/primitives/cxx/simple/task.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


In the code above, we are exporting all public members and constructors.

.. note::
    The title method is marked as a getter, a read-only property for the target language.

.. note::
    By default, CppBind generates ``System.loadLibrary("wrapper_jni")`` for each Kotlin class. To disable this behavior define **c_wrapper_lib_name** with null value:  **c_wrapper_lib_name: null** or **c_wrapper_lib_name:**.

Usage examples:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/main.kt
            :language: kotlin
            :start-after: [task-usage]
            :end-before: [task-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/simple/main.py
            :language: python
            :start-after: [task-usage]
            :end-before: [task-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/simple/main.swift
            :language: swift
            :start-after: [task-usage]
            :end-before: [task-usage]

.. collapse:: Generated code for the target languages

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/task.kt
                :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/simple/task/task_pygen.py
                :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/simple/task.swift
               :language: swift

|

Let's assume we have another class using the one above.

.. literalinclude:: /../examples/primitives/cxx/simple/project.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

And the usage example:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/main.kt
            :language: kotlin
            :start-after: [project-usage]
            :end-before: [project-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/simple/main.py
            :language: py
            :start-after: [project-usage]
            :end-before: [project-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/simple/main.swift
            :language: swift
            :start-after: [project-usage]
            :end-before: [project-usage]

.. collapse:: Here are the generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/simple/project.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/simple/project_pygen.py
                :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/simple/project.swift
               :language: swift

|

Nested Types
~~~~~~~~~~~~

Let's now generate bindings for nested types. Here's a small example:

.. literalinclude:: /../examples/primitives/cxx/nested_types/list.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
   Here we used **header_code_fragment** and **footer_code_fragment** variables to create nested types.

Some usage examples:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/nested_types/main.kt
            :language: kotlin
            :start-after: [nested-types-usage]
            :end-before: [nested-types-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/nested_types/main.py
            :start-after: [nested-types-usage]
            :end-before: [nested-types-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/nested_types/main.swift
            :language: swift
            :start-after: [nested-types-usage]
            :end-before: [nested-types-usage]


.. collapse:: Generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/nested_types/list.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/nested_types/list_pygen.py
               :language: python

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/nested_types/list.swift
               :language: swift

|
