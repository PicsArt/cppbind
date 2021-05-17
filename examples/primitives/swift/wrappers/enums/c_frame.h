#ifndef _C_frame_WRAPPER_
#define _C_frame_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Frame(void* _Nonnull cself);
    void* _Nonnull create_Frame();
    unsigned int _prop_get_Frame_backgroundColor(void* _Nonnull cself);
    void _prop_set_Frame_backgroundColor(void* _Nonnull cself, unsigned int backgroundColor);

#if __cplusplus
}
#endif
#endif /* ifndef _C_frame_WRAPPER_ */