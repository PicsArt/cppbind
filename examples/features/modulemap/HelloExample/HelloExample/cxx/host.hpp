#ifndef host_hpp
#define host_hpp

#include "cxx/user.hpp"

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
        if (!user.want_a_drink) {
            return "Welcome " + user.name + "! Let me know if you want something.";
        }
        return "Welcome " +  user.name + "! Do you want cap of " + (user.age > 21 ? "beer?": "juice?");
    }
};

#endif
