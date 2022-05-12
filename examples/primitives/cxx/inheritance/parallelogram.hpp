#ifndef parallelogram_hpp
#define parallelogram_hpp

namespace cppbind::example {
// [example]
/**
 * __API__
 * action: gen_interface
 * shared_ref: False
 * package: inheritance
 * descendants:
 *  - cppbind::example::Rectangle
 *  - cppbind::example::Rhombus
 *  - cppbind::example::Square
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

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    bool equals(Parallelogram* p) const {
        return this == p;
    }
};
// [example]
}
#endif