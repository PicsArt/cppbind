import XCTest
import Wrapper

func runOverloadExamples() {
// [overload-usage-start]
assert(Utils.sum(first: 1, second: 2) == 3)
assert(Utils.sum(first: 2.0, second: 3.0) == 5.0)

let utils = Utils()
assert(utils.concatenate(first: "1", second: "2") == "12")
assert(utils.concatenate(first: "a", second: "b", third: "c") == "abc")
// [overload-usage-end]

// [static-usage-start]
assert(Utils.minus(first: 3, second: 2) == 1)
assert(Utils.minus(first: 7.0, second: 3.0) == 4.0)
// [static-usage-end]

// overloaded methods with template arguments
let sum1 = utils.sum(first: [1, 2, 0, 0], second: [3, 4, 0, 0])
assert(sum1 == [4, 6, 0, 0])

let sum2 = utils.sum(first: [5.0, 6.0, 0.0, 0.0], second: [7.0, 8.0, 0.0, 0.0])
assert(sum2 == [12.0, 14.0, 0.0, 0.0])

// constructor overloading
let john_email = "john@email.com"
let jane = "Jane Doe"
let jane_email = "jane@email.com"

let e1 = Employee(name: jane)
assert(e1.name == jane)

let e3 = Employee(age: 20, email: john_email)
assert(e3.email == john_email)
assert(e3.age == 20)

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
