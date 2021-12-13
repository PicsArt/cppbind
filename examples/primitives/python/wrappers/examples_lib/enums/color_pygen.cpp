/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/07/2021-12:30.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>

#include "cxx/enums/color.hpp"

namespace py = pybind11;

void bindIegenExampleColor(py::module& m) {
    py::enum_<iegen::example::Color>(m, "Color")
        .value("Red", iegen::example::Color::Red)
        .value("Green", iegen::example::Color::Green)
        .value("Blue", iegen::example::Color::Blue);
}
void bindIegenExampleColorShade(py::module& m) {
    py::enum_<iegen::example::ColorShade>(m, "ColorShade")
        .value("Light", iegen::example::ColorShade::Light)
        .value("Dark", iegen::example::ColorShade::Dark)
        .value("SemiLight", iegen::example::ColorShade::SemiLight)
        .value("SemiDark", iegen::example::ColorShade::SemiDark);
}