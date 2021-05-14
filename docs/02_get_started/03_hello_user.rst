.. _Basic example:

A "Hello user" example
======================

It is time to introduce the most basic usage of IEGEN. We have split a small example into sections to discuss each of the concepts with code.

Let's assume you wrote cool library that greets to it's user. And of course you don't want to restrict it only for C++ users.
You want to make it available for other language programmes as well.

Ok here is your C++ code.


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

To be able to use it from other languages you need to create binding from your C++ library to that language.
IEGEN is a tool which will help you to achieve that just by adding some extra marks to you C++ codes.

In a code above you need to export **UserInfo** structure with *age* and *name* properties and **Host** class with its methods.
To do that you just need to change your Doxygen comments to include IEGEN instructions and parameters.

.. _Basic example C++ with IEGEN:


.. literalinclude:: /../examples/tutorials/hello_user/cxx/hello_user.hpp
   :language: cpp 
   :emphasize-lines: 5-8, 14-15, 20-21, 26-27, 32-33, 40-43, 49-50, 55-56, 63-64

That is it. Now you should be able to use it on your codes written in supported languages. Here is a usage example of Swift.
 
.. _Basic example usage with swift:

.. literalinclude:: /../examples/tutorials/hello_user/usage/swift/hello_user_usage.swift
   :language: swift 

Basically what we have done here we have added *__API__* tag to let IEGEN know that structure needs to be processed
and added the instruction for example *gen: method* which tells that method needs to be generated.

To find out how to configure IEGEN and run on your code and how to create binding library for your target language please read the following topics.

* :doc:`API Attributes </02_get_started/05_api_configuration>`
* :doc:`Configuration for "Hello user" </02_get_started/hello_user_configuration>`

