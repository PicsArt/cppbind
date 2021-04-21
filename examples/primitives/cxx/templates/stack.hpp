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
 * template: {"T": ["iegen::example::Project", "iegen::example::Task"]}
 * package: templates
 * kotlin.include: com.example.classes.Project
 * kotlin.include: com.example.classes.Task
 * python.include: classes.project_pygen
 * python.include: classes.task_pygen
 */
template <class T>
class Stack {

    public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    Stack() {};

       /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    Stack(T& st) {};

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    void push(T* item) {
        _elements.push_back(item);
    };
    /**
     * comments
     *
     * __API__
     * gen: method
     */
    void pop() {
        _elements.pop_back();
    };
    /**
     * comments
     *
     * __API__
     * gen: method
     */
     T* top() const {
        return _elements.back();
     };
     /**
      * comments
      *
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

