#ifndef hello_user_hpp
#define hello_user_hpp

#include "python/wrappers/hello_user/hello/hello_user.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;
void bindHelloUser(py::module& m);

#endif