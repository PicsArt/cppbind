#ifndef inherit_car_hpp
#define inherit_car_hpp

#include <string>

#include "cxx/inheritance/vehicle.hpp"

namespace iegen::example {
// [example]

class Car : public Vehicle {
public:

    Car(int numberOfSeats) : Vehicle(numberOfSeats) {};
};


/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 */
class MyCar : public Car {
public:

     /**
     * __API__
     * action: gen_constructor
     */
    MyCar(int numberOfSeats) : Car(numberOfSeats) {
        name = "mycar";
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
// [example]
}
#endif
