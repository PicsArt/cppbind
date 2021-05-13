
#include <pybind11/pybind11.h>
#include "python/wrappers/hello_user/hello_user.hpp"

namespace py = pybind11;
PYBIND11_MODULE(hello_user, m) {
    py::module_ parent = m;
    bindHelloUser(parent);
}