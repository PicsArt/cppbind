#ifndef overload_hpp
#define overload_hpp

#include <array>
#include <string>

namespace cppbind::example {
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

    // [overload-example-start]
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
    // [overload-example-end]

    // [static-example-start]
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
    // [static-example-end]

    // [overloaded-with-template-args]
    using ArrayInt = std::array<int, 4>;

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * python.name: sum_lists
     */
    ArrayInt sum(ArrayInt first, ArrayInt second) {
        ArrayInt res;
        for (int i = 0; i < 4; ++i) {
            res[i] = first[i] + second[i];
        }
        return res;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * python.name: sum_lists
     */
    std::array<float, 4> sum(std::array<float, 4> first, std::array<float, 4> second) {
        std::array<float, 4> res;
        for (int i = 0; i < 4; ++i) {
            res[i] = first[i] + second[i];
        }
        return res;
    }
    // [overloaded-with-template-args]
};
}
#endif