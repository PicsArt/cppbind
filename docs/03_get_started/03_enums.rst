Enums
^^^^^

Now let's generate a binding for an enum. Here is the ``Color`` enum definition:

.. literalinclude:: /../examples/primitives/cxx/enums/color.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

As shown in the above example, we can extend enums logic by using the **code_fragment** variable.
Code fragments defined with this variable are appended to the enum definition.
In this example, we added the custom conversion from enum to string for all three languages.
Notice that for Swift, we have also used the **bases_list** variable to make the enum implement the ``CustomStringConvertible`` protocol.

We can also customize enum case field names using the **enum_case_name_prefix** variable, which can be used to add a user-defined prefix string to enum field names in the target language.
In order to change the original case names completely, we can use **enum_case_names** variable which is a dictionary of mappings between
the original and target case names. Here is an example of the **enum_case_names** variable usage:

.. literalinclude:: /../examples/primitives/cxx/enums/logging.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

In cases some of the original enum fields are for internal usage,
and the user doesn't want to expose them in target language bindings, the **enum_excluded_cases** variable can be used to specify
the list of excluded fields. If those fields are used as a default value for a function/constructor argument, CppBind skips
that default value generation in target language bindings. If the user has a function that returns an excluded enum field,
CppBind terminates the main program during the function call and provides the user with an appropriate error message.

And the Frame struct using **Color** enum:

.. literalinclude:: /../examples/primitives/cxx/enums/frame.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
    We are generating **property_setter** for public field ``backgroundColor``.
    A writable property field corresponds to it in the target language. To generate a read-only field, we should use **property_getter** instead.

Usage examples:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/main.kt
           :language: kotlin
           :start-after: [color-usage]
           :end-before: [color-usage]

    .. tab-item:: Python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/enums/main.py
           :language: py
           :start-after: [color-usage]
           :end-before: [color-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/enums/main.swift
           :language: swift
           :start-after: [color-usage]
           :end-before: [color-usage]

.. collapse:: Generated codes for Color and Frame

    |

    .. tab-set::
        .. tab-item:: Kotlin

            Here is the generated Kotlin code for Color:

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/color.kt
               :language: java

            And for Frame:

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/frame.kt
               :language: java


        .. tab-item:: Python

            Here is the generated Python code for Color:

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/enums/color_pygen.py
               :language: py

            And for Frame:

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/enums/frame_pygen.py
               :language: py

        .. tab-item:: Swift

            Here is the generated Swift code for Color:

            .. literalinclude:: /../examples/primitives/swift/src/enums/color.swift
               :language: swift

            And for Frame:

            .. literalinclude:: /../examples/primitives/swift/src/enums/frame.swift
               :language: swift

|
