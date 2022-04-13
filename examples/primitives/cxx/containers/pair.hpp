#ifndef pair_examples_h
#define pair_examples_h

#include <utility>
#include <string>
#include <vector>

#include "map.hpp"

namespace iegen::example {

/**
 * comments
 *
 * __API__
 * action: gen_class
 * package: containers
 * swift.file: pair_examples
 */
struct PairExamples {

    /**
     * comments
     *
     * __API__
     * action: gen_constructor
     * throws: no_throw
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

   /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    void setNestedVectorOfPairs(const std::vector<std::vector<std::pair<int, std::string>>>& v) {
        nestedVectorOfPairs = v;
    }

   /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    std::vector<std::vector<std::pair<int, std::string>>> getNestedVectorOfPairs() {
        return nestedVectorOfPairs;
    }

   /**
    * __API__
    * action: gen_setter
    * throws: no_throw
    */
    void setComplexPairObj(const std::pair<MapItem, std::vector<MapItem>>& p) {
        _complexPairObj = p;
    }

   /**
    * __API__
    * action: gen_getter
    * throws: no_throw
    */
    std::pair<MapItem, std::vector<MapItem>> complexPairObj() {
        return _complexPairObj;
    }

private:
    std::pair<std::pair<std::string, std::string>, std::pair<std::string, std::string>> nestedPair;
    std::vector<std::vector<std::pair<int, std::string>>> nestedVectorOfPairs;
    std::pair<MapItem, std::vector<MapItem>> _complexPairObj = {MapItem(0), {}};
};

}

#endif