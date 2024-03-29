/**
 *   ______ .______   .______   .______    __  .__   __.  _______  
 *  /      ||   _  \  |   _  \  |   _  \  |  | |  \ |  | |       \ 
 * |  ,----'|  |_)  | |  |_)  | |  |_)  | |  | |   \|  | |  .--.  |
 * |  |     |   ___/  |   ___/  |   _  <  |  | |  . `  | |  |  |  |
 * |  `----.|  |      |  |      |  |_)  | |  | |  |\   | |  '--'  |
 *  \______|| _|      | _|      |______/  |__| |__| \__| |_______/ 
 * 
 * This file is generated by cppbind on 10/07/2022-06:20.
 * Please do not change it manually.
 */

#ifndef _SWIFT_WRAPPERS_INHERITANCE_C_SWIFT_SHAPES_H_
#define _SWIFT_WRAPPERS_INHERITANCE_C_SWIFT_SHAPES_H_

#include "swift/wrappers/c_helpers.h"

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif
    void release_CppbindExample_Shape(CppBindCObject cself, bool owner);
    double _func_CppbindExample_Shape_area(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_Shape_thisObject(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_Circle_create(double  r, CppBindCObject* _Nonnull cppbind_err);
    double _func_CppbindExample_Circle_area(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_Circle_incrementRadius(CppBindCObject cself, double  value, CppBindCObject* _Nonnull cppbind_err);
    void release_CppbindExample_RegularTriangle(CppBindCObject cself, bool owner);

    CppBindCObject create_CppbindExample_RegularTriangle(double side, CppBindCObject* _Nonnull cppbind_err);
    double _func_CppbindExample_RegularTriangle_area(CppBindCObject cself, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_RegularTriangle_incrementSide(CppBindCObject cself, double  value, CppBindCObject* _Nonnull cppbind_err);
    CppBindCObject _func_CppbindExample_RegularTriangle_multiplySide(CppBindCObject cself, double  value, CppBindCObject* _Nonnull cppbind_err);
#if __cplusplus
}
#endif
#endif /* ifndef _SWIFT_WRAPPERS_INHERITANCE_C_SWIFT_SHAPES_H_ */
