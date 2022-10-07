#ifndef vector_wrapper_hpp
#define vector_wrapper_hpp

#include <vector>
#include <string>

namespace cppbind::example {
// [template-instance-example-start]
/**
 * __API__
 * action: gen_class
 * package: templates
 * swift.file: template_vector
 * template_instance:
 *      - args: int, std::allocator<int>
 *        name: VectorInt
 *      - args: std::string, std::allocator<std::string>
 *        name: StringsVector
 *      - args: double, std::allocator<double>
 */
template <typename T, typename Allocator=std::allocator<T>>
class Vector {

public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Vector() {}

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Vector(const cppbind::example::Vector<T, Allocator>& vec) : _vec(vec._vec) {}

    Vector(const std::vector<T>& vec) : _vec(vec._vec) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * swift.name: pushBack
     * kotlin.name: pushBack
     */
    void push_back(const T& value) {
        _vec.push_back(value);
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * swift.name: popBack
     * kotlin.name: popBack
     */
    void pop_back() {
        _vec.pop_back();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    const T& operator[](int idx) const {
        return _vec[idx];
    }

    T& operator[](int idx) {
        return _vec[idx];
    }


    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    cppbind::example::Vector<T, Allocator> operator+(const cppbind::example::Vector<T, Allocator>& rhs) const {
        Vector res;
        for (int i = 0; i < _vec.size(); ++i) {
            res.push_back(_vec[i] + rhs[i]);
        }
        return res;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    bool operator==(const cppbind::example::Vector<T, Allocator>& rhs) const {
        for (int i = 0; i < _vec.size(); ++i) {
            if (_vec[i] != rhs[i]) {
                return false;
            }
        }
        return true;
    }

private:
    std::vector<T, Allocator> _vec {};
};
// [template-instance-example-end]

///**
// * __API__
// * action: gen_function
// * throws: no_throw
// * swift.file: template_vector
// * template_instance:
// *   - args: int, int
// *     name: createIntArray
// */
//template <typename T, typename... Args>
//static Vector<T>* createVector(Args&&... args) {
//    return new Vector<T>(std::vector<T>(std::forward<Args>(args)...));
//}


}
#endif
