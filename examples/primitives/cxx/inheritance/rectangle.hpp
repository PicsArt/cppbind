#ifndef rectangle_hpp
#define rectangle_hpp

#include <string>
#include <iostream>

#include "cxx/inheritance/parallelogram.hpp"

namespace iegen::example {

/**
 *
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
     *
     * __API__
     * gen: constructor
     *
     */
    Rectangle(double length, double width) : Parallelogram() {
        _length = length;
        _width = width;
    };

    /**
     *
     * __API__
     * gen: getter
     *
     */
    double area() const override {
        return _length * _width;
    }

    /**
     *
     * __API__
     * gen: method
     *
     */
    double perimeter() const override {
        return 2 * (_length + _width);
    }

    /**
     *
     * __API__
     * gen: getter
     *
     */
    double length() const {
        return _length;
    }

    /**
     * comments
     *
     * __API__
     * gen: getter
     *
     */
    double width() const {
        return _width;
    }

protected:
    double _length;
    double _width;

};

}
#endif