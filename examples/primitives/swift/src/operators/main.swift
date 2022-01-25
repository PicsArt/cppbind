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
