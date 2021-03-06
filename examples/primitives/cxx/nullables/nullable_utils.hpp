#ifndef null_utils_hpp
#define null_utils_hpp

#include <string>
#include <memory>
#include <cstring>
#include <algorithm>

namespace cppbind::example::nullable {
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
     * throws: no_throw
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
     * throws: no_throw
     */
    NumberDouble(double val_) : value(val_) {}

    /**
     * __API__
     * action: gen_property_getter
     */
    double value;
};
// [example-helpers]

// [example-start]
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
     * throws: no_throw
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
     * return_value_policy: reference
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
        if (!number){
            throw std::invalid_argument("number cannot be nullptr.");
        }
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    static NumberDouble* checkNonnullReturn() {
        return nullptr;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     * nullable_return: True
     * return_value_policy: reference
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
     * return_value_policy: reference
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
     * return_value_policy: reference
     */
    NumberDouble* numDouble;

    /**
     * __API__
     * action: gen_property_setter
     * nullable_return: False
     */
    std::shared_ptr<NumberInt> numInt;

};

/**
 * __API__
 * action: gen_function
 * package: nullables
 * swift.file: NullableUtils
 * throws: no_throw
 * nullable_arg: s
 * nullable_return: True
 */
const char* reverseString(const char* s) {
    if (s) {
        auto str = std::string(s);
        std::reverse(str.begin(), str.end());
        char* res = new char[sizeof(char) * strlen(s)];
        std::strcpy(res, str.c_str());
        return res;
    }
    return nullptr;
}

// [example-end]
}
#endif