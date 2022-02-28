#include "cxx/rv_policies/policies_doc_examples.hpp"

namespace iegen::example {

// factory
Factory* Factory::create() {
    return new Factory();
}

Factory::Factory() {}

// singleton
Singleton* Singleton::_instance = nullptr;

Singleton& Singleton::getInstance() {
    return *getInstancePtr();
}

Singleton* Singleton::getInstancePtr() {
    if (!_instance) {
        _instance = new Singleton();
    }
    return _instance;
}

Singleton::Singleton() {}

// employer
Employer::Employer(const std::vector<Employee*>& employees) {
    _employees.insert(_employees.end(), employees.begin(), employees.end());
}

void Employer::addEmployee(Employee* employee) {
    _employees.push_back(employee);
}

}
