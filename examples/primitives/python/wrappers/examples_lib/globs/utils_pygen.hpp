/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/22/2021-09:55.
 * Please do not change it manually.
 */

#ifndef globs_utils_hpp
#define globs_utils_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindoptionalColor(py::module& m);
void bindoptionalFDPtr(py::module& m);
void binddoNothing(py::module& m);
void bindoptionalInt(py::module& m);
void bindconcat(py::module& m);
void bindconcat1(py::module& m);
void bindmaxint(py::module& m);
void bindmaxstr(py::module& m);
void bindIegenExamplemakePairProjectProject(py::module& m);
void bindIegenExamplemakePairRootProject(py::module& m);

#endif
