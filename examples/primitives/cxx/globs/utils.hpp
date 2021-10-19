#ifndef globs_hpp
#define globs_hpp

#include <string>

/**
 * A global function example.
 * __API__
 * action: gen_function
 * package: globs
 * file: GlobUtils
 * throws: no_throw
 */
std::string concat(const std::string& str1, const std::string& str2) {
    return str1 + str2;
}

/**
 * A global template function example.
 * __API__
 * action: gen_function
 * package: globs
 * file: GlobUtils
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
     * A global template function example.
     * __API__
     * action: gen_function
     * package: globs
     * file: GlobUtils
     * throws: no_throw
     * template:
     *   T:
     *     - type: iegen::example::Project
     *     - type: iegen::example::Root
     *   V:
     *     - type: iegen::example::Project
     */
    template <typename T, typename V>
    std::pair<T*, V*> makePair(T* a, V* b) {
       return std::make_pair(a, b);
    }
}

#endif