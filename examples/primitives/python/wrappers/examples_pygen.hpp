#ifndef examples_pygen_hpp
#define examples_pygen_hpp

#include "python/wrappers/classes/root_pygen.hpp"
#include "python/wrappers/classes/task_pygen.hpp"
#include "python/wrappers/classes/project_pygen.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;
void bindExamples(py::module& m);

#endif