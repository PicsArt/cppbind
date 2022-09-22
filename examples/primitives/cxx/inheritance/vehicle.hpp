#ifndef vehicle_hpp
#define vehicle_hpp

#include<string>

namespace cppbind::example {
// [example-start]
/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 */
class Vehicle {
public:

    Vehicle(int numberOfSeats) : _numberOfSeats(numberOfSeats) {};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    int numberOfSeats() const {
        return _numberOfSeats;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     virtual std::string type() const = 0;

     virtual ~Vehicle() = default;
private:
    int _numberOfSeats;
};
// [example-end]
}
#endif