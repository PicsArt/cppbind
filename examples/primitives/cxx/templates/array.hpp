#ifndef cxx_array_hpp
#define cxx_array_hpp

#include <vector>
#include <array>
#include <string>

namespace cppbind::example {
// [example-start]
/**
 * __API__
 * action: gen_class
 * package: templates
 * template:
 *  SIZE:
 *   - value: 2
 *     name: '2'
 *   - value: 3
 *     name: '3'
 *  T:
 *   - type: float
 *   - type: int
 */
template <typename T = float, std::size_t SIZE = 2>
class Array {

public:

    Array() {}

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Array(const cppbind::example::Array<T, SIZE>& array) : _array(array._array) {}

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Array(const std::array<T, SIZE> array) : _array(array) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    T& operator[](int idx) {
        return _array[idx];
    }

    const T& operator[](int idx) const {
        return _array[idx];
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    cppbind::example::Array<T, SIZE> operator+(const cppbind::example::Array<T, SIZE>& rhs) const {
        Array res;
        for (int i = 0; i < SIZE; ++i) {
            res[i] = _array[i] + rhs[i];
        }
        return res;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    cppbind::example::Array<T, SIZE> operator-(const cppbind::example::Array<T, SIZE>& rhs) const {
        Array res;
        for (int i = 0; i < SIZE; ++i) {
            res[i] = _array[i] - rhs[i];
        }
        return res;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    bool operator==(const cppbind::example::Array<T, SIZE>& rhs) const {
        for (int i = 0; i < SIZE; ++i) {
            if (_array[i] != rhs[i]) {
                return false;
            }
        }
        return true;
    }

    /**
     * Kotlin equals covers also !=.
     * __API__
     * swift.action: gen_method
     * python.action: gen_method
     * throws: no_throw
     */
    bool operator!=(const cppbind::example::Array<T, SIZE>& rhs) const {
        return !(*this == rhs);
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    const std::array<T, SIZE>& data() const {
        return _array;
    }

private:
    std::array<T, SIZE> _array {};
};

/**
 * An example of template function with an argument of Array<T, 2> type.
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: templates
 * template:
 *  T:
 *   - type: float
 *   - type: int
 */
template<typename T>
T getFirstElement(const cppbind::example::Array<T, 2>& a) {
    return a[0];
}

/**
 *  An example of template function with an argument of Array<int, 2> type.
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: templates
 */
cppbind::example::Array<int, 2> multiplyElements(const cppbind::example::Array<int, 2>& a, int num) {
    std::array<int, 2> res {num * a[0], num * a[1]};
    return res;
}

using ArrayFloat = Array<>;

/**
 * An example of template function with an argument of typedef on Array.
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: templates
 */
ArrayFloat addToElements(const cppbind::example::ArrayFloat& a, int num) {
    std::array<float, 2> res {num + a[0], num + a[1]};
    return res;
}

using ArrayInt = Array<int, 2>;

/**
 * An example of template function with an argument of typedef on Array.
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: templates
 */
ArrayInt addToElements(const ArrayInt& a, int num) {
    std::array<int, 2> res {num + a[0], num + a[1]};
    return res;
}

/**
 * An example of template function with an argument of Array<T, 2> type.
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: templates
 * template_instance:
 *      - args: int, 2
 */
template<typename T, std::size_t SIZE>
T getLastElement(const cppbind::example::Array<T, SIZE>& a) {
    return a[SIZE - 1];
}

static constexpr size_t SIZE = 3;
static constexpr size_t LENGTH3 = SIZE * SIZE;

/**
 * An example with template argument with expression.
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: templates
 */
class Array3 {

public:

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Array3(const std::array<float, LENGTH3>& arr): _arr(arr) {}

    const std::array<float, LENGTH3>& arr() {
        return _arr;
    }

private:
    std::array<float, LENGTH3> _arr {};
};

/**
 * An example with template partial specialization.
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: templates
 * template_instance:
 *   - args: float
 *     name: Array4Float
 *   - args: int
 *     name: Array4Int
 */
template <typename T>
class Array<T, 4> {

public:

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Array(const std::array<T, 4> array) : _array(array) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    T& operator[](int idx) {
        return _array[idx];
    }

private:
    std::array<T, 4> _array {};
};

// [example-end]

}
#endif