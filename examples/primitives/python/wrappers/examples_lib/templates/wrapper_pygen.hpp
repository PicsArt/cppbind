/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/21/2021-09:31.
 * Please do not change it manually.
 */

#ifndef templates_wrapper_hpp
#define templates_wrapper_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindIegenExampleWrapperPairStrings(py::module& m);
void bindIegenExampleWrapperPairIntInt(py::module& m);
void bindIegenExampleWrapperString(py::module& m);

#endif