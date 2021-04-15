#ifndef classes_project_hpp
#define classes_project_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindProject(py::module& m);

#endif