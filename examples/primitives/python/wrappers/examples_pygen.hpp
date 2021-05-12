#ifndef examples_pygen_hpp
#define examples_pygen_hpp

#include "python/wrappers/classes/task/task_pygen.hpp"
#include "python/wrappers/classes/project_pygen.hpp"
#include "python/wrappers/classes/root_pygen.hpp"
#include "python/wrappers/containers/map_pygen.hpp"
#include "python/wrappers/containers/vector_pygen.hpp"
#include "python/wrappers/enums/color_pygen.hpp"
#include "python/wrappers/enums/frame_pygen.hpp"
#include "python/wrappers/forward_decl/student_pygen.hpp"
#include "python/wrappers/forward_decl/teacher_pygen.hpp"
#include "python/wrappers/inheritance/parallelogram_pygen.hpp"
#include "python/wrappers/inheritance/rectangle_pygen.hpp"
#include "python/wrappers/inheritance/rhombus_pygen.hpp"
#include "python/wrappers/inheritance/square_pygen.hpp"
#include "python/wrappers/operators/counter_pygen.hpp"
#include "python/wrappers/optionals/optionals_pygen.hpp"
#include "python/wrappers/overloads/overload_pygen.hpp"
#include "python/wrappers/templates/addressable_pygen.hpp"
#include "python/wrappers/templates/component_pygen.hpp"
#include "python/wrappers/templates/stack_pygen.hpp"
#include "python/wrappers/templates/stack_usage_pygen.hpp"
#include "python/wrappers/templates/template_functions_pygen.hpp"
#include <pybind11/pybind11.h>

namespace py = pybind11;
void bindExamples(py::module& m);

#endif