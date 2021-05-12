#ifndef stack_usage_hpp
#define stack_usage_hpp

#include<unordered_map>
#include<vector>
#include <memory>
#include <string>

namespace iegen::example {

/**
 * __API__
 * gen: class
 * package: templates
 * kotlin.include: com.examples.simple.*
 * python.include: simple.project_pygen
 * python.include: simple.task_pygen
 * swift.include: CWrapper
 */
class TemplateMethods  {
    public:
    /**
     * __API__
     * gen: constructor
     */
    TemplateMethods() {};

    /**
     * __API__
     * gen: method
     * template: {"T": [{"type": "int"}, {"type": "std::string"}]}
     */
    template <typename T>
    T const& max(T const& a, T const& b) {
       return a < b ? b:a;
    }

    /**
     * __API__
     * gen: method
     * template: {"T": ["iegen::example::Project", "iegen::example::Task"], "V": ["iegen::example::Project"]}
     */
    template <typename T, typename V>
    std::pair<T*, V*> makePair(T* a, V* b) {
       return std::make_pair(a, b);
    }
};
}
#endif