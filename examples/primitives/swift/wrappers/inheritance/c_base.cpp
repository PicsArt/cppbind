/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/07/2022-12:05.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/inheritance/c_base.h"
#include "cxx/inheritance/base.hpp"
#include "cxx/inheritance/datetime.hpp"
#include "cxx/inheritance/date.hpp"
#include "cxx/inheritance/time.hpp"

using namespace iegen::example;

void release_BaseImpl(IEGenCObject cself, bool owner){
    static_assert(std::has_virtual_destructor<iegen::example::Base>::value, "iegen::example::Base type must have virtual destructor");
    free(cself.type);
    if (owner) {
        delete static_cast<std::shared_ptr<iegen::example::Base>*>(cself.ptr);
    }
}

char* _Nonnull _func_Base_value(IEGenCObject cself, IEGenCObject* _Nonnull err){
    
    std::shared_ptr<iegen::example::Base> ctocxxcself;
    if (strcmp(cself.type, "iegen::example::Base") == 0)
        ctocxxcself = *static_cast<std::shared_ptr<iegen::example::Base>*>(cself.ptr);
    else if (strcmp(cself.type, "iegen::example::DateTime") == 0)
        ctocxxcself = *static_cast<std::shared_ptr<iegen::example::DateTime>*>(cself.ptr);
    else if (strcmp(cself.type, "iegen::example::Date") == 0)
        ctocxxcself = *static_cast<std::shared_ptr<iegen::example::Date>*>(cself.ptr);
    else if (strcmp(cself.type, "iegen::example::Time") == 0)
        ctocxxcself = *static_cast<std::shared_ptr<iegen::example::Time>*>(cself.ptr);
    else {
        std::cerr << "Unexpected object type: " << cself.type << std::endl;
        exit(1);
    }
    try {
        const auto& result = ctocxxcself->value();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->type = strdup("std::exception");
        err->ptr = new std::exception(e);
    }
    catch (...) {
        err->type = strdup("Uncaught Exception");
    }
    char* result {};
    return result;
}
