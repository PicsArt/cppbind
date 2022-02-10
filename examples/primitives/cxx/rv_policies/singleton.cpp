#include "cxx/rv_policies/singleton.hpp"

namespace iegen::example {

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

}
