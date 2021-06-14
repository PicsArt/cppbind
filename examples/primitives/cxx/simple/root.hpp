#ifndef root_hpp
#define root_hpp

#include <string>

namespace iegen::example {
// [example]
/**
 * __API__
 * gen: class
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
     * gen: constructor
     */
    Root(const std::string& _path) : path(_path) {};

    /**
     * comments
     *
     * __API__
     * gen: property_setter
     */
     std::string path;
};
// [example]
}

#endif
