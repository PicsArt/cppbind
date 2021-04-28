/**
 * This is a color enum usage example.
 */
#ifndef frame_hpp
#define frame_hpp

#include "cxx/enums/color.hpp"

namespace iegen::example {
/**
 *
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
}
#endif