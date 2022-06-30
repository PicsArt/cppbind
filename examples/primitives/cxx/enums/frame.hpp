#ifndef frame_hpp
#define frame_hpp

#include "cxx/enums/color.hpp"

namespace cppbind::example {
// [example-start]
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

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     Color getNextColor(const Color& color) {
        switch(color) {
            case Color::Red: return Color::Green;
            case Color::Green: return Color::Blue;
            case Color::Blue: return Color::Red;
        }
        return Color::Red;
     }
};
// [example-end]
}
#endif