## Hello user tutorial.

This is a small Hello user library.

C++ source code is under cxx directory and the generated bindings under kotlin, swift and python directories.

Configuration can be found in **cppbind.yaml** file.

In this example we use bazel for build.

To generate the bindings yourself use the following command:
 ```bash
 cppbind run kotlin swift python
 ```

For CppBind installation and configuration check the documentation [CppBind docs](https://cppbind.io/).

In this example we have a small usage program for each language which creates some users and greets them.
You can find them under usage directory.

To run the program for three languages run the following command:
 ```bash
 bazel run hello_user_swift hello_user_python hello_user_kotlin
 ```
 
Generated Python bindings depend on [pybind11](https://github.com/pybind/pybind11). 
Please note that the use of pybind11 is governed by the corresponding [license](https://github.com/pybind/pybind11/blob/master/LICENSE).
