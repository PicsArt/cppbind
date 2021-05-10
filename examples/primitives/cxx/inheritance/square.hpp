#ifndef square_hpp
#define square_hpp

#include <math.h>
#include "cxx/inheritance/rhombus.hpp"
#include "cxx/inheritance/rectangle.hpp"

namespace iegen::example {
// [example]
/**
 * __API__
 * gen: class
 * shared_ref: False
 * package: inheritance
 * swift.include: CWrapper
 * python.include: inheritance.rhombus_pygen
 * python.include: inheritance.rectangle_pygen
 */
class Square final : public Rhombus, public Rectangle {
public:
    /**
     * __API__
     * gen: constructor
     *
     */
    Square(double side) : Rhombus(side * sqrt(2), side * sqrt(2)), Rectangle(side, side) {};

    /**
     * __API__
     * gen: getter
     */
    double area() const override {
        return Rectangle::area();
    };

    /**
     * __API__
     * gen: method
     */
    double perimeter() const override {
        return Rectangle::perimeter();
    };

};
// [example]
}
#endif