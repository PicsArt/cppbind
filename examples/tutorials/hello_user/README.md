## Hello user tutorial.

This is a small Hello user library.

Here we have a c++ source code(under cxx directory) and generated bindings for swift, kotlin and python.

You can find generated bindings under kotlin, swift and python directories.
This is configured in **cxx/cppbind.yaml** file.

In this example we use bazel for build.

To generate the wrappers yourself use the following command:
 ```bash
 cppbind run kotlin swift python
 ```

For CppBind installation and configuration check the documentation [CppBind docs](https://iegen.picsart.com).

In this example we have a small usage program for each language which creates some users and greets them.
You can find them under usage directory.

To run the program for three languages run the following command:
 ```bash
 bazel run hello_user_swift hello_user_python hello_user_kotlin
 ```
 
CppBind-generated Python bindings are being binded to Python application with help of [pybind](https://github.com/pybind/pybind11). 
Please note that the use of PyBind is governed by the corresponding [license](https://github.com/pybind/pybind11/blob/master/LICENSE).
