#ifndef _C_containers_WRAPPER_
#define _C_containers_WRAPPER_ 

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Item(void* _Nonnull cself);
    int _prop_get_Item_value(void* _Nonnull cself);
    void _prop_set_Item_value(void* _Nonnull cself, int value);

    void* _Nonnull create_Item(int _value);
    void release_Containers(void* _Nonnull cself);
    void* _Nonnull create_Containers();
    void _func_Containers_addStringPair(void* _Nonnull cself , CDataPair info);
    void _func_Containers_addIntMap(void* _Nonnull cself , CDataMap info);
    void _func_Containers_addStringMap(void* _Nonnull cself , CDataMap info);
    void _func_Containers_addIntPair(void* _Nonnull cself , CDataPair info);
    CDataPair _func_Containers_getStringPair(void* _Nonnull cself );
    CDataMap _func_Containers_getStringMap(void* _Nonnull cself );
    CDataMap _func_Containers_getIntMap(void* _Nonnull cself );
    CDataMap _func_Containers_getMap(void* _Nonnull cself );
    void _func_Containers_addIntVector(void* _Nonnull cself , CDataArray v);
    void _func_Containers_addStringVector(void* _Nonnull cself , CDataArray v);
    CDataArray _func_Containers_getStringVector(void* _Nonnull cself );
    CDataArray _func_Containers_getIntVector(void* _Nonnull cself );
#if __cplusplus
}
#endif
#endif /* ifndef _C_containers_WRAPPER_ */