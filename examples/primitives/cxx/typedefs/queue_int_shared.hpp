#ifndef queue_int_shared_hpp
#define queue_int_shared_hpp

#include <vector>
#include <memory>

namespace cppbind::example {

/**
 * __API__
 * action: gen_class
 * package: typedefs
 * shared_ref: True
 */
class QueueIntShared {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    QueueIntShared() {}

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
    const int get_size() const {
        return _elements.size();
    }

private:
    std::vector<int> _elements;
};

using SharedPtrOfQueueIntSharedType = std::shared_ptr<QueueIntShared>;
using ConstSharedPtrOfQueueIntSharedType = const std::shared_ptr<QueueIntShared>;
using SharedPtrOfConstQueueIntSharedType = std::shared_ptr<const QueueIntShared>;

/**
 * __API__
 * action: gen_class
 * package: typedefs
 */
class QueueIntSharedUsage {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    QueueIntSharedUsage(SharedPtrOfQueueIntSharedType q) : saved_queue(q) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static const int getSize(std::shared_ptr<QueueIntShared> q) {
        return q->get_size();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static int getLastElement(ConstSharedPtrOfQueueIntSharedType q) {
        return q->back();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static int getFirstElement(SharedPtrOfConstQueueIntSharedType q) {
        return q->front();
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static std::shared_ptr<QueueIntShared> getInvQueue(std::vector<int> v) {
        QueueIntShared res_q;

        for (int i : v) {
            res_q.push_back(-i);
        }

        return std::make_shared<QueueIntShared>(res_q);
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    SharedPtrOfQueueIntSharedType getSavedQueue() {
        return saved_queue;
    }

    /**
     * __API__
     * action: gen_property_getter
     */
    SharedPtrOfQueueIntSharedType saved_queue;
};

}

#endif
