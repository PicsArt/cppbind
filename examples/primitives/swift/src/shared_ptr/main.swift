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

    // testing multiple inheritance without single root in case of shared_ref=True
    var symbolUsageObj = SymbolUsageShared()
    let digitObj = DigitShared()
    let textObj = TextShared()
    let signObj = SignSharedImpl()

    // test virtual methods
    assert(symbolUsageObj.getTextType(t: digitObj) == "digit")
    assert(symbolUsageObj.getTextType(t: textObj) == "text")
    assert(symbolUsageObj.getSignType(s: digitObj) == "digit")
    assert(symbolUsageObj.getSignType(s: signObj) == "sign")
    assert(digitObj.typeName() == "digit")
    assert(textObj.typeName() == "text")
    assert(signObj.typeName() == "sign")

    symbolUsageObj = SymbolUsageShared(d: digitObj)
    assert(symbolUsageObj.getTextPtr().typeName() == "digit")
    assert(symbolUsageObj.getSignPtr().typeName() == "digit")

    // test members
    assert(symbolUsageObj.getTextId(t: digitObj) == 2)
    assert(symbolUsageObj.getTextId(t: textObj) == 2)
    assert(symbolUsageObj.getSignId(s: digitObj) == 1)
    assert(symbolUsageObj.getSignId(s: signObj) == 1)

    // test return object correct casting
    assert(symbolUsageObj.getTextId(t: symbolUsageObj.getTextPtr()) == 2)
    assert(symbolUsageObj.getSignId(s: symbolUsageObj.getSignPtr()) == 1)
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
