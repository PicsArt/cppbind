/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 09/09/2022-13:51.
 * Please do not change it manually.
 */

#ifndef _SWIFT_WRAPPERS_STL_TYPES_C_SWIFT_STD_OPTIONAL_H_
#define _SWIFT_WRAPPERS_STL_TYPES_C_SWIFT_STD_OPTIONAL_H_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    
    CppBindOptionalInt _func_CppbindExample_mulInt(CppBindOptionalInt  a, int  b, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalFloat _func_CppbindExample_mulFloat(CppBindOptionalFloat  a, float  b, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalDouble _func_CppbindExample_mulDouble(CppBindOptionalDouble  a, double  b, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalCShort _func_CppbindExample_mulCShort(CppBindOptionalCShort  a, short  b, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalCLong _func_CppbindExample_mulLong(CppBindOptionalCLong  a, long  b, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalBool _func_CppbindExample_reverseBool(CppBindOptionalBool  a, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalUInt _func_CppbindExample_mulUnsignedInt(CppBindOptionalUInt  a, unsigned int  b, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalCUnsignedLong _func_CppbindExample_mulUnsignedLong(CppBindOptionalCUnsignedLong  a, unsigned long  b, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalCLongLong _func_CppbindExample_mulLongLong(CppBindOptionalCLongLong  a, long long  b, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalCUnsignedChar _func_CppbindExample_mulUnsignedChar(CppBindOptionalCUnsignedChar  a, unsigned char  b, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalCharacter _func_CppbindExample_charToUpper(CppBindOptionalCharacter  a, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalString _func_CppbindExample_concatString(CppBindOptionalString  first, char* _Nonnull second, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalArray _func_CppbindExample_concat(CppBindOptionalArray  v, char* _Nonnull s, CppBindCObject* _Nonnull cppbind_err);

    CppBindCDataArray _func_CppbindExample_concat2(CppBindCDataArray  v, char* _Nonnull s, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalInt _func_CppbindExample_sameColor(CppBindOptionalInt  color, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalInt _func_CppbindExample_same_templateOptionalInt(CppBindOptionalInt  a, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalString _func_CppbindExample_same_templateOptionalString(CppBindOptionalString  a, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalPair _func_CppbindExample_samePair(CppBindOptionalPair  pair, CppBindCObject* _Nonnull cppbind_err);

    CppBindOptionalMap _func_CppbindExample_sameMap(CppBindOptionalMap  map, CppBindCObject* _Nonnull cppbind_err);
    void release_CppbindExample_FrameUsage(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_FrameUsage(CppBindCObject* _Nonnull cppbind_err);
    CppBindOptionalObject _func_CppbindExample_FrameUsage_sameFrame(CppBindCObject cself, CppBindOptionalObject  frame, CppBindCObject* _Nonnull cppbind_err);
    CppBindOptionalObject _func_CppbindExample_FrameUsage_getFrame(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _SWIFT_WRAPPERS_STL_TYPES_C_SWIFT_STD_OPTIONAL_H_ */