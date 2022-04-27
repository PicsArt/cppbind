.. _Basic example:

"Hello user" example
====================

It is time to introduce the most basic usage of IEGEN. Let’s assume you wrote a cool library that greets to its user.
And of course, you don’t want to restrict it only to C++ users.
You want to make it available for other language programs as well.

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

To be able to use this from other languages, you need to create a binding from your C++ library to that language.
IEGEN is a tool that will help you to achieve that just by adding some extra marks to your C++ codes.

In the code above, you need to export **UserInfo** structure with *age* and *name* properties and **Host** class with its methods.
To do that, you just need to change your Doxygen comments to include IEGEN instructions and parameters.

.. _Basic example C++ with IEGEN:


.. literalinclude:: /../examples/tutorials/hello_user/cxx/hello_user.hpp
   :language: cpp 
   :emphasize-lines: 5-7, 13-15, 20-21, 26-27, 32-33, 40-42, 48-50, 55-57, 64-66

Basically, we have just added *__API__* tag to let IEGEN know what entity needs to be processed
and added the instruction *action: gen_method* which tells that a method needs to be generated. For the full list of available instructions see :doc:`Generation instructions </05_detailed_info/04_gen_actions>`.

You can notice the usage of **throws** variable in API comments. IEGEN has some required variables on some entities. In this case we have set
mandatory `throws` variable on all methods/constructors. This requirement is done to assure that user hasn't forgotten to mention about possible exceptions that entity can throw.
More details can be found here: :doc:`Exception handling </03_get_started/05_exception_handling>`.

That is it. Now you should be able to use it on your codes written in supported languages. Here are usage examples for kotlin, python and swift.

.. _Basic example usage with swift:

.. tabs::
    .. tab:: kotlin

        .. literalinclude:: /../examples/tutorials/hello_user/usage/kotlin/hello_user_usage.kt
           :language: java

    .. tab:: python

        .. literalinclude:: /../examples/tutorials/hello_user/usage/python/hello_user_usage.py
           :language: py

    .. tab:: swift

        .. literalinclude:: /../examples/tutorials/hello_user/usage/swift/hello_user_usage.swift
           :language: swift

What has been described above is what you are going to do for all the new classes and functions you would like to expose to other languages.
Beside that you will need to configure IEGEN project file once to be able to use the tool.
To know more about IEGEN configuration please continue reading.

IEGEN setup
^^^^^^^^^^^

To run IEGEN you need to have a config file for your project. Config file should include some rules and definitions of minimal required parameters.
IEGEN provides a command line utility to generate default config file for your project.
You should run **iegen init** in the project root directory to create default project config file.

.. collapse:: The content of default config file provided by IEGEN

    |

    .. literalinclude:: /../src/iegen/config/iegen.yaml
        :language: yaml

|

Above provided default config file can be changed later to fit the requirements of your project. For example the default value for **src_glob** variable
is a list with the file glob pattern corresponding to all the header files in the project. This can be modified to control the list of the files processed by IEGEN.
There are also some other variables (`cxx_out_dir`, `out_dir`, etc.) which need to be modified to control the place where the generated bindings will be placed.
You can find the whole list of IEGEN variables here: :doc:`Variable Definitions </05_detailed_info/03_var_def>`.

.. note::
    From the default config file you can notice the usage of `get_android_ndk_sysroot` helper function when defining `clang_args` variable
    for kotlin target language for macOS platform. `ANDROID_NDK` environment variable must be correctly set since it is used by `get_android_ndk_sysroot` function.

.. collapse:: The content of "Hello user" project config file

    |

    .. literalinclude:: /../examples/tutorials/hello_user/cxx/iegen.yaml
        :language: yaml

|

After generating bindings you should include them along with C++ source codes in your project build.
In our tutorial example we use bazel to build the project.

Bazel setups and rules for "Hello user" example can be found here: `Hello User <https://github.com/PicsArt/iegen/tree/master/examples/tutorials/hello_user>`_.
