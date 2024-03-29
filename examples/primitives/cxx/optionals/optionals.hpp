#ifndef optionals_h
#define optionals_h


#include <string>
#include <string_view>
#include <memory>
#include <complex>
#include "cxx/getters/person.hpp"
#include "cxx/enums/color.hpp"
#include "cxx/enums/logging.hpp"
#include "cxx/simple/task.hpp"
#include "cxx/simple/root.hpp"

using UCHAR = unsigned char;

namespace cppbind::example {
// forward declaration
class Project;

/**
 * __API__
 * action: gen_class
 * package: optionals
 */
class Optionals {
public:
// [literals-example]
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
	short optionalShortWithDefault(short value = 10) {
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
	UCHAR optionalUnsignedCharWithDefault(UCHAR num = 100) {
        return num;
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
	LogLevel optionalEnumWithDefaultAndChangedNames(LogLevel level = LogLevel::warning_level) {
	    return level;
	}

// [literals-example]

// [complex-value-examples]
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	Task singleComplexDefaultValue(Task task = Task("MyTask")) {
	    return task;
	}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	std::string multipleMixedDefaultValues(Task task = Task("DefaultTask"), int i = 1, Root r = Root("DefaultRoot")) {
	    return task.title() + std::to_string(i) + r.path;
	}

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Optionals(Task task = Task("DefaultTask"), int i = 1, Root r = Root("DefaultRoot")): _task(task), _i(i), _r(r) {}
// [complex-value-examples]


/// other test cases

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
     * @param[in] optionalStr string with default value
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	std::string_view optionalStringViewWithDefault(std::string_view optionalStr = "abc") {
	    return optionalStr;
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
	std::shared_ptr<Person> optionalSharedPtrWithNullptrDefault(std::shared_ptr<Person> person = nullptr) {
	    return person;
	}

    int getI() {
        return _i;
    }

    Task& getTask() {
        return _task;
    }

    Root& getRoot() {
        return _r;
    }

private:
    Task _task;
    int _i;
    Root _r;
};
}

#endif
