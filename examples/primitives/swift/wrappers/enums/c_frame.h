/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/31/2022-08:51.
 * Please do not change it manually.
 */

#ifndef _C_frame_WRAPPER_
#define _C_frame_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Frame(IEGenCObject cself, bool owner);

    IEGenCObject create_Frame(IEGenCErrorObj* _Nonnull err);
    unsigned int _prop_get_Frame_backgroundColor(IEGenCObject cself);
    void _prop_set_Frame_backgroundColor(IEGenCObject cself, unsigned int backgroundColor);

    unsigned int _prop_get_Frame_backgroundColorShade(IEGenCObject cself);
    void _prop_set_Frame_backgroundColorShade(IEGenCObject cself, unsigned int backgroundColorShade);

#if __cplusplus
}
#endif
#endif /* ifndef _C_frame_WRAPPER_ */
