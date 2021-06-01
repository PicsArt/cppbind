#include <memory>

namespace Example {
/**
 * comments
 *
 * __API__
 * gen: class
 * package: main_pkg
 * linux.swift.include: linux_CWrapper
 * mac.include: mac_CWrapper
 * shared_ref: True
 */
class Car {
    public:
    /**
    * comments
    *
    * __API__
    * gen: constructor
    */
    Car(int cost) : _cost(cost) {}

    /**
     * comments
     *
     * __API__
     * gen: method
     * throws: '{{package}}_exc'
     * name: >
     *   {%- if shared_ref -%}
     *     {{package}}_nonshared
     *   {%- else -%}
     *     {{package}}_shared
     *   {%- endif -%}
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
