#ifndef map_examples_h
#define map_examples_h

#include <unordered_map>
#include <map>
#include <string>

namespace cppbind::example {

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
     * throws: no_throw
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
     * throws: no_throw
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
     * kotlin.action: gen_method
     * throws: no_throw
     */
    void addDoublePair(const std::pair<double, double>& info) {
        mapStringData[std::to_string(info.first)] = std::to_string(info.second);
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

     /**
     * Method for checking that the template arguments that are not translated
     * into target languages are not required to have converters.
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void checkComparatorArgument(const std::map<int, int, std::greater<int>>&){}

private:
    std::unordered_map<std::string, std::string> mapStringData;
    std::unordered_map<int, int> mapIntData;
    std::unordered_map<std::string, MapItem> mapMixedData;
};

}

#endif /* containers_h */
