/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 02/03/2022-13:55.
 * Please do not change it manually.
 */

#ifndef _C_size_buffer_WRAPPER_
#define _C_size_buffer_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_SizeUsage(IEGenCObject cself, bool owner);
    IEGenCDataPair _func_SizeUsage_multiplyBy(IEGenCDataPair  size, int  n, IEGenCObject* _Nonnull err);
    IEGenCDataPair _func_SizeUsage_doubleSizeF(IEGenCDataPair  resolution, IEGenCObject* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_size_buffer_WRAPPER_ */
