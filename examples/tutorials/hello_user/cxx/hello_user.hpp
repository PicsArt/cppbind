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

/**
 * Host class.
 * __API__
 * action: gen_class
 * package: hello
 */
class Host {
public:
    /**
     * Creates host
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Host() = default;
    /**
     * Greeting function.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string hello(const UserInfo& user) {
        return (user.age > 21 ? "Hello ": "Hi ") + user.name;
    }
    /**
     * Welcome function.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string welcome(const UserInfo& user) {
        if (!user.want_a_drink)
            return "Welcome " + user.name + "! Let me know if you want something.";
        return "Welcome " +  user.name + "! Do you want cap of " + (user.age > 21 ? "beer?": "juice?");
    }
};

