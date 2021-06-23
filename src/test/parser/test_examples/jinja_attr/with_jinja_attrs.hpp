#include <memory>

namespace Example {
/**
 * comments
 *
 * __API__
 * action: gen_class
 * package: pkg
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
    * action: gen_constructor
    */
    Car(int cost) : _cost(cost) {}

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws:
     *   - '{{package}}_exc_1'
     *   - '{{package}}_exc_2'
     * name: >
     *   {%- if shared_ref -%}
     *     {{package}}_shared
     *   {%- else -%}
     *     {{package}}_non_shared
     *   {%- endif -%}
     */
    std::shared_ptr<Car> getNewCarSharedPtr() {
        Car* car = new Car(_cost);
        std::shared_ptr<Car> sp(car);
        return sp;
    }

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     * template:
     *   T:
     *     - type: '{{package}}Int'
     *     - type: '{{package}}Double'
     */
     template <typename T>
     void noop() {
     }

    private:
        int _cost;
};
}
