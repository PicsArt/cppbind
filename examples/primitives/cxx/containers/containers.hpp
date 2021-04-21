#ifndef containers_h
#define containers_h

#include <unordered_map>
#include <map>
#include <vector>
#include <string>


namespace iegen::example {

/**
 * comments
 *
 * __API__
 * gen: class
 * package: containers
 */
struct Item {
    /**
     * comments
     *
     * __API__
     * gen: property_setter
     */
    int value;

    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    Item(int _value) : value(_value){};

};

/**
 * comments
 *
 * __API__
 * gen: class
 * package: containers
 */
struct Containers {

    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    Containers() {
        mapMixedData.insert(std::make_pair("first", Item(1)));
        mapMixedData.insert(std::make_pair("second", Item(2)));
    };

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    void addStringPair(const std::pair<std::string, std::string>& info) {
        mapStringData.insert(info);
    };

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    void addIntMap(const std::map<int, int>& info) {
        mapIntData.insert(info.begin(), info.end());
    };

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    void addStringMap(const std::map<std::string, std::string>& info) {
        mapStringData.insert(info.begin(), info.end());
    };

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    void addIntPair(const std::pair<int, int>& info) {
        mapIntData.insert(info);
    };

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    std::pair<std::string, std::string> getStringPair() {
        return std::make_pair("first", "second");
    };

//    /**
//     * comments
//     *
//     * __API__
//     * gen: method
//     */
//    std::pair<int, int> getIntPair() {
//        return std::make_pair(1, 2);
//    };


    /**
     * comments
     *
     * __API__
     * gen: method
     */
    std::unordered_map<std::string, std::string> getStringMap() {
        return mapStringData;
    }

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    std::unordered_map<int, int> getIntMap() {
        return mapIntData;
    }

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    std::unordered_map<std::string, Item> getMap() {
        return mapMixedData;
    }

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    void addIntVector(const std::vector<int>& v){
        for (auto item: v) {
            vectorIntData.push_back(item);
        }
    }

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    void addStringVector(const std::vector<std::string>& v){
        for (auto item: v) {
            vectorStringData.push_back(item);
        }
    }

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    const std::vector<std::string>& getStringVector(){
        return vectorStringData;
    }

    /**
     * comments
     *
     * __API__
     * gen: method
     */
    const std::vector<int>& getIntVector(){
        return vectorIntData;
    }

private:
    std::vector<std::string> vectorStringData;
    std::vector<int> vectorIntData;
    std::unordered_map<std::string, std::string> mapStringData;
    std::unordered_map<int, int> mapIntData;
    std::unordered_map<std::string, Item> mapMixedData;

};


} // namespace pi::video_engine::model

#endif /* containers_h */
