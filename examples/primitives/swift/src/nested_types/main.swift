import XCTest
import Wrapper

func runNestedTypeExamples() {
// [nested-types-usage-start]
let value1 = List.Item.Value(value: 1)
let value2 = Value(value: 3)

let item1 = List.Item(v: value1)
let item2 = Item(v: value2)

let list = List()

list.push_back(item: item1)
assert(list.back.value.value == value1.value)

list.push_back(item: item2)
assert(list.back.value.value == value2.value)

list.pop_back()
assert(list.back.value.value == value1.value)

let listWrapper = ListWrapper()
listWrapper.push_back(item: item1)
assert(listWrapper.back.value.value == item1.value.value)

// [nested-types-usage-end]

let intListItemWrapper = IntListItemWrapper()
let intItem = TemplateListInt.Item(v: 5)
intListItemWrapper.set(item: intItem)
let retIntItem = intListItemWrapper.get()
assert(retIntItem.value == 5)
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
