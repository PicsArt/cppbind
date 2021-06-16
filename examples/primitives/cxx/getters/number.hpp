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
 * gen: class
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
     * gen: constructor
     */
    Number(const T& n): num(n) {}

    /**
     * __API__
     * gen: method
     * throws: no_throw
     * python.name: __int__
     */
    int toInt() {
        return (int)num;
    }

     /**
     * __API__
     * gen: property_setter
     */
     T num;
};
// [example]
}
#endif
