package com.examples.typedefs

import com.examples.typedefs.*

fun use() {

    // test simple cases

    val q = QueueInt()
    q.push_back(1)
    q.push_back(2)
    q.push_back(3)

    assert(QueueIntUsage.getFirstElement(q) == 1)
    assert(QueueIntUsage.getLastElement(q) == 3)
    assert(QueueIntUsage.getFirstElement(QueueIntUsage.getInvQueue(listOf(1, 2))) == -1)
    assert(QueueIntUsage.getSize(q) == 3)

    val queueUsageObj = QueueIntUsage(q)
    val savedQueue = queueUsageObj.getSavedQueue()
    assert(QueueIntUsage.getFirstElement(savedQueue) == 1)
    assert(QueueIntUsage.getLastElement(savedQueue) == 3)
    assert(queueUsageObj.saved_queue.get_size() == 3)
    assert(queueUsageObj.empty_queue.get_size() == 0)

    // test shared_ref cases

    val qShared = QueueIntShared()
    qShared.push_back(1)
    qShared.push_back(2)
    qShared.push_back(3)

    assert(QueueIntSharedUsage.getFirstElement(qShared) == 1)
    assert(QueueIntSharedUsage.getLastElement(qShared) == 3)
    assert(QueueIntSharedUsage.getFirstElement(QueueIntSharedUsage.getInvQueue(listOf(1, 2))) == -1)
    assert(QueueIntSharedUsage.getSize(qShared) == 3)

    val queueSharedUsageObj = QueueIntSharedUsage(qShared)
    val savedQueueShared = queueSharedUsageObj.getSavedQueue()
    assert(QueueIntSharedUsage.getFirstElement(savedQueueShared) == 1)
    assert(QueueIntSharedUsage.getLastElement(savedQueueShared) == 3)
    assert(queueSharedUsageObj.saved_queue.get_size() == 3)

    // test template cases (FIXME: uncomment this after issue with typedef of templates is fixed for kotlin)

    // val qString = QueueString()
    // qString.push_back("a")
    // qString.push_back("b")
    // qString.push_back("c")

    // assert(QueueUsage.getFirstElement(qString) == "a")
    // assert(QueueUsage.getLastElement(qString) == "c")
    // assert(QueueUsage.getFirstElement(QueueUsage.getRevQueue(listOf("ab", "cd"))) == "ba")
    // assert(QueueUsage.getSize(qString) == 3)

    // val queueStringUsageObj = QueueUsage(qString)
    // val savedQueueString = queueStringUsageObj.getSavedQueue()
    // assert(QueueUsage.getFirstElement(savedQueueString) == "a")
    // assert(QueueUsage.getLastElement(savedQueueString) == "c")
    // assert(queueStringUsageObj.saved_queue.get_size() == 3)

}

class TypedefsApp {
    companion object {
        @JvmStatic
        fun main(args: Array<String>) {
            use()
       }
    }
}
