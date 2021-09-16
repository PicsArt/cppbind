#ifndef nested_containers_h
#define nested_containers_h

#include <vector>
#include <string>
#include <map>

namespace iegen::example {

/**
 * __API__
 * action: gen_class
 * package: containers
 */
class NestedExamples {
    public:
    /**
    * comments
    *
    * __API__
    * action: gen_constructor
    */
    NestedExamples() {};

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    void setNestedIntVector(const std::vector<std::vector<int>>& v) {
        nestedIntVector = v;
    }

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    std::vector<std::vector<int>> getNestedIntVector() {
        return nestedIntVector;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void setNestedIntMap(const std::map<int, std::map<int, int>>& m) {
        nestedIntMap = m;
    }
     /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     std::map<int, std::map<int, int>> getNestedIntMap() {
        return nestedIntMap;
     }

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    void mixedExampleWithManyArgs(const std::vector<std::vector<int>>& v1, const std::vector<std::vector<int>>& v2,
                                  const std::map<int, std::map<int, int>>& m1, const std::map<int, std::map<int, int>>& m2) {
    }

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    void setVectorOfIntMaps(const std::vector<std::map<int, int>>& v) {
        vectorOfIntMaps = v;
    }

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    std::vector<std::map<int, int>> getVectorOfIntMaps() {
        return vectorOfIntMaps;
    }

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    void setMapOfIntVectors(const std::map<int, std::vector<int>>& m) {
        mapOfIntVectors = m;
    }

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    std::map<int, std::vector<int>> getMapOfIntVectors() {
        return mapOfIntVectors;
    }

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    void setComplexStringVector(const std::vector<std::vector<std::vector<std::string>>>& v) {
        complexStringVector = v;
    }

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    std::vector<std::vector<std::vector<std::string>>> getComplexStringVector() {
        return complexStringVector;
    }

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    void setComplexStringMap(const std::map<std::string, std::map<std::string, std::map<std::string, std::string>>>& m) {
        complexStringMap = m;
    }

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> getComplexStringMap() {
        return complexStringMap;
    }

    private:
    std::vector<std::vector<int>> nestedIntVector;
    std::map<int, std::map<int, int>> nestedIntMap;
    std::vector<std::map<int, int>> vectorOfIntMaps;
    std::map<int, std::vector<int>> mapOfIntVectors;
    std::vector<std::vector<std::vector<std::string>>> complexStringVector;
    std::map<std::string, std::map<std::string, std::map<std::string, std::string>>> complexStringMap;
};

}

#endif
