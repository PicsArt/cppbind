#ifndef globs_hpp
#define globs_hpp
#include <string>

#include "cxx/enums/color.hpp"
#include "cxx/simple/project.hpp"
#include "cxx/simple/root.hpp"
#include "cxx/simple/task.hpp"


// [simple-example-start]
/**
 * A global function example.
 * __API__
 * action: gen_function
 * package: globs
 * swift.file: GlobUtils
 * throws: no_throw
 */
int mul(int first, int second);

/**
 * A global function example.
 * __API__
 * action: gen_function
 * package: globs
 * swift.file: GlobUtils
 * throws: no_throw
 * overloading_postfix: Three
 */
int mul(int first, int second, int third);

/**
 * A global function example.
 * __API__
 * action: gen_function
 * package: globs
 * swift.file: GlobUtils
 * throws: no_throw
 */
std::string concat(const std::string& str1, const std::string& str2);
// [simple-example-end]

// [example-start]
/**
 * A global overloaded function example.
 * __API__
 * action: gen_function
 * package: globs
 * swift.file: GlobUtils
 * throws: no_throw
 */
std::string concat(const std::string& str1, const std::string& str2, const std::string& str3);

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

namespace cppbind::example {
    /**
     * A global template function example in namespace.
     * __API__
     * action: gen_function
     * package: globs
     * swift.file: GlobUtils
     * throws: no_throw
     * template:
     *   T:
     *     - type: cppbind::example::Project
     *     - type: cppbind::example::Root
     *   V:
     *     - type: cppbind::example::Project
     * return_value_policy: reference
     */
    template <typename T, typename V>
    std::pair<T*, V*> makePair(T* a, V* b) {
       return std::make_pair(a, b);
    }
}

// [example-end]

// [non-complex-defaults-example-start]
/**
 * A global function with enum default argument.
 * __API__
 * action: gen_function
 * kotlin.package: globs.primitives
 * package: globs
 * file: primitiveDefaults
 * throws: no_throw
 */
 cppbind::example::Color optionalColor(cppbind::example::Color c = cppbind::example::Color::Red);

/**
 * A global function with string default argument.
 * __API__
 * action: gen_function
 * kotlin.package: globs.primitives
 * package: globs
 * file: primitiveDefaults
 * throws: no_throw
 */
std::string optionalString(std::string optionalStr = "abc");

/** A global function with primitive default value.
 * __API__
 * action: gen_function
 * kotlin.package: globs.primitives
 * package: globs
 * file: primitiveDefaults
 * throws: no_throw
 */
int optionalInt(int i = 5);
// [non-complex-defaults-example-end]

// [complex-defaults-example-start]
/**
 * __API__
 * action: gen_function
 * kotlin.package: globs.complex
 * package: globs
 * file: complexDefaults
 * throws: no_throw
 */
cppbind::example::Task singleComplexDefaultValue(cppbind::example::Task task = cppbind::example::Task("MyTask"));

/**
 * A global function with mixed default values.
 * __API__
 * action: gen_function
 * kotlin.package: globs.complex
 * package: globs
 * file: complexDefaults
 * throws: no_throw
 */
std::string multipleMixedDefaultValues(cppbind::example::Task task = cppbind::example::Task("DefaultTask"),
                                       int i = 1,
                                       cppbind::example::Root r = cppbind::example::Root("DefaultRoot"));
// [complex-defaults-example-end]

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
cppbind::example::Project* optionalFDPtr(cppbind::example::Project* project = nullptr);

/** A global function with no return value.
 * __API__
 * action: gen_function
 * package: globs
 * swift.file: GlobUtils
 * throws: no_throw
 */
void doNothing();

 // [custom-arg-examples-start]
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
std::string greet(const std::string& name, const std::string& hometown);
// [custom-arg-examples-end]


#endif
