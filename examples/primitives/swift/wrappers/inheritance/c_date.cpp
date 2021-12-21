/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/21/2021-09:26.
 * Please do not change it manually.
 */

#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/inheritance/c_date.h"
#include "cxx/inheritance/date.hpp"
#include "cxx/inheritance/base.hpp"

using namespace iegen::example;

void release_MyDate(CObject cself, bool owner) {
    delete cself.type;
    if (owner) {
        delete static_cast<std::shared_ptr<iegen::example::Base>*>(cself.ptr);
    }
}

CObject create_MyDate(int d, int m, int y, ErrorObj* _Nonnull err){
    
    
    
    try {
        auto this_object = new iegen::example::Date(d, m, y);
        return {strdup("iegen::example::Date"), new std::shared_ptr<iegen::example::Base>(this_object)};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CObject result{};
    return result;
}

char* _Nonnull _func_MyDate_value(CObject cself, ErrorObj* _Nonnull err){
    
    std::shared_ptr<iegen::example::Date> ctocxxcself;
    ctocxxcself = std::dynamic_pointer_cast<iegen::example::Date>(*static_cast<std::shared_ptr<iegen::example::Base>*>(cself.ptr));
    try {
        const auto& result = ctocxxcself->value();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result{};
    return result;
}

char* _Nonnull _prop_get_MyDate_date(CObject cself){
    std::shared_ptr<iegen::example::Date> ctocxxcself;
    ctocxxcself = std::dynamic_pointer_cast<iegen::example::Date>(*static_cast<std::shared_ptr<iegen::example::Base>*>(cself.ptr));
    const auto& result = ctocxxcself->date();
    auto cxxtocresult = strdup(result.data());
    return cxxtocresult;
}
