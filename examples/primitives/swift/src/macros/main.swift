import XCTest
import Wrapper

func runMacrosExamples() {
// [macros-usage-start]
assert(mulD(a: 2.0, b: 5.0) == 10.0)
assert(mulL(a: 4, b: 5) == 20)
// [macros-usage-end]
}

#if os(Linux)
runMacrosExamples()
#elseif os(OSX)
class InheritanceTests: XCTestCase {

    func testRun() throws {
        runMacrosExamples()
    }
}
#endif
