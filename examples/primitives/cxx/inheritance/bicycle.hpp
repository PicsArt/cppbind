#ifndef bicycle_hpp
#define bicycle_hpp

#include<string>

#include "cxx/inheritance/vehicle.hpp"

namespace cppbind::example {
// [example-start]
/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 */
class Bicycle : public Vehicle {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Bicycle(int numberOfSeats) : Vehicle(numberOfSeats) {
        name = "bicycle";
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::string type() const override {
        return name;
    }

    std::string name;
};

/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 */
class ElectricBicycle : public Bicycle {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    ElectricBicycle(int numberOfSeats) : Bicycle(numberOfSeats) {
        name = "ElectricBicycle";
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * name: type
     * is_overridden: True
     */
    std::string bicycleType(){
        return name;
    }

    std::string name;
};

// [example-end]
}
#endif