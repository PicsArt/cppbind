/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 03/28/2022-13:29.
 * Please do not change it manually.
 */

#ifndef _C_number_WRAPPER_
#define _C_number_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_IegenExample_NumberInt(IEGenCObject cself, bool owner);

    IEGenCObject create_IegenExample_NumberInt(int n, IEGenCObject* _Nonnull iegen_err);
    int _func_IegenExample_NumberInt_toInt(IEGenCObject cself, IEGenCObject* _Nonnull iegen_err);
    int _prop_get_IegenExample_NumberInt_num(IEGenCObject cself);
    void _prop_set_IegenExample_NumberInt_num(IEGenCObject cself, int num);

    void release_IegenExample_NumberDouble(IEGenCObject cself, bool owner);

    IEGenCObject create_IegenExample_NumberDouble(double n, IEGenCObject* _Nonnull iegen_err);
    int _func_IegenExample_NumberDouble_toInt(IEGenCObject cself, IEGenCObject* _Nonnull iegen_err);
    double _prop_get_IegenExample_NumberDouble_num(IEGenCObject cself);
    void _prop_set_IegenExample_NumberDouble_num(IEGenCObject cself, double num);

#if __cplusplus
}
#endif
#endif /* ifndef _C_number_WRAPPER_ */
