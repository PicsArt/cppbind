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

Special methods
~~~~~~~~~~~~~~~

Many languages have a base class from which other classes are derived. This class contains methods like ``hash``, ``equals``, ``toString``, etc.
For the languages which have this base class, CppBind generates implementations for ``hash``, ``equals``, ``toString``.
This is done to make sure the objects which are wrapping the same C++ instance are equal and have the same value for ``hash`` and ``toString``.

The generated methods are implemented in the following way:

* **hash** - returns the hash value of underlying C++ object address.
* **equals** - returns whether the underlying C++ objects are identical or not.
* **toString** - returns a string containing type and address of the underlying C++ object.

Users can define their own implementations by adding ``hash``, ``equals`` and ``toString`` to C++ classes.
The names of these methods can be configured with **hash_method**, **equals_method** and **tostring_method** variables.
More on variables can be found :doc:`here </05_detailed_info/03_var_def>`.

Let's see an example:

.. literalinclude:: /../examples/primitives/cxx/hashing/objects.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

In the above example the first class: ``Object1``, contains custom definitions for ``hash``, ``equals`` and ``toString`` which means
CppBind generates appropriate methods for all target languages, and if it's required also implements appropriate interfaces. Particularly for Swift the generated class conforms ``Hashable``, ``Equatable`` and ``CustomStringConvertible``.

In case of the second example, i.e. ``Object2``, CppBind generates the default implementations for Kotlin.

For Python CppBind does not generate the default ones, as pybind already does that.
Instead CppBind generates a ``__repr__`` method which returns a string containing C++ object address and type information. This can be used for debugging purposes.
Users can have their own ``__repr__`` by just annotating the appropriate method with ``python.name: __repr__``.

For Swift the default implementations won't be generated, as by default, classes in Swift are neither hashable nor equatable.

.. note::
   It is not allowed to define ``hash``, ``equals`` and ``toString`` for interfaces.
   If they are defined then CppBind raises an error.


.. note::
   If ``hash`` is defined but ``equals`` is not defined then CppBind raises an error for Swift.
   All ``Hashable`` types are also ``Equatable`` in Swift.

Now let's see some usage examples:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/hashing/main.kt
            :language: kotlin
            :start-after: [hashing-usage-example]
            :end-before: [hashing-usage-example]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/hashing/main.py
            :language: py
            :start-after: [hashing-usage-example]
            :end-before: [hashing-usage-example]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/hashing/main.swift
            :language: swift
            :start-after: [hashing-usage-example]
            :end-before: [hashing-usage-example]



.. collapse:: The generated bindings

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/hashing/objects.kt
               :language: java

        .. tab-item:: Python

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/hashing/objects_pygen.py
                :language: py

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/hashing/objects.swift
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
