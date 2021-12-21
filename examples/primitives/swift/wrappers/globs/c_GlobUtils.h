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

#ifndef _C_GlobUtils_WRAPPER_
#define _C_GlobUtils_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    
    char* _Nonnull _func__concat(char* _Nonnull str1, char* _Nonnull str2, ErrorObj* _Nonnull err);

    int _func__maxInt(int  arg0, int  arg1, ErrorObj* _Nonnull err);

    char* _Nonnull _func__maxString(char* _Nonnull arg0, char* _Nonnull arg1, ErrorObj* _Nonnull err);

    CDataPair _func_IegenExample_makePairProjectProject(CObject  arg0, CObject  arg1, ErrorObj* _Nonnull err);

    CDataPair _func_IegenExample_makePairRootProject(CObject  arg0, CObject  arg1, ErrorObj* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_GlobUtils_WRAPPER_ */