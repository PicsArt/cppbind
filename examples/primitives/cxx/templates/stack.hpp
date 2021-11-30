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


namespace iegen::example {
// [example]
/**
 * comments
 *
 * __API__
 * action: gen_class
 * template:
 *   T:
 *     - type: iegen::example::Project
 *       name: Prj
 *     - type: iegen::example::Task
 *     - type: iegen::example::Number<int>
 *       name: NumInt
 * package: templates
 */
template <class T>
class Stack: public Container {

    public:
    /**
     * __API__
     * action: gen_constructor
     */
    Stack() {};

    /**
     * __API__
     * action: gen_constructor
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

