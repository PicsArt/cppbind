/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/31/2022-10:44.
 * Please do not change it manually.
 */

#ifndef _C_queue_int_shared_WRAPPER_
#define _C_queue_int_shared_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_QueueIntShared(CObject cself, bool owner);

    CObject create_QueueIntShared(ErrorObj* _Nonnull err);
    void _func_QueueIntShared_push_back(CObject cself, int  element, ErrorObj* _Nonnull err);
    int _func_QueueIntShared_get_size(CObject cself, ErrorObj* _Nonnull err);
    void release_QueueIntSharedUsage(CObject cself, bool owner);

    CObject create_QueueIntSharedUsage(CObject q, ErrorObj* _Nonnull err);
    int _func_QueueIntSharedUsage_getSize(CObject  q, ErrorObj* _Nonnull err);
    int _func_QueueIntSharedUsage_getLastElement(CObject  q, ErrorObj* _Nonnull err);
    int _func_QueueIntSharedUsage_getFirstElement(CObject  q, ErrorObj* _Nonnull err);
    CObject _func_QueueIntSharedUsage_getInvQueue(CDataArray  v, ErrorObj* _Nonnull err);
    CObject _func_QueueIntSharedUsage_getSavedQueue(CObject cself, ErrorObj* _Nonnull err);
    CObject _prop_get_QueueIntSharedUsage_saved_queue(CObject cself);
#if __cplusplus
}
#endif
#endif /* ifndef _C_queue_int_shared_WRAPPER_ */
