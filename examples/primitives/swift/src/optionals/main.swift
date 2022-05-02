import XCTest
import Wrapper

func runOptionalExamples() {
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
    assert(op.optionalStringViewWithDefault() == "abc")
    assert(op.optionalCharWithDefault() == ",")
    assert(op.optionalUnsignedCharWithDefault() == 100)
    assert(op.optionalCharPointerWithDefault() == "def")
    assert(op.optionalSharedPtrWithNullptrDefault() == nil)
    assert(op.optionalEnumWithDefault() == Color.Red)
    assert(op.optionalEnumWithDefaultAndFieldPrefix() == ColorShade.ShadeLight)

    // non default value assertions
    let task = Task(title: "my task")
    assert(op.optionalPtrWithNullptrDefault(task: task)!.equals(t: task))
    assert(op.optionalEnumWithDefault(c: Color.Blue) == Color.Blue)
    assert(op.optionalEnumWithDefaultAndFieldPrefix(c: ColorShade.ShadeDark) == ColorShade.ShadeDark)
    assert(op.optionalEnumWithInternalDefault(c: ColorShade.ShadeLight) == ColorShade.ShadeLight)
    assert(op.optionalBoolWithDefault(value: false) == false)
    assert(op.optionalStringViewWithDefault(optionalStr: "test") == "test")
    assert(op.optionalCharWithDefault(symbol: ":") == ":")
    assert(op.optionalUnsignedCharWithDefault(num: 200) == 200)
    assert(op.optionalLongWithDefault(value: 8) == 8)
    assert(op.optionalFloatWithDefault(value: 5.0) == 5.0)
    assert(op.optionalCharPointerWithDefault(optionalStr: "val") == "val")

    /// multiple default values with complex and non-complex values
    assert(op.multipleMixedDefaultValues() == "DefaultTask1DefaultRoot")
    assert(op.multipleMixedDefaultValues(task: Task(title: "ABC")) == "ABC1DefaultRoot")
    assert(op.multipleMixedDefaultValues(task: Task(title: "ABC"), i: 2) == "ABC2DefaultRoot")
    assert(op.multipleMixedDefaultValues(task: Task(title: "ABC"), r: Root(path: "Path") ) == "ABC1Path")
    assert(op.multipleMixedDefaultValues(task: Task(title: "ABC"), i: 2, r: Root(path: "Path") ) == "ABC2Path")
    // // [optionals-usage]
}


#if os(Linux)
runOptionalExamples()
#elseif os(OSX)
class OptionalsTests: XCTestCase {
    func testRun() throws {
        runOptionalExamples()
    }
}
#endif
