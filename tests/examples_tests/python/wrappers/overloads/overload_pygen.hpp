#ifndef overloads_overload_hpp
#define overloads_overload_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindOverloadedFunctions(py::module& m);

#endif