#ifndef inheritance_usage_hpp
#define inheritance_usage_hpp

#include <math.h>
#include <memory>
#include "cxx/inheritance/parallelogram.hpp"
#include "cxx/inheritance/vehicle.hpp"
#include "cxx/inheritance/bicycle.hpp"

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * shared_ref: False
 * package: inheritance
 */
class GeometricFigure {
public:

    /**
     * __API__
     * action: gen_constructor
     */
    GeometricFigure(Parallelogram * p) : _parallelogram(p) {};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    Parallelogram * parallelogram() {
        return _parallelogram;
    };

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     */
    void setParallelogram(Parallelogram * p) {
        _parallelogram = p;
    };

private:
    Parallelogram * _parallelogram;
};


/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 */
class MyVehicle {
public:

    /**
     * __API__
     * action: gen_constructor
     */
    MyVehicle(const std::shared_ptr<Vehicle> & v) : _vehicle(v) {};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const std::shared_ptr<Vehicle> & vehicle() {
        return _vehicle;
    };

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     */
    void setVehicle(const std::shared_ptr<Vehicle> &  v) {
        _vehicle = v;
    };

private:
   std::shared_ptr<Vehicle> _vehicle;
};


/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 */
class MyBicycle {
public:

    /**
     * __API__
     * action: gen_constructor
     */
    MyBicycle(const std::shared_ptr<Bicycle> & b) : _bicycle(b) {};


    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const std::shared_ptr<const Bicycle>& bicycle() {
        return _bicycle;
    };

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     */
    void setBicycle(const std::shared_ptr<const Bicycle> &  b) {
        _bicycle = b;
    };


private:
   std::shared_ptr<const Bicycle> _bicycle;
};


// [example]
}
#endif