#ifndef user_hpp
#define user_hpp

#include <string>

/**
 * Structure to describe user.
 * __API__
 * action: gen_class
 * package: hello
 */
struct UserInfo {

    /**
     * Creates user
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    UserInfo(const std::string& user_name, unsigned int user_age) : age(user_age), name(user_name) {}
    /**
     * Age of user.
     * __API__
     * action: gen_property_getter
     */
    unsigned int age = 0;
    /**
     * Name of user.
     * __API__
     * action: gen_property_getter
     */
    std::string name;
    /**
     * Some wishes of the user.
     * __API__
     * action: gen_property_setter
     */
    bool want_a_drink = false;
};

#endif
