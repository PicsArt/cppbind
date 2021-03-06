/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 06/09/2022-13:05.
 * Please do not change it manually.
 */

#ifndef _SWIFT_WRAPPERS_EXCEPTIONS_C_SWIFT_CUSTOM_EXCEPTIONS_H_
#define _SWIFT_WRAPPERS_EXCEPTIONS_C_SWIFT_CUSTOM_EXCEPTIONS_H_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_CppbindExample_SimpleBaseException(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_SimpleBaseException(int err_num, CppBindCObject* _Nonnull cppbind_err);
    int _func_CppbindExample_SimpleBaseException_errNum(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject create_CppbindExample_SimpleChildException(int err_num, CppBindCObject* _Nonnull cppbind_err);
    int _func_CppbindExample_SimpleChildException_errNum(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _SWIFT_WRAPPERS_EXCEPTIONS_C_SWIFT_CUSTOM_EXCEPTIONS_H_ */
