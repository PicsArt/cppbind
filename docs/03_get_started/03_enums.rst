Enums
^^^^^

Now let's generate a binding for an enum.
Here is Color enum definition:

.. literalinclude:: /../examples/primitives/cxx/enums/color.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

As we can see in the above example we can extend enums logic by using **code_fragment** variable.
Code fragments defined with this variable are appended to the enum definition.
Particularly in this example we added custom conversion from enum to string for all tree languages.
Notice that for swift we have also used **bases_list** variable to make the enum implement `CustomStringConvertible` protocol.
We also can customize enum case field names using **enum_field_name_prefix** variable, which can be used to add a user defined
prefix string to enum field names in target language.

If there are cases when some of original enum fields are for internal usage
and user doesn't want to expose them in target language bindings, then **enum_excluded_fields** variable can be used to specify
the list of excluded fields. In case those fields are used as a default value for a function/constructor argument, iegen will
skip that default value generation in target language bindings. If user has a function which returns an excluded enum field,
iegen terminates the main program during the function call and provides the user with an appropriate error message (except of python,
since currently pybind sets some constraints on iegen).

And the Frame struct using it:

.. literalinclude:: /../examples/primitives/cxx/enums/frame.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
    We are generating **property_setter** for public field **backgroundColor**.
    A writable property field will correspond to it in the target language. To generate read-only field we should use **property_getter** instead.

Usage examples:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/main.kt
           :language: kotlin
           :start-after: [color-usage]
           :end-before: [color-usage]

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/enums/main.py
           :language: py
           :start-after: [color-usage]
           :end-before: [color-usage]

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/enums/main.swift
           :language: swift
           :start-after: [color-usage]
           :end-before: [color-usage]

.. collapse:: Generated codes for Color and Frame

    |

    .. tabs::
        .. tab:: kotlin

            Here is the generated kotlin code for Color:

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/color.kt
               :language: java

            And for Frame:

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/enums/frame.kt
               :language: java


        .. tab:: python

            Here is the generated python code for Color:

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/enums/color_pygen.py
               :language: py

            And for Frame:

            .. literalinclude:: /../examples/primitives/python/src/examples_lib/enums/frame_pygen.py
               :language: py

        .. tab:: swift

            Here is the generated swift code for Color:

            .. literalinclude:: /../examples/primitives/swift/src/enums/color.swift
               :language: swift

            And for Frame:

            .. literalinclude:: /../examples/primitives/swift/src/enums/frame.swift
               :language: swift
|
