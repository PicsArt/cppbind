#ifndef queue_template_hpp
#define queue_template_hpp

#include <vector>
#include <string>

namespace iegen::example {

/**
 * __API__
 * action: gen_class
 * package: typedefs
 * template:
 *   T:
 *     - type: std::string
 */
template <class T>
class Queue {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Queue() {}

    T front() const {
        return _elements[0];
    }

    T back() const {
        return _elements[_elements.size() - 1];
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void push_back(T element) {
        _elements.push_back(element);
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
    std::vector<T> _elements;
};

using QueueStdStringType = Queue<std::string>;
using QueueStdStringPtrType = Queue<std::string>*;
using ConstQueueStdStringType = const Queue<std::string>;
using StdStringType = std::string;
using ConstStdStringType = const std::string;
using VectorOfStringsType = std::vector<std::string>;

/**
 * __API__
 * action: gen_class
 * package: typedefs
 */
class QueueUsage {
public:
    /**
     * We don't have support for `Queue<StdStringType>` specification since we don't have mechanism for `canonical_type` deduction for strings
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    QueueUsage(QueueStdStringPtrType q) : saved_queue(q) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static int getSize(QueueStdStringType q) {
        return q.get_size();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static StdStringType getLastElement(QueueStdStringPtrType q) {
        return q->back();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static ConstStdStringType getFirstElement(ConstQueueStdStringType q) {
        return q.front();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static QueueStdStringType getRevQueue(VectorOfStringsType v) {
        QueueStdStringType res_q;

        for (StdStringType s : v) {
            reverse(s.begin(), s.end());
            res_q.push_back(s);
        }

        return res_q;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    QueueStdStringPtrType getSavedQueue() {
        return saved_queue;
    }

    /**
     * __API__
     * action: gen_property_getter
     */
    QueueStdStringType empty_queue;

    /**
     * __API__
     * action: gen_property_getter
     */
    QueueStdStringPtrType saved_queue;
};

}

#endif
