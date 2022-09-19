#ifndef std_optional_h
#define std_optional_h

#include <optional>
#include <string>
#include <vector>
#include "cxx/enums/color.hpp"
#include "cxx/enums/frame.hpp"
#include "cxx/containers/pair.hpp"
#include "cxx/containers/map.hpp"

namespace cppbind::example {

/**
* __API__
* package: stl_types
* template:
    T:
      - type: int
      - type: float
      - type: double
      - type: short
* action: gen_function
* throws: no_throw
*/
template <typename T>
std::optional<T> mul(std::optional<T> a, T b) {
    return a ? a.value() * b : a;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<long> mulLong(std::optional<long> a, long b) {
    return a ? std::optional<long>(a.value() * b) : a;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<bool> reverseBool(std::optional<bool> a) {
    return a ? std::optional<bool>(!a.value()) : a;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<unsigned int> mulUnsignedInt(std::optional<unsigned int> a, unsigned int b) {
    return a ? std::optional<unsigned int>(a.value() * b) : a;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<unsigned long> mulUnsignedLong(std::optional<unsigned long> a, unsigned long b) {
    return a ? std::optional<unsigned long>(a.value() * b) : a;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<long long> mulLongLong(std::optional<long long> a, long long b) {
    return a ? std::optional<long long>(a.value() * b) : a;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<unsigned char> mulUnsignedChar(std::optional<unsigned char> a, unsigned char b) {
    return a ? std::optional<unsigned char>(a.value() * b) : a;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<char> charToUpper(std::optional<char> a) {
    return a ? std::optional<char>(toupper(a.value())) : a;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<std::string> concatString(std::optional<std::string> first, std::string second) {
    return first ? first.value() + second : first;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<std::vector<std::string>> concat(std::optional<std::vector<std::string>> v, std::string s) {
    if (!v) return v;

    std::vector<std::string> res;
    for (auto item : v.value())
        res.push_back(item + s);

    return res;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::vector<std::optional<std::string>> concat2(std::vector<std::optional<std::string>> v, std::string s) {

    std::vector<std::optional<std::string>> res;
    for (auto item : v)
        res.push_back(item ? item.value() + s : item);

    return res;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<cppbind::example::Color> sameColor(std::optional<cppbind::example::Color> color) {
    return color;
}

/**
* __API__
* package: stl_types
* template:
    T:
      - type: std::optional<int>
      - type: std::optional<std::string>

* action: gen_function
* throws: no_throw
*/
template <typename T>
T same_template(T a) {
    return a;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<std::pair<int, int>> samePair(std::optional<std::pair<int, int>> pair) {
    return pair;
}

/**
* __API__
* package: stl_types
* action: gen_function
* throws: no_throw
*/
std::optional<std::map<int, int>> sameMap(std::optional<std::map<int, int>> map) {
    return map;
}

/**
 * __API__
 * action: gen_class
 * package: stl_types
 */
class FrameUsage {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    FrameUsage() {}
    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    * keep_alive: [1]
    */
    std::optional<cppbind::example::Frame> sameFrame(std::optional<cppbind::example::Frame> frame) {
        return frame;
    }
   /**
    * __API__
    * action: gen_method
    * throws: no_throw
    * return_value_policy: reference_internal
    */
    std::optional<cppbind::example::Frame>& getFrame() {
        return _frame;
    }
private:
    std::optional<cppbind::example::Frame> _frame = std::optional<cppbind::example::Frame>(cppbind::example::Frame());
};

}

#endif