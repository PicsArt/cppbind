#ifndef path_hpp
#define path_hpp

#include <string>

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * shared_ref: False
 * package: simple
 */
struct Path {
public:
    /**
     * __API__
     * action: gen_constructor
     */
    Path(const std::string& _value) : value(_value) {};

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * python.name: __str__
     */
    const std::string& toString() {
        return value;
    }

    /**
     * __API__
     * action: gen_property_getter
     *
     */
     std::string value;
};
// [example]
}

#endif
