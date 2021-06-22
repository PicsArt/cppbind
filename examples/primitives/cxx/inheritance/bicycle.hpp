#ifndef bicycle_hpp
#define bicycle_hpp

#include "cxx/inheritance/vehicle.hpp"

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * shared_ref: False
 * package: inheritance
 * swift.include: CWrapper
 * python.include: inheritance.vehicle_pygen
 */
class Bicycle : public Vehicle {
public:
    /**
     * __API__
     * action: gen_constructor
     */
    Bicycle(int numberOfSeats) : Vehicle(numberOfSeats) {};
};
// [example]
}
#endif