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

#ifndef _C_pair_WRAPPER_
#define _C_pair_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_IegenExample_PairEmployee(IEGenCObject cself, bool owner);

    IEGenCObject create_IegenExample_PairEmployee(char* _Nonnull first, IEGenCObject second, IEGenCObject* _Nonnull iegen_err);
    char* _Nonnull _prop_get_IegenExample_PairEmployee_first(IEGenCObject cself, IEGenCObject* _Nonnull iegen_err);
    IEGenCObject _prop_get_IegenExample_PairEmployee_second(IEGenCObject cself, IEGenCObject* _Nonnull iegen_err);
    void release_IegenExample_PairStudent(IEGenCObject cself, bool owner);

    IEGenCObject create_IegenExample_PairStudent(char* _Nonnull first, IEGenCObject second, IEGenCObject* _Nonnull iegen_err);
    char* _Nonnull _prop_get_IegenExample_PairStudent_first(IEGenCObject cself, IEGenCObject* _Nonnull iegen_err);
    IEGenCObject _prop_get_IegenExample_PairStudent_second(IEGenCObject cself, IEGenCObject* _Nonnull iegen_err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_pair_WRAPPER_ */
