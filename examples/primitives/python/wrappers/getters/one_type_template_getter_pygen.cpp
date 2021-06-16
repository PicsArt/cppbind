/**
 * This file was generated by iegen on 06/16/2021-14:04.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/getters/one_type_template_getter.hpp"

namespace py = pybind11;

void bindSimpleItem(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::SimpleItem> simpleitem(m, "SimpleItem");

    simpleitem.def_readwrite("value", &iegen::example::SimpleItem::value);
}
void bindOneTypeTemplateGetter(py::module& m) {
    using namespace iegen::example;
    py::class_<iegen::example::OneTypeTemplateGetter> onetypetemplategetter(m, "OneTypeTemplateGetter");

    onetypetemplategetter.def(py::init<>());


    onetypetemplategetter.def_property_readonly("simple_item", &iegen::example::OneTypeTemplateGetter::item<iegen::example::SimpleItem>);



    onetypetemplategetter.def_property_readonly("simple_item_with_type", &iegen::example::OneTypeTemplateGetter::itemWithType<iegen::example::SimpleItem>);
}