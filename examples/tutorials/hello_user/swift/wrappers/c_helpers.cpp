#include <memory>
#include <cxxabi.h>

#include "c_helpers.h"

const char* demangle(const char* name) {

    int status = 0;

    std::unique_ptr<char, void(*)(void*)> res {
        abi::__cxa_demangle(name, NULL, NULL, &status),
        std::free
    };

    return (status==0) ? res.get() : name;
};