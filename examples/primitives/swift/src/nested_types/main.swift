import XCTest
import Wrapper

func runNestedTypeExamples() {
// [nested-types-usage]
let value1 = List.Item.Value(value: 1)
let value2 = List.Item.Value(value: 3)
print(value1.value)

let item1 = List.Item(v: value1)
let item2 = List.Item(v: value2)

let list = List()

list.push_back(item: item1)
print(list.back.value.value)
print(value1.value)
assert(list.back.value.value == value1.value)

list.push_back(item: item2)
assert(list.back.value.value == value2.value)

list.pop_back()
assert(list.back.value.value == value1.value)

// [nested-types-usage]
}

#if os(Linux)
runNestedTypeExamples()
#elseif os(OSX)
class NestedTypeTests: XCTestCase {

    func testRun() throws {
        runNestedTypeExamples()
    }
}
#endif
