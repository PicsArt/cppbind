#ifndef rectangle_hpp
#define rectangle_hpp
#include "cxx/inheritance/parallelogram.hpp"

namespace cppbind::example {
// [example-start]
/**
 * __API__
 * action: gen_interface
 * shared_ref: False
 * package: inheritance
 */
class Rectangle : public virtual Parallelogram {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Rectangle(double length, double width) : Parallelogram() {
        _length = length;
        _width = width;
    };

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    double area() const override {
        return _length * _width;
    }

    double perimeter() const override {
        return 2 * (_length + _width);
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    double length() const {
        return _length;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    double width() const {
        return _width;
    }

protected:
    double _length;
    double _width;

};
// [example-end]
}
#endif