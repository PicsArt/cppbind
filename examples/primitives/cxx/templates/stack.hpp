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
 * __API__
 * gen: class
 * template: {"T": ["iegen::example::Project", "iegen::example::Root"]}
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
     */
    void push(T* item) {
        _elements.push_back(item);
    };
    /**
     * __API__
     * gen: method
     */
    void pop() {
        _elements.pop_back();
    };
    /**
     * __API__
     * gen: method
     */
     T* top() const {
        return _elements.back();
     };
     /**
      * __API__
      * gen: method
      */
     bool empty() const {
        return _elements.empty();
     }

   private:
   std::vector<T*> _elements;

};
}
#endif

