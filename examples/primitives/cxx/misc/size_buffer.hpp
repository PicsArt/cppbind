#ifndef third_party_types_usage_example_h
#define third_party_types_usage_example_h

#include <string>
#include <cmath>
#include "buffer.hpp"

typedef cppbind::example::Size<float> SizeF;

namespace cppbind::example {

/**
 * comments
 *
 * __API__
 * action: gen_class
 * package: misc
 * kotlin.include:
 *   - java.awt.geom.Point2D
 * python.include:
 *   - from buffer import SizeF, Buffer
 */
class SizeUsage {
    public:

    /**
    * comments
    *
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    static SizeF multiplyBy(SizeF size, int n) {
        float new_width = n * size.width;
        float new_height = n * size.height;
        return SizeF(new_width, new_height);
    }

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static SizeF doubleSizeF(const SizeF& resolution = SizeF(NAN, NAN)) {
        if (std::isnan(resolution.width) | std::isnan(resolution.height)) {
            return {NAN, NAN};
        } else {
            return SizeF((float)resolution.width * 2, (float)resolution.height * 2);
        }
    }

};

/**
 * comments
 *
 * __API__
 * python.action: gen_class
 * kotlin.action: gen_class
 * package: misc
 * python.include:
 *   - from buffer import SizeF, Buffer
 */
class BufferUsage {
    public:
    /**
    * __API__
    * kotlin.action: gen_constructor
    * python.action: gen_constructor
    * throws: no_throw
    */
    BufferUsage() {};

    /**
    * __API__
    * python.action: gen_method
    * kotlin.action: gen_method
    * throws: no_throw
    */
    std::string usage1(cppbind::example::Buffer<int>& b) const {
        return b.print();
    }

    /**
    * __API__
    * python.action: gen_method
    * kotlin.action: gen_method
    * throws: no_throw
    */
    cppbind::example::Buffer<int>* usage2() const {
        return new cppbind::example::Buffer<int>();
    }

};

}

#endif

