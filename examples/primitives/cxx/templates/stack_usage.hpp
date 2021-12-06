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
 * action: gen_class
 * package: templates
 */
class StackUsage  {
    public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    StackUsage() {};

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Project* firstItemOfSpecializedStack(iegen::example::Stack<Project>* p) {
        return p->top();
    };

    /**
     * __API__
     * action: gen_method
     * template:
     *   V:
     *     - type: iegen::example::Project
     * throws: no_throw
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
