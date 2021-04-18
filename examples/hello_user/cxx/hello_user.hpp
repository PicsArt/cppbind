
#include<string.h>

/**
 * Structure to describe user.
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
     * __API__
     * gen: method
     */
    std::string hello(const UserInfo& user){
        return (age > 21 ? "Hello ": "Hi ") + name;
    }
    /**
     * Welcome function.
     * __API__
     * gen: method
     */
    std::string welcome(const UserInfo& user){
        if(!user.want_a_drink)
            return "Welcome " + name + "! Let me know if you want something.";
        //else
        return "Welcome " + name + "! Do you want cap of " + (age > 21 ? "beer?": "juice?");
    }
};
