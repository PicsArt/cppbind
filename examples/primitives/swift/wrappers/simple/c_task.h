/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/26/2021-12:15.
 * Please do not change it manually.
 */

#ifndef _C_task_WRAPPER_
#define _C_task_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Task(CDataObj cself);

    CDataObj create_Task(char* _Nonnull title);
    char* _Nonnull _prop_get_Task_title(CDataObj cself);
    void _func_Task_setTitle(CDataObj cself, char* _Nonnull title, ErrorObj* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_task_WRAPPER_ */