#ifndef queue_int_hpp
#define queue_int_hpp

#include <vector>

namespace iegen::example {

/**
 * __API__
 * action: gen_class
 * package: typedefs
 */
class QueueInt {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    QueueInt() {}

    int front() {
        return _elements[0];
    }

    int back() {
        return _elements[_elements.size() - 1];
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void push_back(int element) {
        _elements.push_back(element);
    }

private:
    std::vector<int> _elements;
};

using QueueIntType = QueueInt;
using QueueIntPtrType = QueueInt*;
using IntType = int;

/**
 * __API__
 * action: gen_class
 * package: typedefs
 */
class QueueIntUsage {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    QueueIntUsage(QueueIntPtrType q) : _saved_q(q) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static IntType getLastElement(QueueIntType* q) {
        return q->back();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static IntType getFirstElement(QueueIntPtrType q) {
        return q->front();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static QueueIntType getInvQueue(std::vector<int> v) {
        QueueIntType res_q;

        for (int i : v) {
            res_q.push_back(-i);
        }

        return res_q;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    QueueIntPtrType getSavedQueue() {
        return _saved_q;
    }

    /**
     * __API__
     * action: gen_property_getter
     */
    QueueIntType empty_queue;

    /**
     * __API__
     * action: gen_property_getter
     */
    QueueIntPtrType empty_queue_ptr = new QueueIntType;

private:
    QueueIntPtrType _saved_q;
};

}

#endif
