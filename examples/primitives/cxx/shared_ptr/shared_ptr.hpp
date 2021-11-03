#ifndef shared_ptr_hpp
#define shared_ptr_hpp

#include <memory>

namespace Example {
/**
 * __API__
 * action: gen_class
 * package: shared_ptr
 * shared_ref: True
 */
class Car {
    public:
   /**
    * __API__
    * action: gen_constructor
    */
    Car(int cost) : _cost(cost) {}

    Car(const Car& c) {
        _cost = c._cost;
    }

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
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void setCostWithCarSharedPtr(std::shared_ptr<Car> sp) {
        _cost = sp.get()->cost();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void setCostWithCar(Car sp) {
        _cost = sp.cost();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void setCostWithCarRef(Car& sp) {
        _cost = sp.cost();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void setCostWithCarPtr(Car* sp) {
        _cost = sp->cost();
    }

    /**
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

/**
 * __API__
 * action: gen_class
 * package: shared_ptr
 */
class CarUsage {
    public:
   /**
    * __API__
    * action: gen_constructor
    */
    CarUsage(Car* car) : _car(car) {}

    /**
     * Iegen supports only by value return in case shared_ref is set
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Car getCar() {
        return *_car;
    }

    private:
        Car* _car;
};

}

#endif
