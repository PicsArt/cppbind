#ifndef _C_square_WRAPPER_
#define _C_square_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Square(void* _Nonnull cself);
    void* _Nonnull create_Square(double side);
    double _prop_get_Square_area(void* _Nonnull cself);
    double _func_Square_perimeter(void* _Nonnull cself );
#if __cplusplus
}
#endif
#endif /* ifndef _C_square_WRAPPER_ */