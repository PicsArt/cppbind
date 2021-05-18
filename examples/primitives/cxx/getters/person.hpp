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
 * gen: class
 * shared_ref: true
 * package: getters
 * swift.include: CWrapper
 */
class Person {
public:
    /**
     * __API__
     * gen: constructor
     */
    Person(const std::string& name, const std::string& email, int age) : _email(email), _age(age), _fullname(name) {}

    /**
     *__API__
     * gen: setter
     * throws: no_throw
     */
    void setFullName(const std::string& val) {
        _fullname = val;
    }

    /**
     * __API__
     * gen: getter
     * throws: no_throw
     */
    const std::string& fullName() {
        return _fullname;
    }

    /**
     * __API__
     * gen: property_getter
     * name: email
     */
    std::string _email;

    /**
     * __API__
     * gen: property_setter
     * name: age
     */
    int _age;
private:
    std::string _fullname;

};
// [example]
}
#endif
