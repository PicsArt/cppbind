/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/21/2021-09:26.
 * Please do not change it manually.
 */

#ifndef _C_intarray_WRAPPER_
#define _C_intarray_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_IntArrayImpl(CObject cself, bool owner);

    CObject create_IntArray(ErrorObj* _Nonnull err);


    int _func_IntArray_operator_getitem_(CObject cself, int  i);


    void _func_IntArray_operator_setitem_(CObject cself, int i, int value);


    int _func_IntArray_operator_getitem__1(CObject cself, char* _Nonnull i);



    int _func_IntArray_operator_getitem__2(CObject cself, double  i);

#if __cplusplus
}
#endif
#endif /* ifndef _C_intarray_WRAPPER_ */