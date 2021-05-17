/**
* This is an example for template property getter/setter.
*/

#ifndef overload_hpp
#define overload_hpp
#include <string>

namespace iegen::example {
/**
 * comments
 *
 * __API__
 * gen: class
 * package: getters
 * shared_ref: True
 * template: {"T": ["int", "double"]}
 * swift.include: CWrapper
 */
template <class T>
class Number {
    public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    Number(const T& n): num(n) {}

     /**
     * comments
     *
     * __API__
     * gen: property_setter
     */
     T num;
};
}
#endif