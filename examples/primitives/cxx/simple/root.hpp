#ifndef root_hpp
#define root_hpp

#include <string>

namespace iegen::example {
// [example]
/**
 * \internal
 * internal comment should not go to wrappers
 * \endinternal
 * Class Root
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
     * __API__
     * gen: method
     * throws: no_throw
     * kotlin.name: updatePath
     */
    void setPath(const std::string& _path) {
        path = _path;
    };

    /**
     * __API__
     * gen: property_setter
     */
     std::string path;
};
// [example]
}

#endif
