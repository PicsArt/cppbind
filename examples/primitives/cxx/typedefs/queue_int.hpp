#ifndef queue_int_hpp
#define queue_int_hpp

#include <vector>
#include <string>

using String = std::string;

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

    int front() const {
        return _elements[0];
    }

    int back() const {
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

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void push_back_from_str(String element) {
        _elements.push_back(std::stoi(element));
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    int get_size() const {
        return _elements.size();
    }

private:
    std::vector<int> _elements;
};

using QueueIntType = QueueInt;
using QueueIntPtrType = QueueInt*;
using ConstQueueIntType = const QueueInt;
using IntType = int;
using ConstIntType = const int;

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
    QueueIntUsage(QueueIntPtrType q) : saved_queue(q) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static ConstIntType getSize(ConstQueueIntType q) {
        return q.get_size();
    }

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
     * return_value_policy: reference
     */
    QueueIntPtrType getSavedQueue() {
        return saved_queue;
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
    QueueIntPtrType saved_queue;
};

}

#endif
