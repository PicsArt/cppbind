#ifndef json_examples_h
#define json_examples_h

#include <nlohmann/json.hpp>
#include <vector>

namespace iegen::example {

/**
 * __API__
 * action: gen_class
 * package: containers
 */
struct JsonExamples {

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    JsonExamples() {};

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    void setJson(const nlohmann::json& j) {
        jsonValue = j;
    }

    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    nlohmann::json getJson() {
        return jsonValue;
    }

    /**
    * comments
    *
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    nlohmann::json getSimpleJsonExample() {
        return nlohmann::json::parse("{ \"status\": true, \"pi\": 3.14 }");
    }

   /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    void setJsonMatrix(const std::vector<std::vector<nlohmann::json>>& jm) {
        jsonMatrix = jm;
    }

   /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    std::vector<std::vector<nlohmann::json>> getJsonMatrix() {
        return jsonMatrix;
    }

private:
    nlohmann::json jsonValue;
    std::vector<std::vector<nlohmann::json>> jsonMatrix;
};

}

#endif