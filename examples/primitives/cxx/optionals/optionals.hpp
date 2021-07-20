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
	int optionalIntWithDefault(int value = 5) {
	    return value;
	}

	/**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	long optionalLongWithDefault(long value = 7) {
	    return value;
	}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	double optionalDoubleWithDefault(double value = 9.0) {
	    return value;
	}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	float optionalFloatWithDefault(float value = 11.0) {
	    return value;
	}


    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	bool optionalBoolWithDefault(bool value = true) {
	    return value;
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
	const char* optionalCharPointerWithDefault(const char* optionalStr = "def") {
        return optionalStr;
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
