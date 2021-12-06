import XCTest
import Wrapper

func runExtraExamples() {

    // [object-usage]
    let objUsage = ObjectUsage()
    assert(objUsage.className() == "iegen::ObjectUsage")
    assert(objUsage.equals(other: objUsage) == true)
    assert(objUsage.bytesCount() == 8)
    assert(objUsage.toString().hasSuffix("iegen::ObjectUsage>"))
    // [object-usage]
}


#if os(Linux)
runExtraExamples()
#elseif os(OSX)
class ExtraTests: XCTestCase {

    func testRun() throws {
        runExtraExamples()
    }
}
#endif
