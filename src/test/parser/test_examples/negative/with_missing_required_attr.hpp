#include <string>

namespace iegen::example {

/**
 * comments
 * __API__
 * gen: class
 * shared_ref: true
 * package: example
 */
struct Item {

    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    Item(const std::string& _value) : value(_value) {}

    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    Item() : value("default value") {}

    /**
     * Error: missing required 'throws' attribute
     * comments
     * __API__
     * gen: method
     *
     */
    std::string result() {
        return value;
    }
        

    /**
     * comments
     *
     * __API__
     * gen: property_setter
     */
    std::string value;
};
}
