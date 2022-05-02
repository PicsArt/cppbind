Exception handling
^^^^^^^^^^^^^^^^^^

We support exception handling by catching thrown exception object in source language and rethrowing it in target language.
User has to mention the list of possible thrown exception classes for each method. For this purpose we have **throws** variable,
which must contain throwable exceptions. The definition of that list variable looks like:

.. literalinclude:: /../examples/primitives/cxx/exceptions/exceptions.hpp
    :language: cpp
    :start-after: [throw-example]
    :end-before: [throw-example]

**throws** variable is mandatory for methods, constructors and functions (also for getters and setters). If a method doesn't throw
any exception, user must set the value of parameter to special **no_throw** value. This is made as a requirement to ensure
that the user hasn't forgotten about throw ability of method. The example of empty exception list looks like:

.. literalinclude:: /../examples/primitives/cxx/exceptions/exceptions.hpp
    :language: cpp
    :start-after: [no-throw-example]
    :end-before: [no-throw-example]

.. note::
    The order of listed exception classes in *throws* variable is important. We preserve user defined order when catching/rethrowing
    exceptions.

.. note::
    Swift language doesn't support exception throwing from getter/setter, so user should set the value of **throws** variable to **no_throw**.
    IEGEN will complain about wrong usages of **throws**.

Exception list can contain standard exception classes and also user defined exception classes which have API annotations.
In target language side we keep correspondence between those classes, and for this purpose we generate also standard exceptions
binding for target language. We define binding rules for std::exception and its descendant classes, and IEGEN tool generates bindings for us.
We define rules in yaml config file, which looks like:

.. literalinclude:: /../src/iegen/config/std_exc/std_exc_api.yaml
    :language: yaml
    :end-before: "std::logic_error"

.. note::
    Since we generate try/catch blocks in C bindings for catching an exception, we use C++ std exception classes and therefore we need to include
    the header files where std exceptions are defined. Those header files are included via **include_cxx** variable (which you can see in above-mentioned example).
    Here are the required includes:

.. code-block:: cpp

    #include <stdexcept>
    #include <new>
    #include <typeinfo>

If user defined exception is derived from std::exception then it is automatically throwable in the target language.
In case user wants a class not to be derived from std::exception, but to be throwable in the target language,
**is_exception** variable must be set to **True** (default value is **False**).

.. note::
    User defined exception classes must have copy constructor, since we copy exception object before rethrowing it in
    target language. We need this since original exception object is being deleted after its lifetime is ended.

In case we catch an exception not from user defined list, we report unexpected exception and call uncaught exception handler callback.
We define exception utility package which includes ``ExceptionHandler`` class to handle uncaught exception case.
Default handler aborts program execution immediately, but user can set custom callback, which
will be called after unhandled exception is detected. The mentioned package looks like:

    .. tabs::
        .. tab:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/iegen/exceptionUtils.kt
                :language: java

        .. tab:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/iegen/exceptionUtils.swift
                :language: swift

Also we always catch std::exception before catching all exceptions to have more informative error message when exception
class is derived from std::exception.

.. note::
    For generating Python bindings we use **pybind** tool, which already has support for exception handling.
    Pybind translates C++ standard exceptions to their Python analogs using exception correspondence `map <https://pybind11.readthedocs.io/en/stable/advanced/exceptions.html#built-in-c-to-python-exception-translation>`_.
    Pybind translates all user defined exceptions to **RuntimeError** in Python. This support also sets some constraints
    on us, so currently we don't support Python exceptions as it's done for other languages. It means user defined exceptions list
    is not relevant here, but user still has to define **throws** variable to **no_throw** value. This requirement
    keeps API annotations style convenient between all target languages.

After generating bindings for target language we can call methods which can throw an exception, and test results with catch blocks:

.. tabs::
        .. tab:: Kotlin

            .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/exceptions/main.kt
                :language: kotlin
                :start-after: [exceptions-usage]
                :end-before: [exceptions-usage]

        .. tab:: Swift

            .. literalinclude:: /../examples/primitives/swift/src/exceptions/main.swift
                :language: swift
                :start-after: [exceptions-usage]
                :end-before: [exceptions-usage]

.. note::
    In the last usage example you can notice that we called custom exception class method when an exception was caught. When custom exception class and its methods have API annotations,
    we have corresponding bindings and thus we can use class methods.

.. collapse:: Binding codes when "throws" exception list is not empty

    |

    .. tabs::
            .. tab:: Kotlin

                .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/exceptions/throw_exceptions.kt
                    :language: java

            .. tab:: Swift

                .. literalinclude:: /../examples/primitives/swift/src/exceptions/throw_exceptions.swift
                    :language: swift

|

.. collapse:: Binding codes when exception list is empty (throws=True)

    |

    .. tabs::
            .. tab:: Kotlin

                .. literalinclude:: /../examples/primitives/kotlin/src/main/java/com/examples/exceptions/no_throw_exceptions.kt
                    :language: java

                .. note::
                    For Kotlin we rethrow caught exception from C binding via JNI special functions. It means that exception handling section of code is written in C binding file.
                    `Here <https://github.com/PicsArt/iegen/tree/master/examples/primitives/kotlin/wrappers/com/examples/exceptions/throw_exceptions.cpp>`_ is an example of C binding file.

            .. tab:: Swift

                .. literalinclude:: /../examples/primitives/swift/src/exceptions/no_throw_exceptions.swift
                    :language: swift

|
