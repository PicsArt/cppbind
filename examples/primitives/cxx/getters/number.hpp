/**
* This is an example for template property getter/setter.
*/

#ifndef number_hpp
#define number_hpp
#include <string>

namespace cppbind::example {
// [example]
/**
 * __API__
 * action: gen_class
 * package: getters
 * shared_ref: False
 * template:
 *   T:
 *     - type: int
 *     - type: double
 */
template <class T>
class Number {
    public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Number(const T& n): num(n) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * python.name: __int__
     */
    int toInt() {
        return (int)num;
    }

     /**
     * __API__
     * action: gen_property_setter
     */
     T num;
};
// [example]
}
#endif
