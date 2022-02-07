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
#include "swift/wrappers/exceptions/c_misc_exceptions.h"
#include "cxx/exceptions/exceptions.hpp"

using namespace iegen::exceptions;

void release_Integer(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::exceptions::Integer*>(cself.ptr);
    }
}

IEGenCObject create_Integer(int n, IEGenCErrorObj* _Nonnull err){
    
    try {
        auto this_object = new iegen::exceptions::Integer(n);
        return {strdup("iegen::exceptions::Integer"), this_object};
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

int _prop_get_Integer_value(IEGenCObject cself){
    auto ctocxxcself = static_cast<iegen::exceptions::Integer*>(cself.ptr);
    const auto& result = ctocxxcself->value();
    
    return result;
}
void release_MiscExc(IEGenCObject cself, bool owner) {
    free(cself.type);
    if (owner) {
        delete static_cast<iegen::exceptions::MiscExc*>(cself.ptr);
    }
}

IEGenCObject _func_MiscExc_returnInteger(bool do_throw, IEGenCErrorObj* _Nonnull err){
    
  
    try {
        const auto& result = iegen::exceptions::MiscExc::returnInteger(do_throw);
        
        char* type_result = strdup("iegen::exceptions::Integer");
        auto value_ptr_result = const_cast<iegen::exceptions::Integer*>(result);
        IEGenCObject cxxtocresult = {type_result, value_ptr_result};
        return cxxtocresult;
    }catch (const std::out_of_range& e) {
        err->err_type = 1;
        err->err_ptr = new std::out_of_range(e);
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

void _func_MiscExc_raiseErrorByType(char* _Nonnull err_type, IEGenCErrorObj* _Nonnull err){
    auto ctocxxerr_type = std::string(err_type);
    free(err_type);
  
    try {
        iegen::exceptions::MiscExc::raiseErrorByType(ctocxxerr_type);
    }catch (const std::runtime_error& e) {
        err->err_type = 1;
        err->err_ptr = new std::runtime_error(e);
    }catch (const iegen::example::FileError& e) {
        err->err_type = 2;
        err->err_ptr = new iegen::example::FileError(e);
    }catch (const iegen::example::SystemError& e) {
        err->err_type = 3;
        err->err_ptr = new iegen::example::SystemError(e);
    }catch (const iegen::example::SimpleChildException& e) {
        err->err_type = 4;
        err->err_ptr = new iegen::example::SimpleChildException(e);
    }catch (const iegen::example::SimpleBaseException& e) {
        err->err_type = 5;
        err->err_ptr = new iegen::example::SimpleBaseException(e);
    }catch (const std::exception& e) {
        err->err_type = 6;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
}
