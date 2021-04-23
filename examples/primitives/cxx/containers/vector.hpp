#ifndef vector_examples_h
#define vector_examples_h

#include <vector>
#include <string>


namespace iegen::example {

/**
 * comments
 *
 * __API__
 * gen: class
 * package: containers
 * swift.include: CWrapper
 */
struct VectorItem {
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
    VectorItem(int _value) : value(_value){};

};

/**
 * comments
 *
 * __API__
 * gen: class
 * package: containers
 */
struct VectorExamples {

    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    VectorExamples() {};

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
    void addObjVector(const std::vector<VectorItem*>& v){
        for (auto item: v) {
            vectorObjData.push_back(item);
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
    const std::vector<VectorItem*>& getObjVector(){
        return vectorObjData;
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

// TODO: commented as for now for kotlin we do not have nested containers support
//    /**
//     * comments
//     *
//     * __API__
//     * gen: method
//     */
//    void setNestedVector(const std::vector<std::vector<int>>& v) {
//        nestedVector = v;
//    }
//    /**
//     * comments
//     *
//     * __API__
//     * gen: method
//     */
//    std::vector<std::vector<int>> getNestedVector() {
//        return nestedVector;
//    }

private:
    std::vector<std::string> vectorStringData;
    std::vector<int> vectorIntData;
    std::vector<VectorItem*> vectorObjData;
    std::vector<std::vector<int>> nestedVector;
};

}

#endif