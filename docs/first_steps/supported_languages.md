# Supported languages

Currently CppBind supports bindings generation for the following
languages:

-   Kotlin
-   Swift
-   Python

## Kotlin

In order to expose C++ types and functions to Kotlin CppBind uses JNI
framework which enables Java/Kotlin code running in JVM to call a native
program. CppBind generates Kotlin API code which is bridged with
original C++ code via generated JNI bindings.

## Swift

Swift language gives an opportunity to access and use pieces of code
written in C. CppBind uses Swift and C interoperability to create a
bridge between Swift and C++ codes. The connection is created via
generated C and Swift bindings.

## Python

To connect Python and C++ code CppBind generates
[pybind](https://github.com/pybind/pybind11) code. CppBind also
generates Python API which is a wrapper for pybind codes.

!!! Note
    Using pybind as an intermediate layer between C++ and Python brings some
    limitations to CppBind. For example, pybind has a support for exceptions
    which allows CppBind to transfer custom exceptions from C++ to Python
    only as RuntimeError, thus losing the reference to the original
    exception type. Currently this limitation exists only for Python. More
    detailed information is available [here](../main_features/exception_handling.md).

    Besides the limitations pybind gives us opportunity to support some more
    features for Python. For example, currently we have a support for
    callbacks only for Python, but the similar feature is going to be
    developed for other languages as well.

!!! Note
    Since CppBind generates Python API upon generated pybind bindings, we
    are able to add some logic before calling original pybind codes. For
    example, CppBind does some validations for nullable arguments, does
    implicit casts between provided and expected argument types if possible.
    CppBind generates type hints which gives opportunity to navigate through
    the code inside IDE tools.
