#ifndef optionals_h
#define optionals_h

#include <string>
#include <complex>
#include "cxx/enums/color.hpp"
#include "cxx/simple/task.hpp"


namespace iegen::example {

/**
 * __API__
 * action: gen_class
 * package: optionals
 * swift.include: CWrapper
 */
class Optionals {


public:
    /**
     * constructor
     * __API__
     * action: gen_constructor
     */
	Optionals()  {}


    /**
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	Task* optionalPtrWithNullptrDefault(Task* task = nullptr) {
	    return task;
	}

	/**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	int optionalIntWithDefault(int val = 5) {
	    return val;
	}

	/**
     * @param[in] optionalStr string with default value
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	std::string optionalStringWithDefault(std::string optionalStr = "abc") {
	    return optionalStr;
	}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	char optionalCharWithDefault(char symbol = ',') {
        return symbol;
	}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	Task* optionalPtrWithNullDefault(Task* task = NULL) {
	    return task;
	}

	/**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	Color optionalEnumWithDefault(Color c = Color::Red) {
	    return c;
	}

};
}

#endif
