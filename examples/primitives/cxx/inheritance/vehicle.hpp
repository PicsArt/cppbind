#ifndef vehicle_hpp
#define vehicle_hpp

namespace iegen::example {

/**
 *
 * __API__
 * gen: class
 * shared_ref: True
 * package: inheritance
 * swift.include: CWrapper
 */
class Vehicle {
public:
    /**
     * __API__
     * gen: constructor
     */
    Vehicle(int numberOfSeats) : _numberOfSeats(numberOfSeats) {};

    /**
     * __API__
     * gen: getter
     */
    int numberOfSeats() const {
        return _numberOfSeats;
    };

    virtual ~Vehicle() = default;
private:
    int _numberOfSeats;
};

}
#endif