#ifndef color_hpp
#define color_hpp

namespace iegen::example {
// [example]
/**
 * Color Enum.
 * __API__
 * action: gen_enum
 * package: enums
 * swift.include: CWrapper
 */
enum class Color {
    /**
     * Red = 1
     */
    Red = 1,
    /**
     * Green = 1
     */
    Green = 2,
    /**
     * Blue = 20
     */
    Blue = 20
};
// [example]
}
#endif