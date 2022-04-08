#ifndef value_hpp
#define value_hpp

#include <string>
#include <variant>

namespace iegen::example {
/**
 * __API__
 * action: gen_class
 * package: templates
 */
class TemplateValue {
    public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     * template:
     *   T:
     *     - type: int
     *     - type: std::string
     */
    template <typename T>
    TemplateValue(T value) : _value(value) {};

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * template:
     *   T:
     *     - type: int
     *     - type: std::string
     */
    template <typename T>
    T add_value(T other) {
       return std::get<T>(_value) + other;
    }

private:
    std::variant<int, std::string> _value;

};

}

#endif
