#ifndef stack_usage_hpp
#define stack_usage_hpp

#include<unordered_map>
#include<vector>
#include <memory>
#include <string>


namespace iegen::example {

/**
 * comments
 *
 * __API__
 * gen: class
 * package: templates
 * python.include: classes.project_pygen
 * python.include: classes.task_pygen
 */
class TemplateFunctions  {
    public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    TemplateFunctions() {};

    /**
     * comments
     *
     * __API__
     * gen: method
     * template: {"T": [{"type": "int"}, {"type": "std::string"}]}
     * throws: no_throw
     */
    template <typename T>
    T const& max(T const& a, T const& b) {
       return a < b ? b:a;
    }

    /**
     * comments
     *
     * __API__
     * gen: method
     * template: {"T": ["iegen::example::Project", "iegen::example::Task"], "V": ["iegen::example::Project"]}
     * throws: no_throw
     */
    template <typename T, typename V>
    std::pair<T, V> makePair(T const& a, V const& b) {
       return std::make_pair(a, b);
    }

//        /**
//     * comments
//     *
//     * __API__
//     * gen: method
//     * template: {"V": [{"type": "iegen::example::Project"}]}
//     */
//    template <typename V>
//    void usage4(std::shared_ptr<V> p) {
//    //    return p->top();
//    };

};

}
#endif