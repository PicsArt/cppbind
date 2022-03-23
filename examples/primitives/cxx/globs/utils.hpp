#ifndef globs_hpp
#define globs_hpp

#include <string>

#include "cxx/enums/color.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"
#include "cxx/simple/task.hpp"

using namespace iegen::example;

namespace {
    // [simple-example]
    /**
     * A global function example.
     * __API__
     * action: gen_function
     * package: globs
     * swift.file: GlobUtils
     * throws: no_throw
     */
    int mul(int first, int second) {
        return first * second;
    }


    // [simple-example]
    /**
     * A global function example.
     * __API__
     * action: gen_function
     * package: globs
     * swift.file: GlobUtils
     * throws: no_throw
     * overloading_postfix: Three
     */
    int mul(int first, int second, int third) {
        return first * second * third;
    }

    /**
     * A global function example.
     * __API__
     * action: gen_function
     * package: globs
     * swift.file: GlobUtils
     * throws: no_throw
     */
    std::string concat(const std::string& str1, const std::string& str2) {
        return str1 + str2;
    }
    // [simple-example]

    // [example]
    /**
     * A global overloaded function example.
     * __API__
     * action: gen_function
     * package: globs
     * swift.file: GlobUtils
     * throws: no_throw
     */
    std::string concat(const std::string& str1, const std::string& str2, const std::string& str3) {
        return str1 + str2 +str3;
    }

    /**
     * A global template function example.
     * __API__
     * action: gen_function
     * package: globs
     * swift.file: GlobUtils
     * throws: no_throw
     * template:
     *   T:
     *     - type: int
     *     - type: std::string
     */
    template <typename T>
    T max(T a, T b) {
       return a < b ? b:a;
}

}

namespace iegen::example {
    /**
     * A global template function example in namespace.
     * __API__
     * action: gen_function
     * package: globs
     * swift.file: GlobUtils
     * throws: no_throw
     * template:
     *   T:
     *     - type: iegen::example::Project
     *     - type: iegen::example::Root
     *   V:
     *     - type: iegen::example::Project
     * return_value_policy: reference
     */
    template <typename T, typename V>
    std::pair<T*, V*> makePair(T* a, V* b) {
       return std::make_pair(a, b);
    }
}

namespace {
// [example]

// [non-complex-defaults-example]
/**
 * A global function with enum default argument.
 * __API__
 * action: gen_function
 * kotlin.package: globs.primitives
 * package: globs
 * file: primitiveDefaults
 * throws: no_throw
 */
    Color optionalColor(iegen::example::Color c = iegen::example::Color::Red) {
        return c;
    }

    /**
     * A global function with string default argument.
     * __API__
     * action: gen_function
     * kotlin.package: globs.primitives
     * package: globs
     * file: primitiveDefaults
     * throws: no_throw
     */
    std::string optionalString(std::string optionalStr = "abc") {
        return optionalStr;
    }

    /** A global function with primitive default value.
     * __API__
     * action: gen_function
     * kotlin.package: globs.primitives
     * package: globs
     * file: primitiveDefaults
     * throws: no_throw
     */
    int optionalInt(int i = 5) {
        return i;
    }
    // [non-complex-defaults-example]

    // [complex-defaults-example]
    /**
     * __API__
     * action: gen_function
     * kotlin.package: globs.complex
     * package: globs
     * file: complexDefaults
     * throws: no_throw
     */
    Task singleComplexDefaultValue(Task task = Task("MyTask")) {
        return task;
    }

    /**
     * A global function with mixed default values.
     * __API__
     * action: gen_function
     * kotlin.package: globs.complex
     * package: globs
     * file: complexDefaults
     * throws: no_throw
     */
    std::string multipleMixedDefaultValues(Task task = Task("DefaultTask"), int i = 1,
                                           Root r = Root("DefaultRoot")) {
        return task.title() + std::to_string(i) + r.path;
    }
    // [complex-defaults-example]

    /// other test cases

    /** A global function with pointer default value and nullable return value.
     * __API__
     * action: gen_function
     * package: globs
     * swift.file: GlobUtils
     * throws: no_throw
     * nullable_return: True
     * return_value_policy: reference
     */
    Project* optionalFDPtr(Project* project = nullptr) {
        return project;
    }

    /** A global function with no return value.
     * __API__
     * action: gen_function
     * package: globs
     * swift.file: GlobUtils
     * throws: no_throw
     */
    void doNothing() {
    }

     // [custom-arg-examples]
     /** A global function with custom argument name and label.
     * __API__
     * action: gen_function
     * kotlin.package: globs.custom_args
     * package: globs
     * file: customArgUtils
     * throws: no_throw
     * argument_name:
        name: person
     * argument_label:
        hometown: from
     */
    std::string greet(const std::string& name, const std::string& hometown) {
        return "Hello " + name + " from " + hometown;
    }
    // [custom-arg-examples]


}
#endif