/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/31/2022-10:17.
 * Please do not change it manually.
 */

#include <stdlib.h>
#include <string.h>
#include <cxxabi.h>
#include <memory>
#include "swift/wrappers/exceptions/c_throw_exceptions.h"
#include "cxx/exceptions/exceptions.hpp"
#include "cxx/simple/task.hpp"

using namespace iegen::exceptions;


void _func_IegenExceptions_throwExc(bool do_throw, IEGenCErrorObj* _Nonnull err) {
    
    try {
        throwExc(do_throw);
    }catch (const std::invalid_argument& e) {
        err->err_type = 1;
        err->err_ptr = new std::invalid_argument(e);
    }
    catch (const std::exception& e) {
        err->err_type = 2;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}
void release_ThrowExc(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::exceptions::ThrowExc*>(cself.ptr);
    }
}

IEGenCObject create_ThrowExc(bool do_throw, IEGenCErrorObj* _Nonnull err){
    
    try {
        auto this_object = new iegen::exceptions::ThrowExc(do_throw);
        return {strdup("iegen::exceptions::ThrowExc"), this_object};
    }catch (const std::invalid_argument& e) {
        err->err_type = 1;
        err->err_ptr = new std::invalid_argument(e);
    }
    catch (const std::exception& e) {
        err->err_type = 2;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    IEGenCObject result {};
    return result;
}

int _func_ThrowExc_getByKey(IEGenCDataMap m, int key, IEGenCErrorObj* _Nonnull err){
    std::map<int, int> ctocxxm;

    for (size_t _i_m = 0; _i_m < m.size; ++_i_m) {
        auto ktmp_m = reinterpret_cast<int*>(m.keys)[_i_m];
        auto vtmp_m = reinterpret_cast<int*>(m.values)[_i_m];
        
        
        ctocxxm.insert({ ktmp_m, vtmp_m });
    }
  
    
  
    try {
        const auto& result = iegen::exceptions::ThrowExc::getByKey(ctocxxm, key);
        
        return result;
    }catch (const std::out_of_range& e) {
        err->err_type = 1;
        err->err_ptr = new std::out_of_range(e);
    }catch (const iegen::example::SystemError& e) {
        err->err_type = 2;
        err->err_ptr = new iegen::example::SystemError(e);
    }
    catch (const std::exception& e) {
        err->err_type = 3;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    int result {};
    return result;
}

char* _Nonnull _func_ThrowExc_throwsWithReturnValueString(IEGenCErrorObj* _Nonnull err){
    try {
        const auto& result = iegen::exceptions::ThrowExc::throwsWithReturnValueString();
        auto cxxtocresult = strdup(result.data());
        return cxxtocresult;
    }catch (const std::invalid_argument& e) {
        err->err_type = 1;
        err->err_ptr = new std::invalid_argument(e);
    }
    catch (const std::exception& e) {
        err->err_type = 2;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    char* result {};
    return result;
}

IEGenCObject _func_ThrowExc_throwsWithReturnValuePtr(IEGenCErrorObj* _Nonnull err){
    try {
        const auto& result = iegen::exceptions::ThrowExc::throwsWithReturnValuePtr();
        
        char* type_result = strdup("iegen::example::Task");
        IEGenCObject cxxtocresult = {type_result, const_cast<iegen::example::Task*>(result)};
        return cxxtocresult;
    }catch (const std::invalid_argument& e) {
        err->err_type = 1;
        err->err_ptr = new std::invalid_argument(e);
    }
    catch (const std::exception& e) {
        err->err_type = 2;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    IEGenCObject result {};
    return result;
}

char* _Nonnull _prop_get_ThrowExc_prop(IEGenCObject cself){
    auto ctocxxcself = static_cast<iegen::exceptions::ThrowExc*>(cself.ptr);
    const auto& result = ctocxxcself->prop();
    auto cxxtocresult = strdup(result.data());
    return cxxtocresult;
}

void _prop_set_ThrowExc_prop(IEGenCObject cself, char* _Nonnull s){
    
    auto ctocxxcself = static_cast<iegen::exceptions::ThrowExc*>(cself.ptr);
    auto ctocxxs = std::string(s);
    free(s);
    ctocxxcself->setProp(ctocxxs);
}

