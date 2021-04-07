#include <pybind11/pybind11.h>
#include "examples_pygen.hpp"

namespace py = pybind11;
PYBIND11_MODULE(iegen, m) {
    py::module_ ve = m.def_submodule("examples", "examples");
    bindIegenExamples(ve);
}