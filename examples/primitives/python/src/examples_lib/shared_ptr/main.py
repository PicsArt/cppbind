from examples_lib.shared_ptr.shared_ptr_pygen import Car, CarUsage
from examples_lib.shared_ptr.shared_ptr_symbol_pygen import (
    SymbolUsageShared,
    DigitShared,
    TextShared,
    SignShared
)

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

car_usage_obj = CarUsage(cheap_car)
returned_car = car_usage_obj.get_car()
assert(returned_car.cost == cheap_car.cost)

# testing multiple inheritance without single root in case of shared_ref=True
symbol_usage_obj = SymbolUsageShared()
digit_obj = DigitShared()
text_obj = TextShared()
sign_obj = SignShared()

# test virtual methods
assert symbol_usage_obj.get_text_type(digit_obj) == "digit"
assert symbol_usage_obj.get_text_type(text_obj) == "text"
assert symbol_usage_obj.get_sign_type(digit_obj) == "digit"
assert symbol_usage_obj.get_sign_type(sign_obj) == "sign"
assert digit_obj.type_name() == "digit"
assert text_obj.type_name() == "text"
assert sign_obj.type_name() == "sign"

symbol_usage_obj = SymbolUsageShared(digit_obj)
assert symbol_usage_obj.get_text_ptr().type_name() == "digit"
assert symbol_usage_obj.get_sign_ptr().type_name() == "digit"

# test members
assert symbol_usage_obj.get_text_id(digit_obj) == 2
assert symbol_usage_obj.get_text_id(text_obj) == 2
assert symbol_usage_obj.get_sign_id(digit_obj) == 1
assert symbol_usage_obj.get_sign_id(sign_obj) == 1

# test return object correct casting
assert symbol_usage_obj.get_text_id(symbol_usage_obj.get_text_ptr()) == 2
assert symbol_usage_obj.get_sign_id(symbol_usage_obj.get_sign_ptr()) == 1
