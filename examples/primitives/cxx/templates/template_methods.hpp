#ifndef template_methods_hpp
#define template_methods_hpp

#include <utility>


namespace cppbind::example {
// [example-start]
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
     *     - type: cppbind::example::Project
     *     - type: cppbind::example::Root
     *   V:
     *     - type: cppbind::example::Project
     * return_value_policy: reference
     */
    template <typename T, typename V>
    std::pair<T*, V*> makePair(T* a, V* b) {
       return std::make_pair(a, b);
    }
};
// [example-end]

///**
// * An example for testing template functions inside a template.
// * TODO: uncomment and write test examples after implementing #243
// * __API__
// * action: gen_class
// * package: templates.nested
// * template:
// *   T:
// *     - type: cppbind::example::Project
// *     - type: cppbind::example::Root
// */
//template <typename T>
//class TemplateUtils  {
//    public:
//
//    /**
//     * __API__
//     * action: gen_method
//     * throws: no_throw
//     * template:
//     *   U:
//     *     - type: int
//     *     - type: std::string
//     */
//    template <typename U>
//    static U const& max(U const& a, U const& b) {
//       return a < b ? b:a;
//    }
//
//    /**
//     * __API__
//     * action: gen_method
//     * throws: no_throw
//     * template:
//     *   V:
//     *     - type: cppbind::example::Project
//     * return_value_policy: reference
//     */
//    template <typename V>
//    static std::pair<T*, V*> makePair(T* a, V* b) {
//       return std::make_pair(a, b);
//    }
//};

}
#endif
