import XCTest
import Wrapper

func runEnumExamples() {
// [color-usage-start]
assert(Color.Red.rawValue == 1)
assert(Color.Blue.rawValue == 20)

assert(String(describing: Color.Blue) == "20")

let frame = Frame()
frame.backgroundColor = Color.Red
assert(frame.backgroundColor == Color.Red)

// [color-usage-end]

assert(ColorShade.ShadeLight.rawValue == 1)
assert(ColorShade.ShadeDark.rawValue == 2)
frame.backgroundColorShade = ColorShade.ShadeDark
assert(frame.backgroundColorShade == ColorShade.ShadeDark)

// checking const ref enum case
assert(frame.getNextColor(color: Color.Red) == Color.Green)

// checking `enum_case_names` variable
assert(getNextLogLevel(logLevel: LogLevel.DEBUG) == LogLevel.log_info_level)
}

#if os(Linux)
runEnumExamples()
#elseif os(OSX)
class EnumsTests: XCTestCase {

    func testRun() throws {
        runEnumExamples()
    }
}
#endif
