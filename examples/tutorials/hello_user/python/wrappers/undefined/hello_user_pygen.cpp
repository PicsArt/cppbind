#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/hello_user.hpp"

namespace py = pybind11;

void bindUserInfo(py::module& m) {
    using namespace hello_user;
    py::class_<hello_user::UserInfo> userinfo(m, "UserInfo");

    userinfo.def(py::init<const std::string &, unsigned int>(), py::arg("user_name"), py::arg("user_age"));

    userinfo.def_readonly("age", &hello_user::UserInfo::age);

    userinfo.def_readonly("name", &hello_user::UserInfo::name);

    userinfo.def_readwrite("want_a_drink", &hello_user::UserInfo::want_a_drink);
}
void bindHost(py::module& m) {
    using namespace hello_user;
    py::class_<hello_user::Host> host(m, "Host");

    host.def(py::init<>());
    host.def("hello", &hello_user::Host::hello, py::arg("user"));
    host.def("welcome", &hello_user::Host::welcome, py::arg("user"));
}