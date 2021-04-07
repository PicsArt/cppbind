#ifndef getters_getter_hpp
#define getters_getter_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindGetterSetter(py::module& m);
void bindGetterSetterExtended(py::module& m);

#endif