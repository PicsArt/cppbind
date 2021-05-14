#ifndef overload_hpp
#define overload_hpp
#include <string>
namespace iegen::example {
/**
 * An example for with overloaded methods.
 * __API__
 * gen: class
 * shared_ref: true
 * package: overloads
 */
struct OverloadedFunctions {

    /**
     * Overload constructor
     *
     * __API__
     * gen: constructor
     */
    OverloadedFunctions() {}

    /**
     * Concatenate with two strings.
     *
     * __API__
     * gen: method
     * throws: no_throw
     */
    std::string concatenate(std::string first, std::string second) {
        return first + second;
    }

    /**
     * Concatenate with three strings.
     *
     * __API__
     * gen: method
     * throws: no_throw
     */
    std::string concatenate(std::string first, std::string second, std::string third) {
        return first + second + third;
    }
};
}
#endif