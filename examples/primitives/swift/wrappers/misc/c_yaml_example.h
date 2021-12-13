/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/08/2021-11:54.
 * Please do not change it manually.
 */

#ifndef _C_yaml_example_WRAPPER_
#define _C_yaml_example_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_WithExternalAPIComments(CObject cself, bool owner);

    CObject create_WithExternalAPIComments(char* _Nonnull s, ErrorObj* _Nonnull err);
    int _func_WithExternalAPIComments_retInt(int  n, ErrorObj* _Nonnull err);
    char* _Nonnull _prop_get_WithExternalAPIComments_str(CObject cself);

    void _prop_set_WithExternalAPIComments_str(CObject cself, char* _Nonnull s);

    int _func_WithExternalAPIComments_maxInt(int  arg0, int  arg1, ErrorObj* _Nonnull err);
    char* _Nonnull _func_WithExternalAPIComments_maxString(char* _Nonnull arg0, char* _Nonnull arg1, ErrorObj* _Nonnull err);
    void release_AdderInt(CObject cself, bool owner);
    int _func_AdderInt_add(int  a, int  b, ErrorObj* _Nonnull err);
    void release_AdderDouble(CObject cself, bool owner);
    double _func_AdderDouble_add(double  a, double  b, ErrorObj* _Nonnull err);
#if __cplusplus
}
#endif
#endif /* ifndef _C_yaml_example_WRAPPER_ */