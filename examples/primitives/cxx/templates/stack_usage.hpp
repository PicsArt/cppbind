#ifndef stack_usage_hpp
#define stack_usage_hpp

#include<unordered_map>
#include<vector>
#include <memory>
#include <string>

#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"

namespace iegen::example {

/**
 * comments
 *
 * __API__
 * gen: class
 * package: templates
 * python.include:
 *   - templates.stack_pygen
 *   - simple.project_pygen
 * kotlin.include: com.examples.simple.*
 * swift.include: CWrapper
 */
class StackUsage  {
    public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    StackUsage() {};

    /**
     * comments
     *
     * __API__
     * gen: method
     * throws: no_throw
     */
    Project* firstItemOfSpecialized(iegen::example::Stack<Project>* p) {
        return p->top();
    };

    /**
     * comments
     *
     * __API__
     * gen: method
     * template:
     *   V:
     *     - type: iegen::example::Project
     * throws: no_throw
     */
    template <typename V>
    V* firstItemOfTemplate(iegen::example::Stack<V>* p) {
        return p->top();
    };


    // not supported usage example
    template <typename V>
    V* usage3(Stack<V>* p) {
        return p->top();
    };

};

}
#endif