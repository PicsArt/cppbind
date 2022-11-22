#ifndef stack_usage_hpp
#define stack_usage_hpp

#include<unordered_map>
#include<vector>
#include <memory>
#include <string>

#include "cxx/templates/stack.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"

using StackProjectType = cppbind::example::Stack<cppbind::example::Project>;

namespace cppbind::example {
// [example-start]
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
     * return_value_policy: reference
     */
    Project* firstItemOfSpecializedStack(Stack<Project>* p) {
        return p->top();
    };

    using StackProject = Stack<Project>;

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    Project* firstItemOfTypedefOfSpecializedStack(StackProject* p) {
        return p->top();
    };

    /**
     * Full type name(i.e., cppbind::example::Stack<V> not just Stack<V>) should be explicitly specified otherwise
     * cppbind won't be able to generate a converter for the argument, as for templates libclang does not provide
     * enough information.
     * __API__
     * action: gen_method
     * template:
     *   V:
     *     - type: cppbind::example::Project
     * throws: no_throw
     * return_value_policy: reference
     */
    template <typename V>
    V* firstItemOfTemplateStack(cppbind::example::Stack<V>* p) {
        return p->top();
    };

    /**
     * Example to check typedef argument types
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    Project* firstItemOfSpecializedStackWithTypedefArg(StackProjectType* p) {
        return p->top();
    };

    // not supported use cases

    /**
     * Templates without full type names are not supported. Argument full type name(cppbind::example::Stack<V>) should
     * be explicitly specified, so that cppbind can parse the argument.
     */
    template <typename V>
    V* firstItemOfTemplateStackNotSupported(Stack<V>* p) {
        return p->top();
    };

};
// [example-end]

/**
 * An example of a type derived from a template.
 * __API__
 * action: gen_class
 * file: my_stack
 * template:
 *   TItem:
 *     - type: cppbind::example::Project
 *     - type: cppbind::example::Task
 * package: templates
 */
template <class TItem>
class MyStack: public cppbind::example::Stack<TItem> {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    MyStack() {};

    // not supported use cases

    using Stack = cppbind::example::Stack<TItem>;

    /**
     * Typedefs of template types are not supported.
     */
    TItem* firstItemOfTypedefTemplateStack(Stack* p) {
        return p->top();
    };

};


/**
 * An example of a fully specialized template type having an API.
 * __API__
 * action: gen_class
 * package: templates.stack
 * name: RootsStack
 * file: stack_root
 */
template<>
class Stack<Root>: public Container {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Stack() {};

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void push(Root* item) {
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
    Root* top() const {
        return _elements.back();
    };

private:
    std::vector<Root*> _elements;

};


/**
 * An example of a type derived from a fully specialized template.
 * __API__
 * action: gen_class
 * file: stack_root
 * package: templates.stack
 */
class MyStackRoot: public Stack<Root> {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    MyStackRoot() {};

    using StackRoot = Stack<Root>;

    /**
     * Method having typedef of a full specialization as an argument.
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Root* firstItemOfTypedef(StackRoot* p) {
        return p->top();
    };

};

}
#endif
