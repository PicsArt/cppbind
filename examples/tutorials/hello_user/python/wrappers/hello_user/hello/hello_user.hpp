#ifndef hello_hello_user_hpp
#define hello_hello_user_hpp

#include <pybind11/pybind11.h>

namespace py = pybind11;

void bindUserInfo(py::module& m);
void bindHost(py::module& m);

#endif