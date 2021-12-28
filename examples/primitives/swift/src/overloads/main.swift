import XCTest
import Wrapper

func runOverloadExamples() {
    // [overload-usage]
    assert(Utils.sum(first: 1, second: 2) == 3)
    assert(Utils.sum(first: 2.0, second: 3.0) == 5.0)

    let utils = Utils()
    assert(utils.concatenate(first: "1", second: "2") == "12")
    assert(utils.concatenate(first: "a", second: "b", third: "c") == "abc")

    assert(Utils.minus(first: 3, second: 2) == 1)
    assert(Utils.minus(first: 7.0, second: 3.0) == 4.0)

    // constructor overloading
    let john_email = "john@email.com"
    let jane = "Jane Doe"
    let jane_email = "jane@email.com"

    let e1 = Employee(name: jane)
    assert(e1.name == jane)

    let e3 = Employee(age: 20, email: john_email)
    assert(e3.email == john_email)
    assert(e3.age == 20)

    // [overload-usage]


    e3.setData(name: jane, age: 21, email: jane_email)
    assert(e3.email == jane_email)
    assert(e3.age == 21)
    assert(e3.name == jane)

    e3.setData(age: 22)
    assert(e3.age == 22)


    // TODO: uncomment after adding defaults support for swift
    // example with default value
    /*let e4 = Employee(age: 20)
    assert(e4.email == "")

    // method overloading, with default values
    e4.setData(name: jane, email: 21)
    assert(e4.email == "")
    assert(e4.age == 21)
    assert(e4.name == jane)*/

}

#if os(Linux)
runOverloadExamples()
#elseif os(OSX)
class OverloadsTests: XCTestCase {
    func testRun() throws {
        runOverloadExamples()
    }
}
#endif
