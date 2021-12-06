/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/06/2021-09:12.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/inheritance/c_time.h"
#include "cxx/inheritance/time.hpp"
#include "cxx/inheritance/base.hpp"

using namespace iegen::example;

void release_TimeImpl(void* _Nonnull cself){
    delete static_cast<std::shared_ptr<iegen::example::Base>*>(cself);
}

void* _Nonnull create_Time(int h, int m, int s, ErrorObj* _Nonnull err){
    
    
    
    try {
        auto this_object = new iegen::example::Time(h, m, s);
        return new std::shared_ptr<iegen::example::Base>(this_object);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    void* result = nullptr;
    return result;
}

char* _Nonnull _func_Time_value(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    std::shared_ptr<iegen::example::Time> c_to_cxx_cself;
    c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::Time>(*static_cast<std::shared_ptr<iegen::example::Base>*>(cself));
    try {
        const auto& result = c_to_cxx_cself->value();
        auto cxx_to_c_result = strdup(result.data());
        return cxx_to_c_result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result = nullptr;
    return result;
}

char* _Nonnull _prop_get_Time_time(void* _Nonnull cself){
    std::shared_ptr<iegen::example::Time> c_to_cxx_cself;
    c_to_cxx_cself = std::dynamic_pointer_cast<iegen::example::Time>(*static_cast<std::shared_ptr<iegen::example::Base>*>(cself));
    const auto& result = c_to_cxx_cself->time();
    auto cxx_to_c_result = strdup(result.data());
    return cxx_to_c_result;
}