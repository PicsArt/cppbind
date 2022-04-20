.. _Basic example:

A "Hello user" example
======================

It is time to introduce the most basic usage of IEGEN. We have split a small example into sections to discuss each of the concepts with code.

Let’s assume you wrote a cool library that greets to its user. And of course, you don’t want to restrict it only to C++ users.
You want to make it available for other language programs as well.

Okay here is your C++ code.


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

To be able to use it from other languages, you need to create a binding from your C++ library to that language.
IEGEN is a tool that will help you to achieve that just by adding some extra marks to your C++ codes.

In the code above, you need to export **UserInfo** structure with *age* and *name* properties and **Host** class with its methods.
To do that, you just need to change your Doxygen comments to include IEGEN instructions and parameters.

.. _Basic example C++ with IEGEN:


.. literalinclude:: /../examples/tutorials/hello_user/cxx/hello_user.hpp
   :language: cpp 
   :emphasize-lines: 5-7, 13-15, 20-21, 26-27, 32-33, 40-42, 48-50, 55-57, 64-66

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

Basically, what we have done here we have added *__API__* tag to let IEGEN know that structure needs to be processed
and added the instruction for example *action: gen_method* which tells that method needs to be generated.

The example using bazel for build is available at `Hello User <https://github.com/PicsArt/iegen/tree/hello-tutorial/examples/tutorials/hello_user>`_.

To find out how to configure IEGEN and run on your code and how to create a binding library for your target language, please read the following topics.

* :doc:`API Attributes </02_first_steps/06_api_configuration>`
* :doc:`Configuration for "Hello user" </02_first_steps/hello_user_configuration>`

