#ifndef functional_example_hpp
#define functional_example_hpp
#include <functional>

namespace iegen::example {
/**
 * comments
 * __API__
 * gen: class
 * shared_ref: true
 * package: functionals
 * swift.include: CWrapper
 */
class FunctionalExamples {
public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    FunctionalExamples() {}

    /**
     * comments
     *
     * __API__
     * gen: method
     * throws: no_throw
     */
    static std::function<int(int)> genFuncToIncrementResult(const std::function<int(int)> &f) {
        return [f](int i) {
            return f(i) + 1;
        };
    }

};

}
#endif