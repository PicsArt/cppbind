Static and overloaded methods
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Let's now bind a struct with static and overloaded methods:

.. literalinclude:: /../examples/primitives/cxx/overloads/utils.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]


As you can see overloaded or static methods are like regular methods. There's nothing special to add in the **API** for them.

Here is the wrapper code:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/utils.kt
           :language: kotlin

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/overloads/utils_pygen.py
           :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/overloads/Utils.swift
           :language: swift

.. note::
    Python does not have method overloading, but here with bind decorator we have overloaded sum and concatenate methods.
    Sum is also a classmethod as it was static in original code.


We are ready to use it:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/overloads/main.kt
           :language: kotlin
           :start-after: [overload-usage]
           :end-before: [overload-usage]

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/overloads/main.py
           :language: py
           :start-after: [overload-usage]
           :end-before: [overload-usage]

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/overloads/main.swift
           :language: swift
           :start-after: [overload-usage]
           :end-before: [overload-usage]

Global functions
^^^^^^^^^^^^^^^^

Now let's see how global functions should be bind.
Here are some global function c++ examples:

.. literalinclude:: /../examples/primitives/cxx/globs/utils.hpp
   :language: cpp
   :start-after: [example]
   :end-before: [example]

.. note::
    To generate bindings for global functions ``gen_function`` action is used.

Here we have an overloaded example(`concat`), template examples(`max` and `makePair`) etc.

Now let's go through the generated bindings.


.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/globs/utils.kt
           :language: kotlin

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/globs/utils_pygen.py
           :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/globs/GlobUtils.swift
           :language: swift


Here we have overloaded ``concat`` for kotlin and swift but for python it's slightly different
as there's no overloading for python. We have two methods ``concat`` and ``concat1`` in python.
Similarly for template function we have an overloaded function for each template combination for kotlin and swift.
In case of python a postfix generated from argument types is appended to the function name.

Now let's see some usage examples:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/globs/main.kt
           :language: kotlin
           :start-after: [glob-func-examples]
           :end-before: [glob-func-examples]

    .. tab:: python

        .. literalinclude:: /../examples/primitives/python/src/examples_lib/globs/main.py
           :language: py
           :start-after: [glob-func-examples]
           :end-before: [glob-func-examples]

    .. tab:: swift

        .. literalinclude:: /../examples/primitives/swift/src/globs/main.swift
           :language: swift
           :start-after: [glob-func-examples]
           :end-before: [glob-func-examples]
