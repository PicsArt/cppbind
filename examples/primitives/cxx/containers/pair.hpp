#ifndef pair_examples_h
#define pair_examples_h

#include <utility>
#include <string>

namespace iegen::example {

/**
 * comments
 *
 * __API__
 * action: gen_class
 * package: containers
 */
struct PairExamples {

    /**
     * comments
     *
     * __API__
     * action: gen_constructor
     */
    PairExamples() {};

     /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::pair<int, int> sumIntPairs(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        return {p1.first + p2.first, p1.second + p2.second};
    }

     /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     void setNestedPair(const std::pair<std::pair<std::string, std::string>, std::pair<std::string, std::string>>& p) {
        nestedPair = p;
     }

     /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     std::pair<std::pair<std::string, std::string>, std::pair<std::string, std::string>> getNestedPair() {
        return nestedPair;
     }

     /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::pair<std::string, std::string> getStringPair() {
        return std::make_pair("first", "second");
    };

private:
    std::pair<std::pair<std::string, std::string>, std::pair<std::string, std::string>> nestedPair;
};

}

#endif