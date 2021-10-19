/**
 * This is a template class example.
 * For templates user mush explicitly specify all possible types for each template parameter in the API using
 * template attribute.
 */


#ifndef wrapper_hpp
#define wrapper_hpp

#include <vector>
#include <memory>
#include <string>


namespace iegen::example {
// [example]
/**
 * comments
 *
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
}
#endif

