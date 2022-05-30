"Array" tutorial
================

:doc:`"Hello user" </02_first_steps/03_hello_user>` tutorial shows how to annotate source files to tell CppBind what to expose in target languages.
Let's examine the case of using a third-party library. In this case it's impossible to modify source files, so you can't just write
CppBind API annotations inside class/function doxygen style comments. CppBind offers another mechanism for writing annotations in this scenario:
it's possible to write annotations in separate config yaml files.

Let's consider we have an ``Array`` class which is declared in a third party library:

.. literalinclude:: /../examples/tutorials/array/cxx/array.hpp
    :language: cpp

In order to generate bindings, as a first step you need to configure your project. You can use the default configuration
provided by CppBind with running ``cppbind init`` command in your project root directory.

.. collapse:: The content of default config file provided by CppBind

    |

    .. literalinclude:: /../src/cppbind/config/cppbind.yaml
        :language: yaml

|

Above provided default config file can be changed later to fit the requirements of your project. For example,
we can consider the change of **src_glob** variable. It defines the list of the files processed by CppBind.
**src_glob** default value corresponds to all the header files in the project. For this tutorial's case,
we have changed the value of **src_glob** variable in the project config file, since our C++ source file is located under
**cxx** directory: ``src_glob: ["cxx/array.cpp"]``.
More information about CppBind variables can be found :doc:`here </05_detailed_info/03_var_def>`.

.. note::
    When generating bindings on macOS platform for Kotlin, you need **ANDROID_NDK** environment variable to be set.
    It should point to the directory where android NDK is installed. CppBind requires **ANDROID_NDK** environment variable
    to populate the correct clang arguments.

After project configuration is done, you need to annotate your source code with CppBind API annotations.
Third-party library source code annotation should need to be done separately, in a new yaml config file:

.. literalinclude:: /../examples/tutorials/array/cxx/array.cppbind.yaml
    :language: yaml

In the above-mentioned yaml config file you can find API instructions for ``Array`` class.
API instructions are associated with the appropriate entity with the help of C++ signature which are written in front of the **type** key.
Writing instructions in config file has the same effect as writing them in doxygen style comments.
More detailed information about this mechanism can be found here: :ref:`external-api-label`.

To make written API annotations available for CppBind we use project config files merging feature:
**type_vars** sections of project config files can be spread all over the project directories and merged together by CppBind.
By default, CppBind will search for the files with **cppbind.yaml** suffix under project directories, and will merge **type_vars**
sections defined in those files. In our tutorial we have written API annotations for "Array" class in the file named **array.cppbind.yaml**.
To change the name pattern of the project config files, you should modify **context_def_glob** application variable (more details can be found :doc:`here </05_detailed_info/01_app_config>`).

Another way to include API annotations written in a separate file is including the file in the project config
file, under **type_vars** section (the same way as it's done for std_exc_api.yaml file in default config file).

After project configuration is done and annotation config file is written, you should run CppBind command line to generate bindings: ``cppbind koltin swift python``.

.. collapse:: Generated bindings

    |

        .. tab-set::
            .. tab-item:: Kotlin

                .. literalinclude:: /../examples/tutorials/array/kotlin/src/main/java/array/array.kt
                   :language: java

            .. tab-item:: Python

                .. literalinclude:: /../examples/tutorials/array/python/src/array/array.py
                   :language: py

            .. tab-item:: Swift

                .. literalinclude:: /../examples/tutorials/array/swift/src/array/array.swift
                   :language: swift

|

Finally, after generating bindings, you should include them along with C++ source codes in your project build.
In our tutorial we use bazel to build the project.
Bazel setups and rules for "Array" tutorial can be found `here <https://github.com/PicsArt/cppbind/tree/master/examples/tutorials/array>`_.

After project build setup you can write usage examples and run them:

.. tab-set::

    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/tutorials/array/usage/kotlin/array_usage.kt
            :language: java

    .. tab-item:: Python

        .. literalinclude:: /../examples/tutorials/array/usage/python/array_usage.py
            :language: py

    .. tab-item:: Swift

        .. literalinclude:: /../examples/tutorials/array/usage/swift/array_usage.swift
            :language: swift

So, with the help of annotations written in a separate config file, we have achieved our goal: we have exposed several
types and functions from a third-party library to all supported target languages.
