from examples_lib.shared_ptr.shared_ptr_pygen import Car

cheap_car = Car(1000)
expensive_car = Car(2000)
new_car = cheap_car.get_new_car_shared_ptr()
assert new_car.cost == cheap_car.cost

cheap_car.set_cost_with_car_shared_ptr(expensive_car)
assert cheap_car.cost == expensive_car.cost

car1 = Car(10000)
cheap_car.set_cost_with_car(car1)
assert cheap_car.cost == car1.cost

car2 = Car(20000)
cheap_car.set_cost_with_car_ref(car2)
assert cheap_car.cost == car2.cost

car3 = Car(30000)
cheap_car.set_cost_with_car_ptr(car3)
assert cheap_car.cost == car3.cost
