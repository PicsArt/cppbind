import Wrapper


// [optionals-usage]
let op = Optionals()

// default value assertions
assert(op.optionalPtrWithNullptrDefault() == nil)
assert(op.optionalFDPtrWithNullptrDefault() == nil)
assert(op.optionalIntWithDefault() == 5)
assert(op.optionalLongWithDefault() == 7)
assert(op.optionalDoubleWithDefault() == 9.0)
assert(op.optionalFloatWithDefault() == 11.0)
assert(op.optionalBoolWithDefault() == true)
assert(op.optionalStringWithDefault() == "abc")
// // TODO add char converter
// assert(op.optionalCharWithDefault() == ',')
assert(op.optionalCharPointerWithDefault() == "def")
assert(op.optionalSharedPtrWithNullptrDefault() == nil)
assert(op.optionalEnumWithDefault() == Color.Red)
//
// // non default value assertions
let task = Task(title: "my task")
assert(op.optionalPtrWithNullptrDefault(task: task)!.cself == task.cself)
assert(op.optionalEnumWithDefault(c: Color.Blue) == Color.Blue)
assert(op.optionalBoolWithDefault(value: false) == false)
// TODO add char converter
// assert(op.optionalCharWithDefault(symbol: ':') == ':')
assert(op.optionalLongWithDefault(value: 8) == 8)
assert(op.optionalFloatWithDefault(value: 5.0) == 5.0)
assert(op.optionalCharPointerWithDefault(optionalStr: "val") == "val")
// // [optionals-usage]
