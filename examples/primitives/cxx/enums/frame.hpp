#ifndef frame_hpp
#define frame_hpp

#include "cxx/enums/color.hpp"

namespace iegen::example {
// [example]
/**
 * Class Frame.
 * __API__
 * gen: class
 * package: enums
 * swift.include: CWrapper
 */
struct Frame {
    /**
     * __API__
     * gen: constructor
     */
    Frame() {};

    /**
     * __API__
     * gen: property_setter
     */
    Color backgroundColor;

};
// [example]
}
#endif