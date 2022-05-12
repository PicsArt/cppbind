/**
 * This is a template class example.
 * For templates user mush explicitly specify all possible types for each template parameter in the API using
 * template attribute.
 */


#ifndef stack_hpp
#define stack_hpp

#include <vector>
#include <memory>
#include <string>

#include "cxx/templates/container.hpp"


namespace cppbind::example {
// [example]
/**
 * An example of a class template.
 * __API__
 * action: gen_class
 * template:
 *   T:
 *     - type: cppbind::example::Project
 *       name: Prj
 *     - type: cppbind::example::Task
 *     - type: cppbind::example::Number<int>
 *       name: NumInt
 * package: templates
 */
template <class T>
class Stack: public Container {

    public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Stack() {};

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Stack(T& st) {};

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void push(T* item) {
        _elements.push_back(item);
    };
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void pop() {
        _elements.pop_back();
    };
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
     T* top() const {
        return _elements.back();
     };
     /**
      * __API__
      * action: gen_method
      * throws: no_throw
      */
     bool empty() const {
        return _elements.empty();
     }

   private:
   std::vector<T*> _elements;

};
// [example]
}
#endif

