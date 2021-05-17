#ifndef rhombus_hpp
#define rhombus_hpp

#include <math.h>
#include "cxx/inheritance/parallelogram.hpp"

namespace iegen::example {

/**
 * __API__
 * gen: interface
 * shared_ref: False
 * package: inheritance
 * swift.include: CWrapper
 * python.include: inheritance.parallelogram_pygen
 */
class Rhombus : public virtual Parallelogram {
public:
    /**
     * __API__
     * gen: constructor
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

}
#endif