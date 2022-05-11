#ifndef overload_hpp
#define overload_hpp
#include <string>

namespace iegen::example {
/**
 * An example with overloaded methods.
 * __API__
 * action: gen_class
 * shared_ref: true
 * swift.file: Utils
 * package: overloads
 */
struct Utils {
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Utils() {};

    // [overload-example]
    /**
     * Sum two ints.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static int sum(int first, int second) {
        return first + second;
    }

    /**
     * Sum two floats.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static float sum(float first, float second) {
        return first + second;
    }

    /**
     * Concatenate with two strings.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string concatenate(std::string first, std::string second) {
        return first + second;
    }

    /**
     * Concatenate with three strings.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string concatenate(std::string first, std::string second, std::string third) {
        return first + second + third;
    }
    // [overload-example]

    // [static-example]
     /**
     * Sub two ints.
     * __API__
     * action: gen_method
     * name: minus
     * throws: no_throw
     */
    static int sub(int first, int second) {
        return first - second;
    }

    /**
     * Sub two floats.
     * __API__
     * action: gen_method
     * name: minus
     * throws: no_throw
     */
    static float sub(float first, float second) {
        return first - second;
    }
    // [static-example]
};
}
#endif