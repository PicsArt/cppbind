#ifndef null_utils_hpp
#define null_utils_hpp

#include <string>
#include <memory>


namespace iegen::example::nullable {
// [example-helpers]

/**
 * __API__
 * action: gen_class
 * shared_ref: true
 * swift.file: NullableUtils
 * swift.name: NumInt
 * package: nullables
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
 * swift.file: NullableUtils
 * swift.name: NumDouble
 * package: nullables
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
// [example-helpers]

// [example]
/**
 * An example with nullable arguments.
 * __API__
 * action: gen_class
 * shared_ref: true
 * swift.file: NullableUtils
 * swift.name: NullableUtils
 * package: nullables
 */
struct Utils {

    /**
     * __API__
     * action: gen_constructor
     * nullable_arg:
     *   - num
     */
    Utils(NumberDouble* num) : numDouble(num) {}

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

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static void checkNonnullArg(NumberDouble* number) {

    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static NumberDouble* checkNonnullReturn() {
        return nullptr;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     * nullable_return: True
     */
    NumberDouble* nullable() {
        return numDouble;
    }

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     * nullable_arg: num
     */
    void setNullable(NumberDouble* num) {
        numDouble = num;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    NumberDouble* nonNull() {
        return numDouble;
    }

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     */
    void setNonNull(NumberDouble* num) {
        numDouble = num;
    }

    /**
     * __API__
     * action: gen_property_setter
     * nullable_return: True
     */
    NumberDouble* numDouble;

    /**
     * __API__
     * action: gen_property_setter
     * nullable_return: False
     */
    std::shared_ptr<NumberInt> numInt;

};
// [example]
}
#endif