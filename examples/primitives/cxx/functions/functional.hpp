#ifndef function_hpp
#define function_hpp
#include <functional>

namespace iegen::example {
// [example]
/**
 * __API__
 * gen: class
 * shared_ref: true
 * package: functions
 * swift.include: CWrapper
 */
class FunctionalExamples {
public:
    /**
     * __API__
     * gen: constructor
     */
    FunctionalExamples() {}

    /**
     * __API__
     * gen: method
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