#ifndef globs_hpp
#define globs_hpp

#include <string>

#include "cxx/enums/color.hpp"
#include "cxx/simple/project.hpp"


// [simple-example]
/**
 * A global function example.
 * __API__
 * action: gen_function
 * package: globs
 * swift.file: GlobUtils
 * throws: no_throw
 */
static int mul(int first, int second) {
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
static int mul(int first, int second, int third) {
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
// [example]

/** A global function with enum default value.
 * __API__
 * action: gen_function
 * package: globs
 * swift.file: GlobUtils
 * throws: no_throw
 */
iegen::example::Color optionalColor(iegen::example::Color c = iegen::example::Color::Red) {
    return c;
}

/** A global function with pointer default value and nullable return value.
 * __API__
 * action: gen_function
 * package: globs
 * swift.file: GlobUtils
 * throws: no_throw
 * nullable_return: True
 * return_value_policy: reference
 */
iegen::example::Project* optionalFDPtr(iegen::example::Project* project = nullptr) {
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

/** A global function with primitive default value.
 * __API__
 * action: gen_function
 * package: globs
 * swift.file: GlobUtils
 * throws: no_throw
 */
int optionalInt(int i = 5) {
    return i;
}

#endif