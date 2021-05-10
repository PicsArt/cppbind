#ifndef stack_usage_hpp
#define stack_usage_hpp

#include<unordered_map>
#include<vector>
#include <memory>
#include <string>

#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"

namespace iegen::example {
// [example]
/**
 * __API__
 * gen: class
 * package: templates
 * python.include: templates.stack_pygen
 * python.include: simple.project_pygen
 * kotlin.include: com.examples.simple.*
 * swift.include: CWrapper
 */
class StackUsage  {
    public:
    /**
     * __API__
     * gen: constructor
     */
    StackUsage() {};

    /**
     * __API__
     * gen: method
     */
    Project* firstItemOfSpecializedStack(iegen::example::Stack<Project>* p) {
        return p->top();
    };

    /**
     * __API__
     * gen: method
     * template: {"V": [{"type": "iegen::example::Project"}]}
     */
    template <typename V>
    V* firstItemOfTemplateStack(iegen::example::Stack<V>* p) {
        return p->top();
    };

    // not supported usage example
    template <typename V>
    V* usage3(Stack<V>* p) {
        return p->top();
    };

};
// [example]
}
#endif