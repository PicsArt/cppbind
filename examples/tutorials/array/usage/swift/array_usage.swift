import XCTest
import Wrapper

func runArrayTests() {

    let array = Array()

    assert(array.empty)

    array.push_back(element: 0)
    array.push_back(element: 1)
    array.push_back(element: 2)

    assert(!array.empty)
    assert(array.size == 3)
    assert(array.front() == 0)
    assert(array.back() == 2)
    assert(array[1] == 1)

    do {
        let _ = try array.at(i: 5)
        assert(false)
    } catch is StdOutOfRange {
    } catch {
        assert(false)
    }

}

#if os(Linux)
runArrayTests()
#elseif os(OSX)
class ArrayTests: XCTestCase {
    func testRun() throws {
        runArrayTests()
    }
}
#endif
