#ifndef templates_stack_hpp
#define templates_stack_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindStackProject(py::module& m);
void bindStackPyTask(py::module& m);

#endif