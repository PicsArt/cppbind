Exception handling
^^^^^^^^^^^^^^^^^^
We support exception handling by catching thrown exception objects in the source language and rethrowing them in the target language.
The user must mention the possible thrown exception classes for each method. For this purpose, we have a **throws** variable,
which must contain throwable exceptions. The definition of that list variable looks like this:

.. literalinclude:: /../examples/primitives/cxx/exceptions/exceptions.hpp
    :language: cpp
    :start-after: [throw-example]
    :end-before: [throw-example]

**throws** variable is mandatory for methods, constructors, and functions (also for getters and setters). If a method doesn't throw
an exception, the user must set the parameter value to a special **no_throw** value. It is made as a requirement to ensure
the user hasn't forgotten about the throw ability of the method. An example of an empty exception list looks like this:

.. literalinclude:: /../examples/primitives/cxx/exceptions/exceptions.hpp
    :language: cpp
    :start-after: [no-throw-example]
    :end-before: [no-throw-example]

.. note::
    The order of listed exception classes in the **throws** variable is important. We preserve user-defined orders when catching/rethrowing exceptions.

.. note::
    Swift language doesn't support exception throwing from getter/setter, so the user should set the value of the **throws** variable to **no_throw**.
    CppBind complains about the wrong usage of **throws**.

The exception list can contain standard exception classes and user-defined exception classes with API annotations.
On the target language side, we keep correspondence between those classes, and for this purpose, we also generate standard exceptions
binding to the target language. We define binding rules for std::exception and its descendant classes, and the CppBind tool generates bindings for us. We define rules in the yaml config file, which looks like this:

.. literalinclude:: /../src/cppbind/config/std_exc/std_exc_api.yaml
    :language: yaml
    :end-before: "std::logic_error"

.. note::
    Since we generate try/catch blocks in C bindings for catching an exception, we use C++ std exception classes, and therefore we need to include the
    header files where std exceptions are defined. Those header files are included via the **include_cxx** variable (which you can see in the example above).
    Here are the required includes:

.. code-block:: cpp

    #include <stdexcept>
    #include <new>
    #include <typeinfo>

If a user-defined exception is derived from std::exception, it is automatically throwable in the target language.
If the user wants a class not to be derived from std::exception but to be throwable in the target language,
the **is_exception** variable must be set to True (default value is **False**).

.. note::
    User-defined exception classes must have a copy constructor since we copy the exception object before rethrowing it 
    in the target language. We need this since the original exception object is deleted after its lifetime is ended.

If we catch an exception, not from the user-defined list, we report an unexpected exception and call an uncaught exception handler callback.
We define an exception utility package that includes ``ExceptionHandler`` class to handle uncaught exception cases.
The default handler aborts program execution immediately, but the user can set a custom callback, which
will be called after an unhandled exception is detected. The mentioned package looks like this:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/cppbind/exceptionUtils.kt
            :language: java

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/cppbind/exceptionUtils.swift
            :language: swift

Also, we always catch std::exception before catching all exceptions to have a more informative error message when the exception
class is derived from std::exception.

.. note::
    We use the **pybind** tool to generate Python bindings, which already has support for exception handling.
    Pybind translates C++ standard exceptions to their Python analogs using an exception correspondence `map <https://pybind11.readthedocs.io/en/stable/advanced/exceptions.html#built-in-c-to-python-exception-translation>`_.
    Pybind translates all user-defined exceptions to **RuntimeError** in Python. This support also sets some constraints
    on us, so currently, we don't support Python exceptions as it's done for other languages. The user-defined exceptions list
    is not relevant here, but the user still must define the **throws** variable to the **no_throw** value. This requirement
    keeps API annotations style convenient between all target languages.

After generating bindings for the target language, we can call methods that can throw an exception and test results with catch blocks:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/exceptions/main.kt
            :language: kotlin
            :start-after: [exceptions-usage]
            :end-before: [exceptions-usage]

    .. tab-item:: Swift

        .. literalinclude:: /../examples/primitives/swift/src/exceptions/main.swift
            :language: swift
            :start-after: [exceptions-usage]
            :end-before: [exceptions-usage]

.. note::
    In the last usage example, you can notice that we called the custom exception class method when an exception was caught. When a custom exception class and its methods have API annotations, we have corresponding bindings, and thus we can use class methods.

.. collapse:: Binding codes when "throws" exception list is not empty

    |

    .. tab-set::
            .. tab-item:: Kotlin

                .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/exceptions/throw_exceptions.kt
                    :language: java

            .. tab-item:: Swift

                .. literalinclude:: /../examples/primitives/swift/src/exceptions/throw_exceptions.swift
                    :language: swift

|

.. collapse:: Binding codes when the exception list is empty (throws=True)

    |

    .. tab-set::
        .. tab-item:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/exceptions/no_throw_exceptions.kt
                :language: java

            .. note::
                For Kotlin we rethrow caught exception from C binding via JNI special functions. It means that exception handling section of code is written in C binding file.
                `Here <https://github.com/PicsArt/cppbind/tree/master/examples/primitives/kotlin/wrappers/com/examples/exceptions/throw_exceptions.cpp>`_ is an example of C binding file.

        .. tab-item:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/exceptions/no_throw_exceptions.swift
                :language: swift

|
