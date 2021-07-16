Nullable Types
^^^^^^^^^^^^^^

Let's take a look at the following example.

.. literalinclude:: /../examples/primitives/cxx/nullables/nullable_utils.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

Iegen uses **nullable_arg** to identify which arguments are nullable. This is a list of argument names.
And for nullable return value uses **nullable_return**, which is a boolean tag.
Let's take a look at the above example. Here we have an overloaded method **max**. The first one has one nullable and one non null argument and it returns nullable value.
And the second one has two nullable arguments and  again returns nullable value.
In the above example you can find also constructor taking nullable argument and getters/setters which are nullable.

.. note::
    For getters/setters make sure that methods marked as **gen_getter** and **gen_setter** both are tagged similarly.
    If the getter is marked with **nullable_return: True** then setter should be marked with **nullable_arg: <arg_name>**.
    In the above example we have `nullable` tagged with gen_getter which returns nullable value
    and `setNullable` tagged with gen_setter having nullable argument.

In this example we use two helper structures `NumberInt` and `NumberDouble`. Note that first one is marked as shared_ref = True,
and the second one as shared_ref = False. Both cases are similar.
Here is the code for them.

.. literalinclude:: /../examples/primitives/cxx/nullables/nullable_utils.hpp
   :language: cpp
   :start-after: [example-helpers]
   :end-before: [example-helpers]

Now let's take a look at generated wrappers.

.. tabs::
    .. tab:: kotlin

        Kotlin has a support for nullable types. As you can see arguments that were marked as nullable have **?** with their data type. The same is for return values.

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/nullables/nullable_utils.kt
           :language: kotlin
           :start-after: [nullables-usage]
           :end-before: [nullables-usage]

    .. tab:: python

        For python nullable arguments and return values are marked as Optional.
        And as for python everything is nullable iegen does additional checks to not allow passing nullable values where non nulls are expected.

        .. literalinclude:: /../examples/primitives/python/src/nullables/nullable_utils_pygen.py
            :language: py
            :start-after: [nullables-usage]
            :end-before: [nullables-usage]

    .. tab:: swift

        Swift is similar to kotlin and has a support for nullable types.
        As you can see arguments that were marked as nullable have **?** with their type. The same is fot return values.

        .. literalinclude:: /../examples/primitives/swift/src/nullables/NullableUtils.swift
           :language: swift
           :start-after: [nullables-usage]
           :end-before: [nullables-usage]

Now let's see some usage examples for generated wrappers.

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/nullables/main.kt
           :language: kotlin

    .. tab:: python

        As you can see here `ValueError` is thrown when None is passed but expected value is not Optional.
        The same is for return values.

        .. literalinclude:: /../examples/primitives/python/src/nullables/main.py
            :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/nullables/main.swift
           :language: swift

