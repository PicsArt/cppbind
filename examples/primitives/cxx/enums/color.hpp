#ifndef color_hpp
#define color_hpp

namespace iegen::example {
// [example]
/**
 * Color Enum.
 * __API__
 * action: gen_enum
 * package: enums
 * python.code_fragment:
 *   - >
 *    def __str__(self):
 *        return str(self.value)
 * kotlin.code_fragment:
 *   - >
 *    override fun toString(): String {
 *        return this.value.toString()
 *    }
 * swift.bases_list: CustomStringConvertible
 * swift.code_fragment:
 *   - >
 *    public var description: String {
 *        return "\(self.rawValue)"
 *    }
 */
enum class Color {
    /**
     * Red = 1
     */
    Red = 1,
    /**
     * Green = 2
     */
    Green = 2,
    /**
     * Blue = 20
     */
    Blue = 20
};

/**
 * __API__
 * action: gen_enum
 * package: enums
 * enum_field_name_prefix: Shade
 */
enum class ColorShade {
    ///
    /// Light = 1
    ///
    Light = 1,
    /// Dark = 2
    ///
    Dark = 2
};
// [example]
}
#endif
