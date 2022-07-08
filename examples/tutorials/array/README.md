## Array tutorial.

This is a small Array library.

Here we have a c++ source code(under cxx directory) and generated bindings for swift, kotlin and python.

You can find generated bindings under kotlin, swift and python directories.
This is configured in **cppbind.yaml** file.

In this example we use bazel for build.

To generate the wrappers yourself use the following command:
 ```bash
 cppbind run kotlin swift python
 ```

For CppBind installation and configuration check the documentation [CppBind docs](https://cppbind.io/).

In this example we have a small usage program for each language which creates an array and uses it.

To run the program for three languages run the following command:
 ```bash
 bazel run array_swift
 bazel run array_python
 bazel run array_kotlin
 ```
 
CppBind-generated Python bindings are being binded to Python application with help of [pybind](https://github.com/pybind/pybind11). 
Please note that the use of PyBind is governed by the corresponding [license](https://github.com/pybind/pybind11/blob/master/LICENSE).
