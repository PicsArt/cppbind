#ifndef _C_rhombus_WRAPPER_
#define _C_rhombus_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Rhombus(void* _Nonnull cself);
    void* _Nonnull create_Rhombus(double diagonal1, double diagonal2);
#if __cplusplus
}
#endif
#endif /* ifndef _C_rhombus_WRAPPER_ */