import XCTest
import Wrapper

func runNullableExamples() {
    // [nullables-usage]
    let n1 = NumInt(val_: 1)
    let n2 = NumInt(val_: 2)

    var res1 = NullableUtils.max(first: n1, second: n2)
    assert(res1!.value == n2.value)

    let d1 = NumDouble(val_: 1.0)
    let d2 = NumDouble(val_: 2.0)

    var res2 = NullableUtils.max(first: d1, second: d2)
    assert(res2!.value == d2.value)

    res2 = NullableUtils.max(first: nil, second: d2)
    assert(res2 == nil)

    // incorrect example for swift
    // res1 = NullableUtils.max(first: nil, second: nil)
    // assert(res1 == nil)

    // negative examples
    // NullableUtils.checkNonnullArg(number: nil)

    // nullable getter/setter
    let utils = NullableUtils(num: d1)
    assert(utils.nullable!.value == d1.value)
    utils.nullable = nil


    // nullable property getter/setter
    assert(utils.numDouble == nil)
    utils.numDouble = d2
    assert(utils.numDouble!.value == d2.value)

    // negative examples
    // utils.numInt = nil

    // [nullables-usage]
}


#if os(Linux)
runNullableExamples()
#elseif os(OSX)
class NullablesTests: XCTestCase {

    func testRun() throws {
        runNullableExamples()
    }
}
#endif
