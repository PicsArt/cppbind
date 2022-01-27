import XCTest
import Wrapper

func runTypedefExamples() {

    let q = QueueInt()
    q.push_back(element: 1)
    q.push_back(element: 2)
    q.push_back(element: 3)

    assert(QueueIntUsage.getFirstElement(q: q) == 1)
    assert(QueueIntUsage.getLastElement(q: q) == 3)
    assert(QueueIntUsage.getFirstElement(q: QueueIntUsage.getInvQueue(v: [1, 2])) == -1)

//     let queueUsageObj = QueueIntUsage(q: q)
//     let savedQueue = queueUsageObj.getSavedQueue()
//     print(QueueIntUsage.getFirstElement(q: savedQueue))
//     print(QueueIntUsage.getLastElement(q: savedQueue))
}

#if os(Linux)
runTypedefExamples()
#elseif os(OSX)
class TypedefsTests: XCTestCase {

    func testRun() throws {
        runTypedefExamples()
    }
}
#endif
