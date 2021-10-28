import Wrapper

// [shared_ptr-usage]
let cheapCar = Car(cost: 1000)
let expensiveCar = Car(cost: 100000)
let newCar = cheapCar.getNewCarSharedPtr()
assert(newCar.cost == cheapCar.cost)

cheapCar.setCostWithCarSharedPtr(sp: expensiveCar)
assert(cheapCar.cost == expensiveCar.cost)

let car1 = Car(cost: 10000)
cheapCar.setCostWithCar(sp: car1)
assert(cheapCar.cost == car1.cost)

let car2 = Car(cost: 20000)
cheapCar.setCostWithCarRef(sp: car2)
assert(cheapCar.cost == car2.cost)

let car3 = Car(cost: 30000)
cheapCar.setCostWithCarPtr(sp: car3)
assert(cheapCar.cost == car3.cost)

let carUsageObj = CarUsage(car: cheapCar)

let returnedCar = carUsageObj.getCar()
assert(returnedCar.cost == cheapCar.cost)

let returnedCarPtr = carUsageObj.getCarPtr()
assert(returnedCarPtr.cost == cheapCar.cost)

let returnedCarRef = carUsageObj.getCarRef()
assert(returnedCarRef.cost == cheapCar.cost)

let plane = Plane(seats: 100)
let planeUsageObj = PlaneUsage(plane: plane)

let returnedPlane = planeUsageObj.getPlane()
assert(returnedPlane.seats == plane.seats)

let returnedPlanePtr = planeUsageObj.getPlanePtr()
assert(returnedPlanePtr.seats == plane.seats)

let returnedPlaneRef = planeUsageObj.getPlaneRef()
assert(returnedPlaneRef.seats == plane.seats)

// [shared_ptr-usage]
