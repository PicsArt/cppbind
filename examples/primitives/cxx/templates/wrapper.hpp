#ifndef wrapper_hpp
#define wrapper_hpp

#include <vector>
#include <memory>
#include <string>


namespace iegen::example {
// [example]
/**
 * This is a template class example.
 * For templates user must explicitly specify all possible types for each template parameter in the API using
 * template attribute.
 * __API__
 * action: gen_class
 * template:
 *   T:
 *     - type: std::pair<std::string, std::string>
 *       name: PairStrings
 *     - type: std::pair<int, int>
 *     - type: std::string
 * package: templates
 */
template <class T>
class Wrapper {

    public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Wrapper(const T& value) : _value(value) {};

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     */
    void setValue(const T& value) {
        _value = value;
    };

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
     const T& value() const {
        return _value;
     };


    private:
        T _value;

};
// [example]

///**
// * This is an example of template type containing nested template type.
// * TODO: uncomment and write test examples after implementing https://picsart.atlassian.net/browse/IEGEN-242
// * __API__
// * action: gen_class
// * template:
// *   TFirst:
// *     - type: iegen::example::Project
// *     - type: iegen::example::Task
// * package: templates.nested
// */
//template <class TFirst>
//class NestedWrapper {
//public:
//    /**
//     * __API__
//     * action: gen_class
//     * template:
//     *   TSecond:
//     *     - type: std::string
//     *     - type: int
//     */
//    template <class TSecond>
//    struct Item {
//
//        /**
//         * __API__
//         * action: gen_constructor
//         * throws: no_throw
//         */
//        Item(const std::pair<TFirst, TSecond>& v) : value(v) {}
//
//        /**
//         * __API__
//         * action: gen_property_setter
//         */
//        std::pair<TFirst, TSecond> value;
//    };
//};

}
#endif

