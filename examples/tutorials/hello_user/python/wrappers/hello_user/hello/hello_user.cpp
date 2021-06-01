#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/hello_user.hpp"

namespace py = pybind11;

void bindUserInfo(py::module& m) {
    py::class_<UserInfo> userinfo(m, "UserInfo");

    userinfo.def(py::init<const std::string &, unsigned int>(), py::arg("user_name"), py::arg("user_age"));

    userinfo.def_readonly("age", &UserInfo::age);

    userinfo.def_readonly("name", &UserInfo::name);

    userinfo.def_readwrite("want_a_drink", &UserInfo::want_a_drink);
}
void bindHost(py::module& m) {
    py::class_<Host> host(m, "Host");

    host.def(py::init<>());
    host.def("hello", &Host::hello, py::arg("user"));
    host.def("welcome", &Host::welcome, py::arg("user"));
}