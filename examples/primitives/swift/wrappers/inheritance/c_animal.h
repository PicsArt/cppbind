/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 05/30/2022-14:02.
 * Please do not change it manually.
 */

#ifndef _SWIFT_WRAPPERS_INHERITANCE_C_ANIMAL_H_
#define _SWIFT_WRAPPERS_INHERITANCE_C_ANIMAL_H_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_CppbindExample_AnimalImpl(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_Animal(CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_Animal_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    bool _func_CppbindExample_Animal_isEqualTo(CppBindCObject cself, CppBindCObject  a, CppBindCObject* _Nonnull cppbind_err);
    void release_CppbindExample_TerrestrialAnimalImpl(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_TerrestrialAnimal(CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_TerrestrialAnimal_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    void release_CppbindExample_AquaticAnimal(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_AquaticAnimal(CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_AquaticAnimal_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject create_CppbindExample_Frog(CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_Frog_typeName(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject create_CppbindExample_LittleFrog(CppBindCObject* _Nonnull cppbind_err);
    void release_CppbindExample_AnimalUsage(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_AnimalUsage(CppBindCObject* _Nonnull cppbind_err);

    CppBindCObject create_CppbindExample_AnimalUsage_1(CppBindCObject little_frog, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_AnimalUsage_getAnimalTypeName(CppBindCObject  animal, CppBindCObject* _Nonnull cppbind_err);
    char* _Nonnull _func_CppbindExample_AnimalUsage_getAquaticAnimalTypeName(CppBindCObject  animal, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_AnimalUsage_getAnimal(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_AnimalUsage_getAquaticAnimal(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_AnimalUsage_getFrog(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_AnimalUsage_getLittleFrog(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _SWIFT_WRAPPERS_INHERITANCE_C_ANIMAL_H_ */
