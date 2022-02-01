import XCTest
import Wrapper

func runTypedefExamples() {
    //  test simple cases

    let q = QueueInt()
    q.push_back(element: 1)
    q.push_back(element: 2)
    q.push_back(element: 3)

    assert(QueueIntUsage.getFirstElement(q: q) == 1)
    assert(QueueIntUsage.getLastElement(q: q) == 3)
    assert(QueueIntUsage.getFirstElement(q: QueueIntUsage.getInvQueue(v: [1, 2])) == -1)
    assert(QueueIntUsage.getSize(q: q) == 3)

    let queueUsageObj = QueueIntUsage(q: q)
    let savedQueue = queueUsageObj.getSavedQueue()
    assert(QueueIntUsage.getFirstElement(q: savedQueue) == 1)
    assert(QueueIntUsage.getLastElement(q: savedQueue) == 3)
    assert(queueUsageObj.saved_queue.get_size() == 3)
    assert(queueUsageObj.empty_queue.get_size() == 0)

    // test shared_ref cases

    let qShared = QueueIntShared()
    qShared.push_back(element: 1)
    qShared.push_back(element: 2)
    qShared.push_back(element: 3)

    assert(QueueIntSharedUsage.getFirstElement(q: qShared) == 1)
    assert(QueueIntSharedUsage.getLastElement(q: qShared) == 3)
    assert(QueueIntSharedUsage.getFirstElement(q: QueueIntSharedUsage.getInvQueue(v: [1, 2])) == -1)
    assert(QueueIntSharedUsage.getSize(q: qShared) == 3)

    let queueSharedUsageObj = QueueIntSharedUsage(q: qShared)
    let savedQueueShared = queueSharedUsageObj.getSavedQueue()
    assert(QueueIntSharedUsage.getFirstElement(q: savedQueueShared) == 1)
    assert(QueueIntSharedUsage.getLastElement(q: savedQueueShared) == 3)
    assert(queueSharedUsageObj.saved_queue.get_size() == 3)

    // test template cases

    let qString = QueueString()
    qString.push_back(element: "a")
    qString.push_back(element: "b")
    qString.push_back(element: "c")

    assert(QueueUsage.getFirstElement(q: qString) == "a")
    assert(QueueUsage.getLastElement(q: qString) == "c")
    assert(QueueUsage.getFirstElement(q: QueueUsage.getRevQueue(v: ["ab", "cd"])) == "ba")
    assert(QueueUsage.getSize(q: qString) == 3)

    let queueStringUsageObj = QueueUsage(q: qString)
    let savedQueueString = queueStringUsageObj.getSavedQueue()
    assert(QueueUsage.getFirstElement(q: savedQueueString) == "a")
    assert(QueueUsage.getLastElement(q: savedQueueString) == "c")
    assert(queueStringUsageObj.saved_queue.get_size() == 3)

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
