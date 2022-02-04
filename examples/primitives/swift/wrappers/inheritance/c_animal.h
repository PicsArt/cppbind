/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/01/2022-13:24.
 * Please do not change it manually.
 */

#ifndef _C_animal_WRAPPER_
#define _C_animal_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_AnimalImpl(IEGenCObject cself, bool owner);

    IEGenCObject create_Animal(IEGenCErrorObj* _Nonnull err);
    char* _Nonnull _func_Animal_typeName(IEGenCObject cself, IEGenCErrorObj* _Nonnull err);
    void release_TerrestrialAnimalImpl(IEGenCObject cself, bool owner);

    IEGenCObject create_TerrestrialAnimal(IEGenCErrorObj* _Nonnull err);
    char* _Nonnull _func_TerrestrialAnimal_typeName(IEGenCObject cself, IEGenCErrorObj* _Nonnull err);
    void release_AquaticAnimal(IEGenCObject cself, bool owner);

    IEGenCObject create_AquaticAnimal(IEGenCErrorObj* _Nonnull err);
    char* _Nonnull _func_AquaticAnimal_typeName(IEGenCObject cself, IEGenCErrorObj* _Nonnull err);

    IEGenCObject create_Frog(IEGenCErrorObj* _Nonnull err);
    char* _Nonnull _func_Frog_typeName(IEGenCObject cself, IEGenCErrorObj* _Nonnull err);
    void release_AnimalUsage(IEGenCObject cself, bool owner);

    IEGenCObject create_AnimalUsage(IEGenCErrorObj* _Nonnull err);
    char* _Nonnull _func_AnimalUsage_getAnimalTypeName(IEGenCObject  animal, IEGenCErrorObj* _Nonnull err);
    char* _Nonnull _func_AnimalUsage_getAquaticAnimalTypeName(IEGenCObject  animal, IEGenCErrorObj* _Nonnull err);
    IEGenCObject _func_AnimalUsage_getAnimal(IEGenCObject cself, IEGenCErrorObj* _Nonnull err);
    IEGenCObject _func_AnimalUsage_getAquaticAnimal(IEGenCObject cself, IEGenCErrorObj* _Nonnull err);
    IEGenCObject _func_AnimalUsage_getFrog(IEGenCObject cself, IEGenCErrorObj* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_animal_WRAPPER_ */
