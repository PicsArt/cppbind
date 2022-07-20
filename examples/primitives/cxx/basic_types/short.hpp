#ifndef short_hpp
#define short_hpp

#include <utility>
#include <vector>
#include <cstdint>

namespace cppbind::example {

/**
 * __API__
 * action: gen_function
 * package: basic_types
 * throws: no_throw
 */
short add(std::int16_t a, std::int16_t b) {
    return a + b;
}

/**
 * __API__
 * action: gen_function
 * package: basic_types
 * throws: no_throw
 */
std::vector<short> add(std::vector<short> v, short a) {
    std::vector<short> result;
    for (short number : v)
        result.push_back(number + a);

    return result;
}

/**
 * __API__
 * action: gen_function
 * package: basic_types
 * throws: no_throw
 */
std::pair<short, short> add(std::pair<short, short> p1, std::pair<short, short> p2) {
    return std::make_pair(p1.first + p2.first, p1.second + p2.second);
}

}

#endif
