#ifndef vector_examples_h
#define vector_examples_h

#include <vector>
#include <string>


namespace iegen::example {

/**
 * comments
 *
 * __API__
 * action: gen_class
 * package: containers
 */
struct VectorItem {
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
    VectorItem(int _value) : value(_value){};

};

/**
 * comments
 *
 * __API__
 * action: gen_class
 * package: containers
 */
struct VectorExamples {

    /**
     * comments
     *
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    VectorExamples() {};

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
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
     * action: gen_method
     * throws: no_throw
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
     * action: gen_method
     * throws: no_throw
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
     * action: gen_method
     * throws: no_throw
     */
    const std::vector<std::string>& getStringVector(){
        return vectorStringData;
    }

        /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    const std::vector<VectorItem*>& getObjVector(){
        return vectorObjData;
    }

    /**
     * comments
     *
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    const std::vector<int>& getIntVector(){
        return vectorIntData;
    }

private:
    std::vector<std::string> vectorStringData;
    std::vector<int> vectorIntData;
    std::vector<VectorItem*> vectorObjData;
};

}

#endif