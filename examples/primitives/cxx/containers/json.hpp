#ifndef json_examples_h
#define json_examples_h

#include <nlohmann/json.hpp>

namespace iegen::example {

/**
 * comments
 *
 * __API__
 * action: gen_class
 * package: containers
 */
struct JsonExamples {

    /**
     * comments
     *
     * __API__
     * action: gen_constructor
     */
    JsonExamples() {};

    /**
    * comments
    *
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    void setJson(const nlohmann::json& j) {
        jsonValue = j;
    }

    /**
    * comments
    *
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

private:
    nlohmann::json jsonValue;
};

}

#endif