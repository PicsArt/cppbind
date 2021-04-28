#ifndef _C_rectangle_WRAPPER_
#define _C_rectangle_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Rectangle(void* _Nonnull cself);
    void* _Nonnull create_Rectangle(double length, double width);
    double _prop_get_Rectangle_area(void* _Nonnull cself);
    double _func_Rectangle_perimeter(void* _Nonnull cself );
    double _prop_get_Rectangle_length(void* _Nonnull cself);
    double _prop_get_Rectangle_width(void* _Nonnull cself);
#if __cplusplus
}
#endif
#endif /* ifndef _C_rectangle_WRAPPER_ */