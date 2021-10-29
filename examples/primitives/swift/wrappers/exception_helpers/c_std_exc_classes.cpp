/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 10/22/2021-08:40.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/exception_helpers/c_std_exc_classes.h"
#include <stdexcept>
#include <new>
#include <typeinfo>


using namespace std;

void release_StdException(void* _Nonnull cself) {
    delete dynamic_cast<std::exception*>(static_cast<std::exception*>(cself));
}

const char * _Nonnull _func_StdException_what(void* _Nonnull cself, ErrorObj* _Nonnull err){
    
    auto c_to_cxx_cself = static_cast<std::exception*>(cself);
    try {
        const auto& result = c_to_cxx_cself->what();
        
        return result;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    const char * result;
    return result;
}
void release_StdBadCast(void* _Nonnull cself) {
    delete dynamic_cast<std::bad_cast*>(static_cast<std::exception*>(cself));
}
void release_StdBadTypeId(void* _Nonnull cself) {
    delete dynamic_cast<std::bad_typeid*>(static_cast<std::exception*>(cself));
}
void release_StdBadAlloc(void* _Nonnull cself) {
    delete dynamic_cast<std::bad_alloc*>(static_cast<std::exception*>(cself));
}
void release_StdLogicError(void* _Nonnull cself) {
    delete dynamic_cast<std::logic_error*>(static_cast<std::exception*>(cself));
}
void release_StdDomainError(void* _Nonnull cself) {
    delete dynamic_cast<std::domain_error*>(static_cast<std::exception*>(cself));
}
void release_StdInvalidArgument(void* _Nonnull cself) {
    delete dynamic_cast<std::invalid_argument*>(static_cast<std::exception*>(cself));
}
void release_StdLengthError(void* _Nonnull cself) {
    delete dynamic_cast<std::length_error*>(static_cast<std::exception*>(cself));
}
void release_StdOutOfRange(void* _Nonnull cself) {
    delete dynamic_cast<std::out_of_range*>(static_cast<std::exception*>(cself));
}
void release_StdRuntimeError(void* _Nonnull cself) {
    delete dynamic_cast<std::runtime_error*>(static_cast<std::exception*>(cself));
}
void release_StdRangeError(void* _Nonnull cself) {
    delete dynamic_cast<std::range_error*>(static_cast<std::exception*>(cself));
}
void release_StdOverflowError(void* _Nonnull cself) {
    delete dynamic_cast<std::overflow_error*>(static_cast<std::exception*>(cself));
}
void release_StdUnderflowError(void* _Nonnull cself) {
    delete dynamic_cast<std::underflow_error*>(static_cast<std::exception*>(cself));
}