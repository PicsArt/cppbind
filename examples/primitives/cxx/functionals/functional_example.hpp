#ifndef functional_example_hpp
#define functional_example_hpp
#include <functional>

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * shared_ref: true
 * package: functionals
 */
class FunctionalExamples {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    FunctionalExamples() {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static std::function<int(int)> genFuncToIncrementResult(const std::function<int(int)> &f) {
        return [f](int i) {
            return f(i) + 1;
        };
    }
};
// [example]
}
#endif