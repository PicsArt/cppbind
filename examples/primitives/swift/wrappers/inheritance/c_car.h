/**
 * ,--.,------. ,----.   ,------.,--.  ,--.
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  |
 * |  ||  `--, |  | .---.|  `--, |  |' '  |
 * |  ||  `---.'  '--'  ||  `---.|  | `   |
 * `--'`------' `------' `------'`--'  `--'
 * 
 * This file is generated by iegen on 12/06/2021-09:12.
 * Please do not change it manually.
 */

#ifndef _C_car_WRAPPER_
#define _C_car_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_MyCar(void* _Nonnull cself);

    void* _Nonnull create_MyCar(int numberOfSeats, ErrorObj* _Nonnull err);
    char* _Nonnull _func_MyCar_type(void* _Nonnull cself, ErrorObj* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_car_WRAPPER_ */