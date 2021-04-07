#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "examples/cxx/getters/getter.hpp"

namespace py = pybind11;

void bindGetterSetter(py::module& m) {
    using namespace iegen::example::getter;
    py::class_<iegen::example::getter::GetterSetter, std::shared_ptr<iegen::example::getter::GetterSetter>> gettersetter(m, "GetterSetter");

    gettersetter.def(py::init<>());


    gettersetter.def_property("value", &iegen::example::getter::GetterSetter::value, &iegen::example::getter::GetterSetter::setValue);
}
void bindGetterSetterExtended(py::module& m) {
    using namespace iegen::example::getter;
    py::class_<iegen::example::getter::GetterSetterExtended, std::shared_ptr<iegen::example::getter::GetterSetterExtended>,iegen::example::getter::GetterSetter> gettersetterextended(m, "GetterSetterExtended");

    gettersetterextended.def(py::init<>());
}