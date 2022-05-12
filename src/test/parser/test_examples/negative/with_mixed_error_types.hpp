#include <string>

namespace cppbind::example {

/**
 * comments
 * __API__
 * action: gen_class
 * shared_ref: true
 * package: example
 */
struct Item1 {

    /**
     * Error: not allowed 'package' attribute on constructor node
     * comments
     *
     * __API__
     * action: gen_constructor
     * throws: no_throw
     * package: pkg
     */
    Item(const std::string& _value) : value(_value) {}

    /**
     * comments
     *
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Item() : value("default value") {}

    /**
     * Error: missing required 'throws' attribute
     * comments
     * __API__
     * action: gen_method
     *
     */
    std::string result() {
        return value;
    }
        

    /**
     * comments
     *
     * __API__
     * action: gen_property_setter
     */
    std::string value;
};
}

