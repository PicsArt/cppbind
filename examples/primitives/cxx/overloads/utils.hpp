#ifndef overload_hpp
#define overload_hpp
#include <string>

namespace iegen::example {
// [example]
/**
 * An example with overloaded methods.
 * __API__
 * gen: class
 * shared_ref: true
 * package: overloads
 * swift.include: CWrapper
 */
struct Utils {
    /**
     * __API__
     * gen: constructor
     */
    Utils() {};

    /**
     * Sum two ints.
     * __API__
     * gen: method
     */
    static int sum(int first, int second) {
        return first + second;
    }

    /**
     * Sum two floats.
     * __API__
     * gen: method
     */
    static float sum(float first, float second) {
        return first + second;
    }

    /**
     * Concatenate with two strings.
     * __API__
     * gen: method
     */
    std::string concatenate(std::string first, std::string second) {
        return first + second;
    }

    /**
     * Concatenate with three strings.
     * __API__
     * gen: method
     */
    std::string concatenate(std::string first, std::string second, std::string third) {
        return first + second + third;
    }
};
// [example]
}
#endif