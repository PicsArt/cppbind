#ifndef root_hpp
#define root_hpp

#include <string>

namespace iegen::example {
// [example]
/**
 * comments
 *
 * __API__
 * gen: class
 * shared_ref: False
 * package: simple
 * swift.include: CWrapper
 */
struct Root {
public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     *
     */
    Root(const std::string& _path) : path(_path) {};

    /**
     * comments
     *
     * __API__
     * gen: property_getter
     *
     */
     std::string path;
};
// [example]
}

#endif
