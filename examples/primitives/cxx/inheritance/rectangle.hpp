#ifndef rectangle_hpp
#define rectangle_hpp
#include "cxx/inheritance/parallelogram.hpp"

namespace iegen::example {
// [example]
/**
 * __API__
 * gen: interface
 * shared_ref: False
 * package: inheritance
 * swift.include: CWrapper
 * python.include: inheritance.parallelogram_pygen
 */
class Rectangle : public virtual Parallelogram {
public:
    /**
     * __API__
     * gen: constructor
     */
    Rectangle(double length, double width) : Parallelogram() {
        _length = length;
        _width = width;
    };

    /**
     * __API__
     * gen: getter
     * throws: no_throw
     */
    double area() const override {
        return _length * _width;
    }

    /**
     * __API__
     * gen: method
     * throws: no_throw
     */
    double perimeter() const override {
        return 2 * (_length + _width);
    }

    /**
     * __API__
     * gen: getter
     * throws: no_throw
     */
    double length() const {
        return _length;
    }

    /**
     * __API__
     * gen: getter
     * throws: no_throw
     */
    double width() const {
        return _width;
    }

protected:
    double _length;
    double _width;

};
// [example]
}
#endif