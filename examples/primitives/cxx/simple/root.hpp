#ifndef root_hpp
#define root_hpp

#include <string>

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * shared_ref: False
 * swift.package: simple
 * kotlin.package: simple
 * swift.include: CWrapper
 */
struct Root {
public:
    /**
     * comments
     *
     * __API__
     * action: gen_constructor
     */
    Root(const std::string& _path) : path(_path) {};

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * kotlin.name: updatePath
     */
    void setPath(const std::string& _path) {
        path = _path;
    };

    /**
     * __API__
     * action: gen_property_setter
     */
     std::string path;
};
// [example]
}

#endif
