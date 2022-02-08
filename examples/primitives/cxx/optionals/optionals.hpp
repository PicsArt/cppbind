#ifndef optionals_h
#define optionals_h

#include <string>
#include <string_view>
#include <memory>
#include <complex>
#include "cxx/enums/color.hpp"
#include "cxx/simple/task.hpp"
#include "cxx/getters/person.hpp"


namespace iegen::example {
// [example]
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
     * throws: no_throw
     */
	Optionals()  {}


    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * nullable_return: True
     * return_value_policy: reference
     */
	Task* optionalPtrWithNullptrDefault(Task* task = nullptr) {
	    return task;
	}

	/**
     * __API__
     * action: gen_method
     * throws: no_throw
     * nullable_return: True
     * return_value_policy: reference
     */
	Task* optionalPtrWithNullDefault(Task* task = NULL) {
	    return task;
	}

	/**
     * __API__
     * action: gen_method
     * throws: no_throw
     * nullable_return: True
     * return_value_policy: reference
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
     * @param[in] optionalStr string with default value
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	std::string_view optionalStringViewWithDefault(std::string_view optionalStr = "abc") {
	    return optionalStr;
	}

    /**
     * \internal
     * TODO add swift action after char support for swift
     * __API__
     * python.action: gen_method
     * kotlin.action: gen_method
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

	/**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	ColorShade optionalEnumWithDefaultAndFieldPrefix(ColorShade c = ColorShade::Light) {
	    return c;
	}

	/**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	ColorShade optionalEnumWithInternalDefault(ColorShade c = ColorShade::InternalField) {
	    return c;
	}
	/**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	const Task& optionalRefWithDefaultComplexValue(const Task& task = Task("MyTask")) {
	    return task;
	}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	Task optionalByValWithDefaultComplexValue(Task task = Task("MyTask")) {
	    return task;
	}

};
// [example]
}

#endif
