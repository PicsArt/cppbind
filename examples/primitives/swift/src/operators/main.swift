import XCTest
import Wrapper

func runOperatorExamples() {
// [counter-usage]
let counter1 = Counter(count: 1)
let counter2 = Counter(count: 2)
let counter = counter1 + counter2
assert(counter.count == 3)
assert(counter2 > counter1)
counter1 += counter2
assert(counter1.count == 3)
assert(counter1 > counter2)
// [counter-usage]

// checking == operator
let c1 = Counter(count: 1)
let c2 = Counter(count: 1)
assert(c1 == c2)
let c3 = Counter(count: 2)
assert(!(c1 == c3))

// checking a method mapped to the == operator
let pc1 = PositiveCounter(count: 5)
let pc2 = PositiveCounter(count: 5)
assert(pc1 == pc2)
let pc3 = PositiveCounter(count: 6)
assert(!(pc1 == pc3))

// [subscript-operator-usage]
var intArr = IntArrayImpl()
assert(intArr[0] == 0)
assert(intArr[9] == 9)
assert(intArr["9"] == 9)
assert(intArr[9.0] == 9)
intArr[9] = 10
assert(intArr[9] == 10)
assert(intArr["9"] == 10)
assert(intArr[9.0] == 10)
// [subscript-operator-usage]
}

#if os(Linux)
runOperatorExamples()
#elseif os(OSX)
class OperatorsTests: XCTestCase {

    func testRun() throws {
        runOperatorExamples()
    }
}
#endif
