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

#ifndef _C_fruits_WRAPPER_
#define _C_fruits_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_Fruit(CObject cself, bool owner);
    unsigned int _prop_get_Fruit_type(CObject cself);
    void release_Apple(CObject cself, bool owner);

    CObject create_Apple(ErrorObj* _Nonnull err);
    unsigned int _prop_get_Apple_type(CObject cself);
    void release_Pineapple(CObject cself, bool owner);

    CObject create_Pineapple(ErrorObj* _Nonnull err);
    unsigned int _prop_get_Pineapple_type(CObject cself);
    void release_Fruits(CObject cself, bool owner);

    CObject create_Fruits(CDataArray fruits, ErrorObj* _Nonnull err);
    CDataArray _prop_get_Fruits_fruitsApple(CObject cself);
    CDataArray _prop_get_Fruits_fruitsPineapple(CObject cself);
    CDataArray _prop_get_Fruits_allFruitsApplePineapple(CObject cself);

    void _prop_set_Fruits_allFruitsApplePineapple(CObject cself, CDataArray arg0);

#if __cplusplus
}
#endif
#endif /* ifndef _C_fruits_WRAPPER_ */
