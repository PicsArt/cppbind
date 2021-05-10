#ifndef optionals_h
#define optionals_h

#include <string>
#include <complex>
#include "cxx/enums/color.hpp"
#include "cxx/classes/task.hpp"

/*
 * Operators overload examples
 */
namespace iegen::example {

/**
 * __API__
 * gen: class
 * package: optionals
 * swift.include: CWrapper
 * python.include: classes.task_pygen
 * python.include: enums.color_pygen
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
     */
	Task* optionalPtrWithNullptrDefault(Task* task = nullptr) {
	    return task;
	}

	/**
     * __API__
     * gen: method
     */
	int optionalIntWithDefault(int val = 5) {
	    return val;
	}

	/**
     * __API__
     * gen: method
     */
	std::string optionalStringWithDefault(std::string val = "abc") {
	    return val;
	}

    /**
     * __API__
     * gen: method
     */
	char optionalCharWithDefault(char symbol = ',') {
        return symbol;
	}

    /**
     * __API__
     * gen: method
     */
	Task* optionalPtrWithNullDefault(Task* task = NULL) {
	    return task;
	}

	/**
     * __API__
     * gen: method
     */
	Color optionalEnumWithDefault(Color c = Color::Red) {
	    return c;
	}

};
}

#endif
