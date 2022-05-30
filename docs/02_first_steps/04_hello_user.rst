.. _Basic example:

"Hello user" tutorial
=====================

It is time to introduce the most basic usage of CppBind. Let's assume you wrote a fantastic library that greets its user. And, of course, you don't want to restrict it only to C++ users. You want to make it available for other language programs as well.

Okay, here is your C++ code:


.. _Basic example C++:

.. code-block:: cpp

    #include <string>

    /**
     * Structure to describe user.
     */
    struct UserInfo {

        /**
         * Creates user
         */
        UserInfo(const std::string& user_name, unsigned int user_age) : age(user_age), name(user_name) {}
        /**
         * Age of user.
         */
        unsigned int age = 0;
        /**
         * Name of user.
         */
        std::string name;
        /**
         * Some wishes of the user.
         */
        bool want_a_drink = false;
    };

    /**
     * Host class.
     */
    class Host {
    public:
        /**
         * Creates host
         */
        Host() = default;
        /**
         * Greeting function.
         */
        std::string hello(const UserInfo& user) {
            return (user.age > 21 ? "Hello ": "Hi ") + user.name;
        }
        /**
         * Welcome function.
         */
        std::string welcome(const UserInfo& user) {
            if (!user.want_a_drink)
                return "Welcome " + user.name + "! Let me know if you want something.";
            return "Welcome " + user.name + "! Do you want cap of " + (user.age > 21 ? "beer?": "juice?");
        }
    };
    
To use this from other languages, you need to create a binding from your C++ library to that language. CppBind is a tool that helps you achieve that by adding some extra marks to your C++ codes.

In the code above, you need to export the ``UserInfo`` structure with ``age`` and ``name`` properties and the ``Host`` class with its methods.
To do that, you need to change your doxygen style comments to include CppBind instructions and parameters.
.. _Basic example C++ with CppBind:


.. literalinclude:: /../examples/tutorials/hello_user/cxx/hello_user.hpp
   :language: cpp 
   :emphasize-lines: 5-7, 13-15, 20-21, 26-27, 32-33, 40-42, 48-50, 55-57, 64-66

We have just added the **__API__** tag to let CppBind know what entity needs to be processed
and added the instruction **action: gen_method**, which tells that a method needs to be generated. For the complete list of available instructions, see
:doc:`Generation instructions </05_detailed_info/04_gen_actions>`.

You can notice the usage of the **throws** variable in API comments. CppBind has required variables on some entities. In this case, we have set a mandatory **throws** variable on all methods/constructors. This requirement is done to ensure that the user hasn't forgotten to mention possible exceptions that the entity can throw. More details can be found :doc:`here </03_get_started/05_exception_handling>`.
That is it. You should be able to use it on your codes written in supported languages. Here are usage examples for Kotlin, Python, and Swift.

.. _Basic example usage with Swift:

.. tab-set::
    .. tab-item:: Kotlin

        .. literalinclude:: /../examples/tutorials/hello_user/usage/kotlin/hello_user_usage.kt
           :language: java

    .. tab-item:: Python

        .. literalinclude:: /../examples/tutorials/hello_user/usage/python/hello_user_usage.py
           :language: py

    .. tab-item:: Swift

        .. literalinclude:: /../examples/tutorials/hello_user/usage/swift/hello_user_usage.swift
           :language: swift

The above-described steps are applicable for all the new classes and functions you want to expose to other languages. Besides that, you need to configure the CppBind project file once to use the tool. To know more about the CppBind configuration, continue reading.

"Hello user" CppBind configuration
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To run CppBind, you need to have a config file for your project. The config file should include rules and definitions of minimal required parameters. CppBind provides a command-line utility to generate a default config file for your project. Run **cppbind init** in the project root directory to create the default project config file.

.. collapse:: The content of the default config file provided by CppBind

    |

    .. literalinclude:: /../src/cppbind/config/cppbind.yaml
        :language: yaml

|

The above-provided default config file can be changed later to fit the requirements of your project. For example, the default value the **src_glob** variable is a list with the file glob pattern corresponding to all the header files in the project. This can be modified to control the list of the files processed by CppBind. Some other variables (**cxx_out_dir**, **out_dir**, etc.) need to be adjusted to control the place where the generated bindings will be placed. 
You can find the whole list of CppBind variables :doc:`here </05_detailed_info/03_var_def>`.

.. note::
    When generating bindings on macOS platform for Kotlin, you need **ANDROID_NDK** environment variable to be set.
    It should point to the directory where android NDK is installed. CppBind requires **ANDROID_NDK** environment variable
    to populate the correct clang arguments.

.. collapse:: The content of "Hello user" project config file

    |

    .. literalinclude:: /../examples/tutorials/hello_user/cxx/cppbind.yaml
        :language: yaml

|

After generating bindings, you should include them with C++ source codes in your project build. In our tutorial, we use Bazel to build the project.

Bazel setups and rules for the "Hello user" tutorial can be found `here <https://github.com/PicsArt/cppbind/tree/master/examples/tutorials/hello_user>`_.
