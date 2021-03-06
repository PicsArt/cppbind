#ifndef rhombus_hpp
#define rhombus_hpp

#include <math.h>
#include "cxx/inheritance/parallelogram.hpp"

namespace cppbind::example {
// [example-start]
/**
 * __API__
 * action: gen_interface
 * shared_ref: False
 * package: inheritance
 * name: RhombusFigure
 */
class Rhombus : public virtual Parallelogram {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Rhombus(double diagonal1, double diagonal2) : Parallelogram() {
           _diagonal1 = diagonal1;
           _diagonal2 = diagonal2;
    };


    double area() const override {
        return (_diagonal1 * _diagonal2) / 2;
    }

    double perimeter() const override {
        return 2 * sqrt(_diagonal1 * _diagonal1 + _diagonal2 * _diagonal2) ;
    }


private:
    double _diagonal1;
    double _diagonal2;
};
// [example-end]
}
#endif