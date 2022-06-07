/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/25/2022-14:38.
 * Please do not change it manually.
 */

#ifndef _SWIFT_WRAPPERS_INHERITANCE_C_DOCTOR_H_
#define _SWIFT_WRAPPERS_INHERITANCE_C_DOCTOR_H_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_CppbindExample_Doctor(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_Doctor(char* _Nonnull doctor_name, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject create_CppbindExample_Surgeon(char* _Nonnull surgeon_name, CppBindCObject* _Nonnull cppbind_err);
    void release_CppbindExample_GoodVirtualDoctorImpl(CppBindCObject cself, bool owner);
    void release_CppbindExample_GoodDoctor(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_GoodDoctor(char* _Nonnull doctor_name, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject create_CppbindExample_GoodYoungDoctor(char* _Nonnull doctor_name, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject create_CppbindExample_GoodOldDoctor(char* _Nonnull doctor_name, CppBindCObject* _Nonnull cppbind_err);
    void release_CppbindExample_DoctorInfo(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_DoctorInfo(CppBindCObject s, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject create_CppbindExample_DoctorInfo_1(CppBindCObject d, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_DoctorInfo_getDoctorName(CppBindCObject cself, CppBindCObject  d, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_DoctorInfo_getSurgeonName(CppBindCObject cself, CppBindCObject  s, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_DoctorInfo_getDoctor(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_DoctorInfo_getGoodDoctor(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_DoctorInfo_getGoodVirtualDoctor(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_DoctorInfo_getGoodDoctorName(CppBindCObject cself, CppBindCObject  d, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _SWIFT_WRAPPERS_INHERITANCE_C_DOCTOR_H_ */