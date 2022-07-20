import XCTest
import Wrapper

func runBasicTypesExamples() {
    // testing 'short'
    assert(add(a: 10, b: 20) == 30)
    assert(add(v: [10, 20, 30], a: 10) == [20, 30, 40])
    assert(add(p1: (1, 2), p2: (-1, -2)) == (0, 0))
}


#if os(Linux)
runBasicTypesExamples()
#elseif os(OSX)
class BasicTypesTests : XCTestCase {

    func testRun() throws {
        runBasicTypesExamples()
    }

}
#endif
