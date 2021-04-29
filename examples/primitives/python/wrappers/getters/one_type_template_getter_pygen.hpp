#ifndef getters_one_type_template_getter_hpp
#define getters_one_type_template_getter_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindSimpleItem(py::module& m);
void bindOneTypeTemplateGetter(py::module& m);

#endif