/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/02/2022-11:11.
 * Please do not change it manually.
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include <type_traits>
#include "swift/wrappers/simple/c_project.h"
#include "cxx/simple/project.hpp"
#include "cxx/simple/task.hpp"

using namespace iegen::example;

void release_Project(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::example::Project*>(cself.ptr);
    }
}

IEGenCObject create_Project(char* _Nonnull title, IEGenCErrorObj* _Nonnull err){
    auto ctocxxtitle = std::string(title);
    free(title);
    try {
        auto this_object = new iegen::example::Project(ctocxxtitle);
        return {strdup("iegen::example::Project"), this_object};
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    IEGenCObject result {};
    return result;
}

char* _Nonnull _prop_get_Project_title(IEGenCObject cself){
    auto ctocxxcself = static_cast<iegen::example::Project*>(cself.ptr);
    const auto& result = ctocxxcself->title();
    auto cxxtocresult = strdup(result.data());
    return cxxtocresult;
}

void _func_Project_addTask(IEGenCObject cself, IEGenCObject task, IEGenCErrorObj* _Nonnull err){
    
    auto ctocxxtask = static_cast<iegen::example::Task*>(task.ptr);
  
    
    auto ctocxxcself = static_cast<iegen::example::Project*>(cself.ptr);
    try {
        ctocxxcself->addTask(ctocxxtask);
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}

IEGenCDataArray _func_Project_tasks(IEGenCObject cself, IEGenCErrorObj* _Nonnull err){
    
    auto ctocxxcself = static_cast<iegen::example::Project*>(cself.ptr);
    try {
        const auto& result = ctocxxcself->tasks();
        auto _data_cxxtocresult = new IEGenCObject [result.size()];
        IEGenCDataArray cxxtocresult = { _data_cxxtocresult, static_cast<long long>(result.size()) };
        for (int _i_result = 0; _i_result < result.size(); ++_i_result) {
            auto& value_result = result[_i_result];
            
            char* type_value_result = strdup("iegen::example::Task");
            auto value_ptr_value_result = const_cast<iegen::example::Task*>(value_result);
            IEGenCObject cxxtocvalue_result = {type_value_result, value_ptr_value_result};
            _data_cxxtocresult[_i_result] = cxxtocvalue_result;
        }
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    IEGenCDataArray result {};
    return result;
}
