#ifndef pair_hpp
#define pair_hpp

#include <vector>
#include <memory>
#include <string>


namespace cppbind::example {
// [example]
/**
 * __API__
 * action: gen_class
 * template:
 *   T:
 *     - type: std::string
 *       name: ''
 *   V:
 *     - type: std::shared_ptr<cppbind::example::Employee>
 *       name: Employee
 *     - type: std::shared_ptr<cppbind::example::Student>
 *       name: Student
 * package: templates
 */
template <class T, class V>
class Pair {

    public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Pair(const T& first, const V& second) : _first(first), _second(second) {};

     /**
      * __API__
      * action: gen_getter
      * throws: no_throw
      */
     const T& first() const {
        return _first;
     }

     /**
      * __API__
      * action: gen_getter
      * throws: no_throw
      */
     const V& second() const {
        return _second;
     }

   private:
       T _first;
       V _second;

};
// [example]
}
#endif

