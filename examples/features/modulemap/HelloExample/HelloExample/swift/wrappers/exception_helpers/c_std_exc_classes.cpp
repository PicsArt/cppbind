/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/02/2021-10:34.
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
    delete static_cast<std::exception*>(cself);
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
void release_StdLogicError(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}
void release_StdRuntimeError(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}
void release_StdDomainError(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}
void release_StdInvalidArgument(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}
void release_StdLengthError(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}
void release_StdOutOfRange(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}
void release_StdRangeError(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}
void release_StdOverflowError(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}
void release_StdUnderflowError(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}
void release_StdBadAlloc(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}
void release_StdBadCast(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}
void release_StdBadTypeId(void* _Nonnull cself) {
    delete static_cast<std::exception*>(cself);
}