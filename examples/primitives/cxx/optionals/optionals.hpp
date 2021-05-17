#ifndef optionals_h
#define optionals_h

#include <string>
#include <complex>
#include "cxx/enums/color.hpp"
#include "cxx/simple/task.hpp"

/*
 * Operators overload examples
 */
namespace iegen::example {

/**
 * __API__
 * gen: class
 * package: optionals
 * swift.include: CWrapper
 * python.include:
 *   - simple.task
 *   - enums
 */
class Optionals {


public:
    /**
     * constructor
     * __API__
     * gen: constructor
     */
	Optionals()  {}


    /**
     *
     * __API__
     * gen: method
     * throws: no_throw
     */
	Task* optionalPtrWithNullptrDefault(Task* task = nullptr) {
	    return task;
	}

	/**
     * __API__
     * gen: method
     * throws: no_throw
     */
	int optionalIntWithDefault(int val = 5) {
	    return val;
	}

	/**
     * __API__
     * gen: method
     * throws: no_throw
     */
	std::string optionalStringWithDefault(std::string val = "abc") {
	    return val;
	}

    /**
     * __API__
     * gen: method
     * throws: no_throw
     */
	char optionalCharWithDefault(char symbol = ',') {
        return symbol;
	}

    /**
     * __API__
     * gen: method
     * throws: no_throw
     */
	Task* optionalPtrWithNullDefault(Task* task = NULL) {
	    return task;
	}

	/**
     * __API__
     * gen: method
     * throws: no_throw
     */
	Color optionalEnumWithDefault(Color c = Color::Red) {
	    return c;
	}

};
}

#endif
