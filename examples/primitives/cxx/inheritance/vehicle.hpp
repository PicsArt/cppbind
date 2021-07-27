#ifndef vehicle_hpp
#define vehicle_hpp

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 */
class Vehicle {
public:
    /**
     * __API__
     * action: gen_constructor
     */
    Vehicle(int numberOfSeats) : _numberOfSeats(numberOfSeats) {};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    int numberOfSeats() const {
        return _numberOfSeats;
    };

    virtual ~Vehicle() = default;
private:
    int _numberOfSeats;
};
// [example]
}
#endif