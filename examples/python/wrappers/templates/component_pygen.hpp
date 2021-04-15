#ifndef templates_component_hpp
#define templates_component_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindComponent(py::module& m);

#endif