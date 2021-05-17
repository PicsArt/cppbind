#ifndef forward_decl_student_hpp
#define forward_decl_student_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindStudent(py::module& m);

#endif