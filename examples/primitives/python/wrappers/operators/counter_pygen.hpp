#ifndef operators_counter_hpp
#define operators_counter_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindCounter(py::module& m);

#endif