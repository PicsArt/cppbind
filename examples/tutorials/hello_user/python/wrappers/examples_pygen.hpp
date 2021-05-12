#ifndef examples_pygen_hpp
#define examples_pygen_hpp

#include "python/wrappers/undefined/hello_user_pygen.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;
void bindExamples(py::module& m);

#endif