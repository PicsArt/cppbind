#ifndef template_methods_hpp
#define template_methods_hpp

#include <utility>


namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * package: templates
 */
class TemplateMethods  {
    public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    TemplateMethods() {};

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * template:
     *   T:
     *     - type: int
     *     - type: std::string
     */
    template <typename T>
    T const& max(T const& a, T const& b) {
       return a < b ? b:a;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * template:
     *   T:
     *     - type: iegen::example::Project
     *     - type: iegen::example::Root
     *   V:
     *     - type: iegen::example::Project
     * return_value_policy: reference
     */
    template <typename T, typename V>
    std::pair<T*, V*> makePair(T* a, V* b) {
       return std::make_pair(a, b);
    }
};
// [example]
}
#endif
