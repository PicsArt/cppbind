/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/12/2022-10:26.
 * Please do not change it manually.
 */

#ifndef _C_shared_ptr_WRAPPER_
#define _C_shared_ptr_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Example_Car(CppBindCObject cself, bool owner);

    CppBindCObject create_Example_Car(int cost, CppBindCObject* _Nonnull cppbind_err);
    int _prop_get_Example_Car_cost(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    void _func_Example_Car_setCostWithCarSharedPtr(CppBindCObject cself, CppBindCObject  sp, CppBindCObject* _Nonnull cppbind_err);
    void _func_Example_Car_setCostWithCar(CppBindCObject cself, CppBindCObject  sp, CppBindCObject* _Nonnull cppbind_err);
    void _func_Example_Car_setCostWithCarConstSharedPtr(CppBindCObject cself, CppBindCObject  sp, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_Example_Car_makeConstSharedPtr(CppBindCObject cself, CppBindCObject  sp, CppBindCObject* _Nonnull cppbind_err);
    void _func_Example_Car_setCostWithCarRef(CppBindCObject cself, CppBindCObject  sp, CppBindCObject* _Nonnull cppbind_err);
    void _func_Example_Car_setCostWithCarPtr(CppBindCObject cself, CppBindCObject  sp, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_Example_Car_getNewCarSharedPtr(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    void release_Example_CarUsage(CppBindCObject cself, bool owner);

    CppBindCObject create_Example_CarUsage(CppBindCObject car, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_Example_CarUsage_getCar(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_shared_ptr_WRAPPER_ */
