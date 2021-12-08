#ifndef parallelogram_hpp
#define parallelogram_hpp

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_interface
 * shared_ref: False
 * package: inheritance
 * swift.descendants:
 *  - iegen::example::Rectangle
 *  - iegen::example::Rhombus
 *  - iegen::example::Square
 */
class Parallelogram {
public:

    Parallelogram() {};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    virtual double area() const = 0;

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    virtual double perimeter() const = 0;

    virtual ~Parallelogram() = default;
};
// [example]
}
#endif