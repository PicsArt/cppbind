#ifndef policies_hpp
#define policies_hpp

#include <vector>
#include "cxx/overloads/employee.hpp"

namespace cppbind::example {

// [factory-example]
/**
 * __API__
 * action: gen_class
 * shared_ref: False
 * package: rv_policies
 */
class Factory {
public:
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static Factory* create();

private:
    Factory();
};
// [factory-example]

// [singleton-example]
/**
 * __API__
 * action: gen_class
 * shared_ref: False
 * package: rv_policies
 */
class Singleton {
public:
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    static Singleton& getInstance();
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    static Singleton* getInstancePtr();

    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

private:
    Singleton();
    static Singleton* _instance;
};

// [singleton-example]


// [employer-example]

/**
 * __API__
 * action: gen_class
 * shared_ref: False
 * package: rv_policies
 */
class Employer {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     * keep_alive: [1]
     */
    Employer(const std::vector<Employee*>& employees);

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     * keep_alive: [1]
     */
    void addEmployee(Employee* employee);


private:
    std::vector<Employee*> _employees;
};

// [employer-example]

}

#endif
