import Wrapper

// [shared_ptr-usage]
let cheapCar = Car(cost: 1000)
let expensiveCar = Car(cost: 100000)
let newCar = cheapCar.getNewCarSharedPtr()
assert(newCar.cost == cheapCar.cost)

cheapCar.setCostWithCarSharedPtr(sp: expensiveCar)
assert(cheapCar.cost == expensiveCar.cost)
// [shared_ptr-usage]
