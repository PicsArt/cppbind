#ifndef map_examples_h
#define map_examples_h

#include <unordered_map>
#include <map>
#include <string>

namespace iegen::example {

/**
 * comments
 *
 * __API__
 * action: gen_class
 * package: containers
 */
struct MapItem {
    /**
     * comments
     *
     * __API__
     * action: gen_property_setter
     */
    int value;

    /**
     * comments
     *
     * __API__
     * action: gen_constructor
     */
    MapItem(int _value) : value(_value){};

};

/**
 * comments
 *
 * __API__
 * action: gen_class
 * package: containers
 */
struct MapExamples {

    /**
     * comments
     *
     * __API__
     * action: gen_constructor
     */
    MapExamples() {};

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void addStringPair(const std::pair<std::string, std::string>& info) {
        mapStringData.insert(info);
    };

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void addIntMap(const std::map<int, int>& info) {
        mapIntData.insert(info.begin(), info.end());
    };

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void addStringMap(const std::map<std::string, std::string>& info) {
        mapStringData.insert(info.begin(), info.end());
    };


    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::unordered_map<std::string, std::string> getStringMap() {
        return mapStringData;
    }

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::unordered_map<int, int> getIntMap() {
        return mapIntData;
    }

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void addMixedMap(const std::map<std::string, MapItem>& info) {
        mapMixedData.insert(info.begin(), info.end());
    }

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    std::unordered_map<std::string, MapItem> getMixedMap() {
        return mapMixedData;
    }
// TODO: commented as for now for kotlin we do not have nested containers support
//    /**
//     * comments
//     *
//     * __API__
//     * gen: method
//     */
//    void setNestedMap(const std::map<int, std::map<int, int>>& m) {
//        nestedMap = m;
//    }
//     /**
//     * comments
//     *
//     * __API__
//     * gen: method
//     */
//     std::map<int, std::map<int, int>> getNestedMap() {
//        return nestedMap;
//     }

private:
    std::unordered_map<std::string, std::string> mapStringData;
    std::unordered_map<int, int> mapIntData;
    std::unordered_map<std::string, MapItem> mapMixedData;
    std::map<int, std::map<int, int>> nestedMap;
};

}

#endif /* containers_h */
