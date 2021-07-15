#ifndef optionals_h
#define optionals_h

#include <string>
#include <memory>
#include <complex>
#include "cxx/enums/color.hpp"
#include "cxx/simple/task.hpp"
#include "cxx/getters/person.hpp"


namespace iegen::example {
// forward declaration
class Project;

/**
 * __API__
 * action: gen_class
 * package: optionals
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
     * __API__
     * action: gen_method
     * throws: no_throw
     * nullable_return: True
     */
	Task* optionalPtrWithNullptrDefault(Task* task = nullptr) {
	    return task;
	}

	/**
     * __API__
     * action: gen_method
     * throws: no_throw
     * nullable_return: True
     */
	Project* optionalFDPtrWithNullptrDefault(Project* project = nullptr) {
	    return project;
	}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * nullable_return: True
     */
	const std::shared_ptr<Person>& optionalSharedPtrWithNullptrDefault(const std::shared_ptr<Person>& person = nullptr) {
	    return person;
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
	Color optionalEnumWithDefault(Color c = Color::Red) {
	    return c;
	}

};
}

#endif
