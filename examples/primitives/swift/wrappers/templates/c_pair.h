/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/06/2021-14:37.
 * Please do not change it manually.
 */

#ifndef _C_pair_WRAPPER_
#define _C_pair_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_PairEmployee(CObject cself);

    CObject create_PairEmployee(char* _Nonnull first, CObject second, ErrorObj* _Nonnull err);
    char* _Nonnull _prop_get_PairEmployee_first(CObject cself);
    CObject _prop_get_PairEmployee_second(CObject cself);
    void release_PairStudent(CObject cself);

    CObject create_PairStudent(char* _Nonnull first, CObject second, ErrorObj* _Nonnull err);
    char* _Nonnull _prop_get_PairStudent_first(CObject cself);
    CObject _prop_get_PairStudent_second(CObject cself);
#if __cplusplus
}
#endif
#endif /* ifndef _C_pair_WRAPPER_ */