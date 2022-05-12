#ifndef square_hpp
#define square_hpp

#include <math.h>
#include "cxx/inheritance/rhombus.hpp"
#include "cxx/inheritance/rectangle.hpp"

namespace cppbind::example {
// [example]
/**
 * __API__
 * action: gen_class
 * shared_ref: False
 * package: inheritance
 */
class Square final : public Rhombus, public Rectangle {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     *
     */
    Square(double side) : Rhombus(side * sqrt(2), side * sqrt(2)), Rectangle(side, side) {};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    double area() const override {
        return Rectangle::area();
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    double perimeter() const override {
        return Rectangle::perimeter();
    };

};
// [example]
}
#endif