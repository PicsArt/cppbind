#ifndef null_utils_hpp
#define null_utils_hpp

#include <string>
#include <memory>


namespace iegen::example::nullable {
// [example]

/**
 * __API__
 * action: gen_class
 * shared_ref: true
 * swift.file: Utils
 * package: nullables
 * swift.include: CWrapper
 */
struct NumberInt {
    /**
     * __API__
     * action: gen_constructor
     */
    NumberInt(int val_) : value(val_) {}

    /**
     * __API__
     * action: gen_property_getter
     */
    int value;
};

/**
 * __API__
 * action: gen_class
 * shared_ref: false
 * swift.file: Utils
 * package: nullables
 * swift.include: CWrapper
 */
struct NumberDouble {
    /**
     * __API__
     * action: gen_constructor
     */
    NumberDouble(double val_) : value(val_) {}

    /**
     * __API__
     * action: gen_property_getter
     */
    double value;
};


/**
 * An example with nullable arguments.
 * __API__
 * action: gen_class
 * shared_ref: true
 * swift.file: Utils
 * package: nullables
 * kotlin.include:
 *  - com.examples.simple.Task
 * swift.include: CWrapper
 */
struct Utils {

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * nullable_arg:
     *   - first
     * nullable_return: True
     */
    static NumberDouble* max(NumberDouble* first, NumberDouble* second) {
        if (first && second) {
            if (first->value > second->value) {
                return first;
            }
            return second;
        }
        return nullptr;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * nullable_arg:
     *   - first
     *   - second
     * nullable_return: True
     */
    static std::shared_ptr<NumberInt> max(std::shared_ptr<NumberInt> first, std::shared_ptr<NumberInt> second) {
        if (first && second) {
            if (first->value > second->value) {
                return first;
            }
            return second;
        }
        return std::shared_ptr<NumberInt>(nullptr);
    }
};
// [example]
}
#endif