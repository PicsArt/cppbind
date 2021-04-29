/**
 * This is a simple example of overloaded sum function.
 */

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
 * swift.include: CWrapper
 */
struct Utils {


    /**
     * Concatenate with two strings.
     *
     * __API__
     * gen: method
     */
    static int sum(int first, int second) {
        return first + second;
    }

    /**
     * Concatenate with three strings.
     *
     * __API__
     * gen: method
     */
    static float sum(float first, float second) {
        return first + second;
    }
};
}
#endif