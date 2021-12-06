#ifndef employee_hpp
#define employee_hpp

#include <vector>
#include <string>

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: overloads
 */
class Employee {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Employee(const std::string& name) : _name(name) {};

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Employee(int age, const std::string& email = "") : _age(age), _email(email) {};


    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void setData(const std::string& name, int age, const std::string& email = "") {
        _name = name;
        _age = age;
        _email = email;
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void setData(int age) {
        _age = age;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const std::string& name() {
        return _name;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const std::string& email() {
        return _email;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    int age() {
        return _age;
    }

private:
    std::string _name;
    int _age;
    std::string _email;

};
// [example]
}
#endif