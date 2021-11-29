#ifndef frame_hpp
#define frame_hpp

#include "cxx/enums/color.hpp"

namespace iegen::example {
// [example]
/**
 * Class Frame.
 * __API__
 * action: gen_class
 * package: enums
 */
struct Frame {
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Frame() {};

    /**
     * __API__
     * action: gen_property_setter
     */
    Color backgroundColor;

    /**
     * __API__
     * action: gen_property_setter
     */
    ColorShade backgroundColorShade;
};
// [example]
}
#endif