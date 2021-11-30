/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 11/29/2021-14:07.
 * Please do not change it manually.
 */

#ifndef _C_usage_WRAPPER_
#define _C_usage_WRAPPER_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_GeometricFigure(CDataObj cself);

    CDataObj create_GeometricFigure(CDataObj p);
    CDataObj _prop_get_GeometricFigure_parallelogram(CDataObj cself);

    void _prop_set_GeometricFigure_parallelogram(CDataObj cself, CDataObj p);

    void release_MyVehicle(CDataObj cself);

    CDataObj create_MyVehicle(CDataObj v);
    CDataObj _prop_get_MyVehicle_vehicle(CDataObj cself);

    void _prop_set_MyVehicle_vehicle(CDataObj cself, CDataObj v);

    void release_MyBicycle(CDataObj cself);

    CDataObj create_MyBicycle(CDataObj b);
    CDataObj _prop_get_MyBicycle_bicycle(CDataObj cself);

    void _prop_set_MyBicycle_bicycle(CDataObj cself, CDataObj b);

    void release_MyCalendar(CDataObj cself);

    CDataObj create_MyCalendar(CDataArray events);
    void _func_MyCalendar_addEvent(CDataObj cself, CDataObj  e, ErrorObj* _Nonnull err);
    CDataArray _prop_get_MyCalendar_events(CDataObj cself);
#if __cplusplus
}
#endif
#endif /* ifndef _C_usage_WRAPPER_ */