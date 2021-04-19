#ifndef getters_person_hpp
#define getters_person_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindPerson(py::module& m);

#endif