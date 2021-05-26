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
     * Error: not allowed 'package' attribute on constructor node
     * comments
     *
     * __API__
     * gen: constructor
     * package: pkg
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
     * comments
     *
     * __API__
     * gen: property_setter
     */
    std::string value;
};
}
