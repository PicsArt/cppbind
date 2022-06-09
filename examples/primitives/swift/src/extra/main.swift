import XCTest
import Wrapper

func runExtraExamples() {

    // [object-usage]
    let objUsage = ObjectUsage()
    assert(objUsage.className() == "cppbind::ObjectUsage")
    assert(objUsage == objUsage)
    assert(objUsage.bytesCount() == 8)
    assert(String(describing: objUsage).hasSuffix("cppbind::ObjectUsage>"))
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
