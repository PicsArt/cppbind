#ifndef counter_h
#define counter_h

#include <vector>

namespace cppbind::example {
// [example-start]
/**
 * An example for with overloaded methods.
 * __API__
 * action: gen_class
 * package: operators
 */
class Counter {
public:
    /**
     * Counter constructor.
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
	Counter(int count) : _count(count) {}

	Counter(const Counter& c) {
	    _count = c.count();
	}

    /**
     * Getter for count.
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
	int count() const {
	    return _count;
	}

    /**
     * Plus operator
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Counter operator+(const Counter& counter) {
        return Counter(_count + counter.count());
    }

    /**
     * Comparison operator for kotlin
     * __API__
     * kotlin.action: gen_method
     * kotlin.is_operator: True
     * kotlin.name: compareTo
     * throws: no_throw
     */
    int compareTo(const Counter& counter) {
        if (_count > counter.count()) return 1;
        else if (_count < counter.count()) return -1;
        else return 0;
    }

    /**
     * __API__
     * python.action: gen_method
     * swift.action: gen_method
     * throws: no_throw
     */
    bool operator>(const Counter& counter) {
        return _count > counter.count();
    }

    /**
     * __API__
     * python.action: gen_method
     * swift.action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    Counter& operator +=(const Counter& counter) {
        this->_count += counter.count();
        return *this;
    }

   /**
    * Equality operator
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    bool operator == (const Counter& counter) {
       return this->_count == counter.count();
    }

private:
	int _count;
};
// [example-end]

/**
 * A class example to the case when non-operator method is mapped to == operator
 * __API__
 * action: gen_class
 * package: operators
 */
class PositiveCounter {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    PositiveCounter(int count) : _count(count) {}

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    PositiveCounter(std::vector<int> counts) : _multi_counts(counts) {}

    /**
     * __API__
     * action: gen_method
     * kotlin.name: equals
     * python.name: __eq__
     * swift.name: ==
     * is_operator: True
     * throws: no_throw
     */
    bool isEqual(const PositiveCounter& other) {
        return this->_count == other._count;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    int& operator [] (int i) {
        return _multi_counts[i];
    }

private:
    int _count;
    std::vector<int> _multi_counts;
};


}
#endif
