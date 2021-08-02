#ifndef shared_ptr_hpp
#define shared_ptr_hpp

#include <memory>

namespace Example {
/**
 * comments
 *
 * __API__
 * action: gen_class
 * package: shared_ptr
 * shared_ref: True
 */
class Car {
    public:
    /**
    * comments
    *
    * __API__
    * action: gen_constructor
    */
    Car(int cost) : _cost(cost) {}
    /**
    * value getter
    *__API__
    * action: gen_getter
    * throws: no_throw
    */
    const int& cost() {
        return _cost;
    }

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void setCostWithCarSharedPtr(std::shared_ptr<Car> sp) {
        _cost = sp.get()->cost();
    }
    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::shared_ptr<Car> getNewCarSharedPtr() {
        Car* car = new Car(_cost);
        std::shared_ptr<Car> sp(car);
        return sp;
    }

    private:
        int _cost;
};
}

#endif