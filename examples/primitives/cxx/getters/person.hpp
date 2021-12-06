/**
 * This is a basic example for getter/setter method and  property getter/setter.
 * It contains a private string field and getter/setter methods for it and public fields with property getter/setter.
 */

#ifndef person_hpp
#define person_hpp
#include <string>

namespace iegen::example {
// [example]
/**
 * This class contains a private string field and getter/setter methods for it.
 * __API__
 * action: gen_class
 * shared_ref: true
 * package: getters
 */
class Person {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Person(const std::string& name, const std::string& email, int age) : _email(email), _age(age), _fullname(name) {}

    /**
     *__API__
     * action: gen_setter
     * throws: no_throw
     */
    void setFullName(const std::string& val) {
        _fullname = val;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     * name: name
     */
    const std::string& fullName() {
        return _fullname;
    }

    /**
     * __API__
     * action: gen_property_getter
     * name: email
     */
    std::string _email;

    /**
     * __API__
     * action: gen_property_setter
     * name: age
     */
    int _age;
private:
    std::string _fullname;

};
// [example]
}
#endif
