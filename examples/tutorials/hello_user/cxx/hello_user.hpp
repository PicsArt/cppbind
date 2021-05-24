#include <string>

/**
 * Structure to describe user.
 * __API__
 * gen: class
 * package: hello
 * swift.include: CWrapper
 */
struct UserInfo {

    /**
     * Creates user
     * __API__
     * gen: constructor
     */
    UserInfo(const std::string& user_name, unsigned int user_age) : age(user_age), name(user_name) {}
    /**
     * Age of user.
     * __API__
     * gen: property_getter
     */
    unsigned int age = 0;
    /**
     * Name of user.
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
 * package: hello
 * swift.include: CWrapper
 */
class Host {
public:
    /**
     * Creates host
     * __API__
     * gen: constructor
     */
    Host() = default;
    /**
     * Greeting function.
     * __API__
     * gen: method
     * throws: no_throw
     */
    std::string hello(const UserInfo& user) {
        return (user.age > 21 ? "Hello ": "Hi ") + user.name;
    }
    /**
     * Welcome function.
     * __API__
     * gen: method
     * throws: no_throw
     */
    std::string welcome(const UserInfo& user) {
        if (!user.want_a_drink)
            return "Welcome " + user.name + "! Let me know if you want something.";
        return "Welcome " +  user.name + "! Do you want cap of " + (user.age > 21 ? "beer?": "juice?");
    }
};

