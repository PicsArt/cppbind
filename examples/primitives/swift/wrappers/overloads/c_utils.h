#ifndef _C_utils_WRAPPER_
#define _C_utils_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Utils(void* _Nonnull cself);
    int _func_Utils_sum(int first, int second);
    float _func_Utils_sum_1(float first, float second);
#if __cplusplus
}
#endif
#endif /* ifndef _C_utils_WRAPPER_ */