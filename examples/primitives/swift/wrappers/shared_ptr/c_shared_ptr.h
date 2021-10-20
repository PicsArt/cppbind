/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 09/23/2021-14:11.
 * Please do not change it manually.
 */

#ifndef _C_shared_ptr_WRAPPER_
#define _C_shared_ptr_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Car(void* _Nonnull cself);

    void* _Nonnull create_Car(int cost);
    int _prop_get_Car_cost(void* _Nonnull cself);
    void _func_Car_setCostWithCarSharedPtr(void* _Nonnull cself, void* _Nonnull sp, ErrorObj* _Nonnull err);
    void* _Nonnull _func_Car_getNewCarSharedPtr(void* _Nonnull cself, ErrorObj* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_shared_ptr_WRAPPER_ */