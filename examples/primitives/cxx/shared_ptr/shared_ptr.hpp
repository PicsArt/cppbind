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
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Car getCar() {
        return *_car;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Car* getCarPtr() {
        return _car;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Car& getCarRef() {
        return *_car;
    }

    private:
        Car* _car;
};

/**
 * __API__
 * action: gen_class
 * package: shared_ptr
 * shared_ref: True
 */
class Plane : public std::enable_shared_from_this<Plane> {
    public:
   /**
    * __API__
    * action: gen_constructor
    */
    Plane(int seats) : _seats(seats) {}

   /**
    * value getter
    *__API__
    * action: gen_getter
    * throws: no_throw
    */
    const int& seats() {
        return _seats;
    }

    private:
        int _seats;
};

/**
 * __API__
 * action: gen_class
 * package: shared_ptr
 */
class PlaneUsage {
    public:
   /**
    * __API__
    * action: gen_constructor
    */
    PlaneUsage(Plane* plane) : _plane(plane) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Plane getPlane() {
        return *_plane;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Plane* getPlanePtr() {
        return _plane;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Plane& getPlaneRef() {
        return *_plane;
    }

    private:
        Plane* _plane;
};

}

#endif
