#ifndef template_methods_hpp
#define template_methods_hpp

#include <utility>


namespace iegen::example {
// [example]
/**
 * __API__
 * gen: class
 * package: templates
 * kotlin.include: com.examples.simple.*
 * python.include: simple
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
     * throws: no_throw
     * template: {"T": [{"type": "int"}, {"type": "std::string"}]}
     */
    template <typename T>
    T const& max(T const& a, T const& b) {
       return a < b ? b:a;
    }

    /**
     * __API__
     * gen: method
     * throws: no_throw
     * template: {"T": ["iegen::example::Project", "iegen::example::Root"], "V": ["iegen::example::Project"]}
     */
    template <typename T, typename V>
    std::pair<T*, V*> makePair(T* a, V* b) {
       return std::make_pair(a, b);
    }
};
// [example]
}
#endif