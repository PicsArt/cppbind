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
#include "cxx/simple/project.hpp"


namespace cppbind::example {
// [example-start]
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
     * Full type name(i.e., cppbind::example::Stack<T> not just Stack<T>) should be explicitly specified otherwise
     * cppbind won't be able to generate a converter for the argument, as for templates libclang does not provide
     * enough information.
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Stack(cppbind::example::Stack<T>& stack) : _elements(stack._elements) {};

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Stack(T* st) {
        push(st);
    };

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


template <>
class Stack<cppbind::example::Project>: public Container {

public:

    Stack() {};

    Stack(cppbind::example::Stack<cppbind::example::Project>& stack) : _elements(stack._elements) {};

    Stack(cppbind::example::Project* st) {
        push(st);
    };

    void push(cppbind::example::Project* item) {
        _elements.push_back(item);
    };

    void pop() {
        _elements.pop_back();
    };

    cppbind::example::Project* top() const {
        return _elements.back();
    };

    bool empty() const {
         return _elements.empty();
    }

private:
    std::vector<cppbind::example::Project*> _elements;

};

// [example-end]
}
#endif

