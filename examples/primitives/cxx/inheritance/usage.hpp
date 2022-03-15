#ifndef inheritance_usage_hpp
#define inheritance_usage_hpp

#include <math.h>
#include <memory>
#include <vector>
#include "cxx/inheritance/parallelogram.hpp"
#include "cxx/inheritance/vehicle.hpp"
#include "cxx/inheritance/bicycle.hpp"
#include "cxx/inheritance/date.hpp"

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
     * throws: no_throw
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
     * action: gen_getter
     * throws: no_throw
     * nullable_return: True
     */
    Parallelogram * nullableParallelogram() {
        return _nullableParallelogram;
    };

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     * nullable_arg: p
     */
    void setNullableParallelogram(Parallelogram * p) {
        _nullableParallelogram = p;
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
    Parallelogram * _nullableParallelogram;
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
     * throws: no_throw
     */
    MyVehicle(std::shared_ptr<Vehicle> v, std::shared_ptr<const Vehicle> cv) : _vehicle(v), _const_vehicle(cv) {};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     * nullable_return: True
     */
    std::shared_ptr<Vehicle> vehicle() {
        return _vehicle;
    };

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     */
    void setVehicle(std::shared_ptr<Vehicle> v) {
        _vehicle = v;
    };

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     * nullable_return: True
     */
    std::shared_ptr<const Vehicle> constVehicle() {
        return _const_vehicle;
    };

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     */
    void setConstVehicle(std::shared_ptr<const Vehicle> v) {
        _const_vehicle = v;
    };

private:
   std::shared_ptr<Vehicle> _vehicle;
   std::shared_ptr<const Vehicle> _const_vehicle;
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
     * throws: no_throw
     */
    MyBicycle(std::shared_ptr<Bicycle> b) : _bicycle(b) {};


    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    std::shared_ptr<const Bicycle> bicycle() {
        return _bicycle;
    };

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     */
    void setBicycle(std::shared_ptr<const Bicycle>  b) {
        _bicycle = b;
    };


private:
   std::shared_ptr<const Bicycle> _bicycle;
};

/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 */
class MyCalendar {
public:

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    MyCalendar(const std::vector<std::shared_ptr<Date>>& events) : _events(events) {};


    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void addEvent(std::shared_ptr<Date> e) {
        _events.push_back(e);
    };

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const std::vector<std::shared_ptr<Date>>& events() {
        return _events;
    };

private:
   std::vector<std::shared_ptr<Date>> _events;
};


// [example]
}
#endif