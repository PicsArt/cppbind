#ifndef path_hpp
#define path_hpp

#include <string>

namespace iegen::example {
// [example]
/**
 * __API__
 * gen: class
 * shared_ref: False
 * package: simple
 * swift.include: CWrapper
 */
struct Path {
public:
    /**
     * __API__
     * gen: constructor
     */
    Path(const std::string& _value) : value(_value) {};

    /**
     * __API__
     * gen: method
     * throws: no_throw
     * python.name: __str__
     */
    const std::string& toString() {
        return value;
    }

    /**
     * __API__
     * gen: property_getter
     *
     */
     std::string value;
};
// [example]
}

#endif
