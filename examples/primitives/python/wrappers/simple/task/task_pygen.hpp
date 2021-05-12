#ifndef simple_task_task_hpp
#define simple_task_task_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindPyTask(py::module& m);

#endif