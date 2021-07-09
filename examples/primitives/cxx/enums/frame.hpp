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
     */
    Frame() {};

    /**
     * __API__
     * action: gen_property_setter
     */
    Color backgroundColor;

};
// [example]
}
#endif