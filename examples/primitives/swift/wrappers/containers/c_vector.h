#ifndef _C_vector_WRAPPER_
#define _C_vector_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_VectorItem(void* _Nonnull cself);
    int _prop_get_VectorItem_value(void* _Nonnull cself);
    void _prop_set_VectorItem_value(void* _Nonnull cself, int value);

    void* _Nonnull create_VectorItem(int _value);
    void release_VectorExamples(void* _Nonnull cself);
    void* _Nonnull create_VectorExamples();
    void _func_VectorExamples_addIntVector(void* _Nonnull cself , CDataArray v);
    void _func_VectorExamples_addObjVector(void* _Nonnull cself , CDataArray v);
    void _func_VectorExamples_addStringVector(void* _Nonnull cself , CDataArray v);
    CDataArray _func_VectorExamples_getStringVector(void* _Nonnull cself );
    CDataArray _func_VectorExamples_getObjVector(void* _Nonnull cself );
    CDataArray _func_VectorExamples_getIntVector(void* _Nonnull cself );
#if __cplusplus
}
#endif
#endif /* ifndef _C_vector_WRAPPER_ */