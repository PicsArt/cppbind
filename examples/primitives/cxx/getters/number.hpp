/**
* This is an example for template property getter/setter.
*/

#ifndef overload_hpp
#define overload_hpp
#include <string>

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * package: getters
 * shared_ref: True
 * template:
 *   T:
 *     - type: int
 *     - type: double
 * swift.include: CWrapper
 */
template <class T>
class Number {
    public:
    /**
     * __API__
     * action: gen_constructor
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
