#ifndef templates_template_functions_hpp
#define templates_template_functions_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindTemplateFunctions(py::module& m);

#endif