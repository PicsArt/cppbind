import XCTest
import Wrapper


func runSharedPtrExamples() {
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
    // [shared_ptr-usage]

    // const shared_ptr tests
    cheapCar.setCostWithCarConstSharedPtr(sp: newCar)
    assert(cheapCar.cost == newCar.cost)

    let constPtrCar = cheapCar.makeConstSharedPtr(sp: newCar)
    assert(constPtrCar.cost == newCar.cost)
}

#if os(Linux)
runSharedPtrExamples()
#elseif os(OSX)
class SharedPtrTests: XCTestCase {

    func testRun() throws {
        runSharedPtrExamples()
    }
}
#endif
