#ifndef nested_containers_h
#define nested_containers_h

#include <vector>
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

//    /**
//     * __API__
//     * action: gen_method
//     * throws: no_throw
//     */
//    void setNestedIntMap(const std::map<int, std::map<int, int>>& m) {
//        nestedIntMap = m;
//    }
//     /**
//     * __API__
//     * action: gen_method
//     * throws: no_throw
//     */
//     std::map<int, std::map<int, int>> getNestedIntMap() {
//        return nestedIntMap;
//     }

//     /**
//     * __API__
//     * action: gen_method
//     * throws: no_throw
//     */
//    void mixedExampleWithManyArgs(const std::vector<std::vector<int>>& v1, const std::vector<std::vector<int>>& v2,
//                                  const std::map<int, std::map<int, int>>& m1, const std::map<int, std::map<int, int>>& m2) {
//    }

    private:
    std::vector<std::vector<int>> nestedIntVector;
    std::map<int, std::map<int, int>> nestedIntMap;
};

}

#endif
