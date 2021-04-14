.. _Basic example:

A "Hello user" example
======================

It is time to introduce the most basic usage of IEGEN. We have split a small example into sections to discuss each of the concepts with code.

Let's assume you wrote cool library that greeds to its user. And of course you don't want to restrict it only for C++ users. You want to make it available for other language programmes as well. 

Ok here is a your C++ code.


.. _Basic example C++:

.. code-block:: cpp

   #include<string.h>

   /**
    * Structure do describe user.
    */
   struct UserInfo{
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
   class Host{
        /**
         * Greeting function.
         */
        std::string hello(const UserInfo& user){
            return (age > 21 ? "Hello ": "Hi ") + name;
        }
        /**
         * Greeting function.
         */
        std::string welcome(const UserInfo& user){
            return (age > 21 ? "Hello ": "Hi ") + name;
        }
   };

To be able to use it from other languages you need to create binding from that language to you C++ library. IEGEN is a tool which will help you to achieve that just by adding some extra marks to you C++ codes.

In a code above you need to export **UserInfo** structure with *age* and *name* properties and **Host** class with its methods. Do do that you just change your Doxygen comments to include IEGEN instructions and parameters.

.. _Basic example C++ with IEGEN:

.. code-block:: cpp

   #include<string.h>

   /**
    * Structure do describe user.
    * __API__
    * gen: class
    */
   struct UserInfo{

        /**
         * Creates user
         *
         * __API__
         * gen: constructor
         */
        UserInfo(const std::string& user_name, unsigned int user_age):name(user_name), age(user_age){}
        /**
         * Age of user.
         *
         * __API__
         * gen: property_getter
         */
        unsigned int age = 0;
        /**
         * Name of user.
         *
         * __API__
         * gen: property_getter
         */
        std::string name;
        /**
         * Some wishes of the user.
         * __API__
         * gen: property_setter
         */
        bool want_a_drink = false;
   };

   /**
    * Host class.
    * __API__
    * gen: class
    */
   class Host{
        /**
         * Creates host
         *
         * __API__
         * gen: constructor
         */
        Host() = default;
        /**
         * Greeting function.
         * gen: method
         */
        std::string hello(const UserInfo& user){
            return (age > 21 ? "Hello ": "Hi ") + name;
        }
        /**
         * Greeting function.
         * gen: method
         */
        std::string welcome(const UserInfo& user){
            if(!user.want_a_drink)
                return "Welcome " + name + "! Let me know if you want something";
            //else
            return "Welcome " + name + "! Do you want cap of " + (age > 21 ? "beer?": "juice?");
        }
   };

That is it. Now you should be able to use it on your codes written in supported languages. Here is a usage example of Swift.
 
.. _Basic example usage with swift:

.. code-block:: swift 

    import Wrapper
    let user = UserInfo(name: "Jhon", age: 22)
    let young_user = UserInfo(name: "Kate", age: 18)

    let host = Host()

    assert(host.hello(user)  == "abc")
    assert(host.hello(young_user)  == "abc")

    assert(host.welcome(user)  == "abc")
    assert(host.welcome(young_user)  == "abc")

    user.want_a_drink = true
    young_user.want_a_drink = true

    assert(host.welcome(user)  == "abc")
    assert(host.welcome(young_user)  == "abc")

To find out how to configure IEGEN and run on you code and how to create binding library for your target language please read following topics.

* :doc:`Configuration </02_get_started/03_configuration>`
* :doc:`Creating  binding library.</02_get_started/03_configuration>`

