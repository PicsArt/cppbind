#ifndef getters_number_hpp
#define getters_number_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindNumberint(py::module& m);
void bindNumberfloat(py::module& m);

#endif