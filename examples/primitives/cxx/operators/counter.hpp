#ifndef counter_h
#define counter_h

namespace iegen::example {
// [example]
/**
 * An example for with overloaded methods.
 * __API__
 * gen: class
 * package: operators
 * swift.include: CWrapper
 */
class Counter {
public:
    /**
     * Counter constructor.
     * __API__
     * gen: constructor
     */
	Counter(int count) : _count(count) {}

	Counter(const Counter& c) {
	    _count = c.count();
	}

    /**
     * Getter for count.
     * __API__
     * gen: getter
     */
	int count() const {
	    return _count;
	}

    /**
     * Plus operator
     * __API__
     * gen: method
     * kotlin.name: plus
     */
    Counter operator+(const Counter& counter) {
        return Counter(_count + counter.count());
    }

    /**
     * Comparison operator for kotlin
     * __API__
     * gen: method
     * kotlin.is_operator: True
     * kotlin.name: compareTo
     */
    int compareTo(const Counter& counter) {
        if (_count > counter.count()) return 1;
        else if (_count < counter.count()) return -1;
        else return 0;
    }

    /**
     * __API__
     * gen: method
     * kotlin.name: gt
     * kotlin.is_operator: False
     */
    bool operator>(const Counter& counter) {
        return _count > counter.count();
    }

    /**
     * __API__
     * gen: method
     * kotlin.name: add
     * kotlin.is_operator: False
     */
    Counter& operator +=(const Counter& counter) {
        this->_count += counter.count();
        return *this;
    }
private:
	int _count;
};
// [example]
}
#endif