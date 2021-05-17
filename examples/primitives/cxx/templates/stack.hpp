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


namespace iegen::example {

/**
 * comments
 *
 * __API__
 * gen: class
 * template:
 *   T:
 *     - iegen::example::Project
 *     - iegen::example::Task
 * package: templates
 * kotlin.include: com.examples.simple.*
 * python.include: simple
 * swift.include: CWrapper
 */
template <class T>
class Stack {

    public:
    /**
     * __API__
     * gen: constructor
     */
    Stack() {};

    /**
     * __API__
     * gen: constructor
     */
    Stack(T& st) {};

    /**
     * __API__
     * gen: method
     * throws: no_throw
     */
    void push(T* item) {
        _elements.push_back(item);
    };
    /**
     * __API__
     * gen: method
     * throws: no_throw
     */
    void pop() {
        _elements.pop_back();
    };
    /**
     * __API__
     * gen: method
     * throws: no_throw
     */
     T* top() const {
        return _elements.back();
     };
     /**
      * __API__
      * gen: method
      * throws: no_throw
      */
     bool empty() const {
        return _elements.empty();
     }

   private:
   std::vector<T*> _elements;

};
}
#endif

