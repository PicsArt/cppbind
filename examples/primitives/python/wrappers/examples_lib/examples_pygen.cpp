/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 01/25/2022-13:16.
 * Please do not change it manually.
 */

#include <pybind11/pybind11.h>
#include "python/wrappers/examples_lib/examples_pygen.hpp"

namespace py = pybind11;
void bindExamples(py::module& m) {
    py::module_ containers = m.def_submodule("containers", "containers");

    py::module_ containers_map = containers.def_submodule("map", "map");

    bindIegenExampleMapItem(containers_map);
    bindIegenExampleMapExamples(containers_map);
    py::module_ containers_nested_containers = containers.def_submodule("nested_containers", "nested_containers");

    bindIegenExampleNestedExamples(containers_nested_containers);
    py::module_ containers_pair = containers.def_submodule("pair", "pair");

    bindIegenExamplePairExamples(containers_pair);
    py::module_ containers_vector = containers.def_submodule("vector", "vector");

    bindIegenExampleVectorItem(containers_vector);
    bindIegenExampleVectorExamples(containers_vector);
    py::module_ enums = m.def_submodule("enums", "enums");

    py::module_ enums_color = enums.def_submodule("color", "color");

    bindIegenExampleColor(enums_color);
    bindIegenExampleColorShade(enums_color);
    py::module_ enums_frame = enums.def_submodule("frame", "frame");

    bindIegenExampleFrame(enums_frame);
    py::module_ extra = m.def_submodule("extra", "extra");

    py::module_ extra_object = extra.def_submodule("object", "object");

    bindIegenObject(extra_object);
    py::module_ extra_object_usage = extra.def_submodule("object_usage", "object_usage");

    bindIegenObjectUsage(extra_object_usage);
    py::module_ forward_decl = m.def_submodule("forward_decl", "forward_decl");

    py::module_ forward_decl_student = forward_decl.def_submodule("student", "student");

    bindIegenExampleStudent(forward_decl_student);
    py::module_ forward_decl_teacher = forward_decl.def_submodule("teacher", "teacher");

    bindIegenExampleTeacher(forward_decl_teacher);
    py::module_ functionals = m.def_submodule("functionals", "functionals");

    py::module_ functionals_functional_example = functionals.def_submodule("functional_example", "functional_example");

    bindIegenExampleFunctionalExamples(functionals_functional_example);
    py::module_ getters = m.def_submodule("getters", "getters");

    py::module_ getters_fruits = getters.def_submodule("fruits", "fruits");

    bindIegenExampleFruitType(getters_fruits);
    bindIegenExampleFruit(getters_fruits);
    bindIegenExampleApple(getters_fruits);
    bindIegenExamplePineapple(getters_fruits);
    bindIegenExampleFruits(getters_fruits);
    py::module_ getters_number = getters.def_submodule("number", "number");

    bindIegenExampleNumberInt(getters_number);
    bindIegenExampleNumberFloat(getters_number);
    py::module_ getters_person = getters.def_submodule("person", "person");

    bindIegenExamplePerson(getters_person);
    py::module_ simple_task = m.def_submodule("simple.task", "simple.task");

    py::module_ simple_task_task = simple_task.def_submodule("task", "task");

    bindIegenExamplePyTask(simple_task_task);
    py::module_ simple = m.def_submodule("simple", "simple");

    py::module_ simple_project = simple.def_submodule("project", "project");

    bindIegenExampleProject(simple_project);
    py::module_ globs = m.def_submodule("globs", "globs");

    py::module_ globs_utils = globs.def_submodule("utils", "utils");

    bindconcat(globs_utils);
    bindconcat1(globs_utils);
    bindmaxint(globs_utils);
    bindmaxstr(globs_utils);
    bindIegenExamplemakePairProjectProject(globs_utils);
    bindIegenExamplemakePairRootProject(globs_utils);
    bindoptionalColor(globs_utils);
    bindoptionalFDPtr(globs_utils);
    binddoNothing(globs_utils);
    bindoptionalInt(globs_utils);
    py::module_ inheritance = m.def_submodule("inheritance", "inheritance");

    py::module_ inheritance_animal = inheritance.def_submodule("animal", "animal");

    bindIegenExampleAnimal(inheritance_animal);
    bindIegenExampleTerrestrialAnimal(inheritance_animal);
    bindIegenExampleAquaticAnimal(inheritance_animal);
    bindIegenExampleFrog(inheritance_animal);
    bindIegenExampleLittleFrog(inheritance_animal);
    bindIegenExampleAnimalUsage(inheritance_animal);
    py::module_ inheritance_base = inheritance.def_submodule("base", "base");

    bindIegenExampleBase(inheritance_base);
    py::module_ inheritance_vehicle = inheritance.def_submodule("vehicle", "vehicle");

    bindIegenExampleVehicle(inheritance_vehicle);
    py::module_ inheritance_bicycle = inheritance.def_submodule("bicycle", "bicycle");

    bindIegenExampleBicycle(inheritance_bicycle);
    py::module_ inheritance_car = inheritance.def_submodule("car", "car");

    bindIegenExampleMyCar(inheritance_car);
    py::module_ inheritance_date = inheritance.def_submodule("date", "date");

    bindIegenExampleDate(inheritance_date);
    py::module_ inheritance_datetime = inheritance.def_submodule("datetime", "datetime");

    bindIegenExampleTime(inheritance_datetime);
    bindIegenExampleDateTime(inheritance_datetime);
    py::module_ inheritance_parallelogram = inheritance.def_submodule("parallelogram", "parallelogram");

    bindIegenExampleParallelogram(inheritance_parallelogram);
    py::module_ inheritance_rectangle = inheritance.def_submodule("rectangle", "rectangle");

    bindIegenExampleRectangle(inheritance_rectangle);
    py::module_ inheritance_rhombus = inheritance.def_submodule("rhombus", "rhombus");

    bindIegenExampleRhombusFigure(inheritance_rhombus);
    py::module_ inheritance_square = inheritance.def_submodule("square", "square");

    bindIegenExampleSquare(inheritance_square);
    py::module_ inheritance_symbol = inheritance.def_submodule("symbol", "symbol");

    bindIegenExampleSign(inheritance_symbol);
    bindIegenExampleText(inheritance_symbol);
    bindIegenExampleDigit(inheritance_symbol);
    bindIegenExampleSymbolUsage(inheritance_symbol);
    py::module_ inheritance_usage = inheritance.def_submodule("usage", "usage");

    bindIegenExampleGeometricFigure(inheritance_usage);
    bindIegenExampleMyVehicle(inheritance_usage);
    bindIegenExampleMyBicycle(inheritance_usage);
    bindIegenExampleMyCalendar(inheritance_usage);
    py::module_ misc = m.def_submodule("misc", "misc");

    py::module_ misc_size_buffer = misc.def_submodule("size_buffer", "size_buffer");

    bindIegenExampleSizeUsage(misc_size_buffer);
    bindIegenExampleBufferUsage(misc_size_buffer);
    py::module_ misc_yaml_example = misc.def_submodule("yaml_example", "yaml_example");

    bindIegenExampleWithExternalAPIComments(misc_yaml_example);
    bindIegenExampleAdderInt(misc_yaml_example);
    bindIegenExampleAdderFloat(misc_yaml_example);
    bindIegenExamplecolor(misc_yaml_example);
    py::module_ nullables = m.def_submodule("nullables", "nullables");

    py::module_ nullables_nullable_utils = nullables.def_submodule("nullable_utils", "nullable_utils");

    bindIegenExampleNullableNumberInt(nullables_nullable_utils);
    bindIegenExampleNullableNumberDouble(nullables_nullable_utils);
    bindIegenExampleNullableUtils(nullables_nullable_utils);
    py::module_ operators = m.def_submodule("operators", "operators");

    py::module_ operators_counter = operators.def_submodule("counter", "counter");

    bindIegenExampleCounter(operators_counter);
    py::module_ operators_intarray = operators.def_submodule("intarray", "intarray");

    bindIegenExampleIntArray(operators_intarray);
    py::module_ optionals = m.def_submodule("optionals", "optionals");

    py::module_ optionals_optionals = optionals.def_submodule("optionals", "optionals");

    bindIegenExampleOptionals(optionals_optionals);
    py::module_ overloads = m.def_submodule("overloads", "overloads");

    py::module_ overloads_employee = overloads.def_submodule("employee", "employee");

    bindIegenExampleEmployee(overloads_employee);
    py::module_ overloads_utils = overloads.def_submodule("utils", "utils");

    bindIegenExampleUtils(overloads_utils);
    py::module_ shared_ptr = m.def_submodule("shared_ptr", "shared_ptr");

    py::module_ shared_ptr_shared_ptr = shared_ptr.def_submodule("shared_ptr", "shared_ptr");

    bindExampleCar(shared_ptr_shared_ptr);
    bindExampleCarUsage(shared_ptr_shared_ptr);
    py::module_ shared_ptr_shared_ptr_symbol = shared_ptr.def_submodule("shared_ptr_symbol", "shared_ptr_symbol");

    bindIegenExampleSignShared(shared_ptr_shared_ptr_symbol);
    bindIegenExampleTextShared(shared_ptr_shared_ptr_symbol);
    bindIegenExampleDigitShared(shared_ptr_shared_ptr_symbol);
    bindIegenExampleSymbolUsageShared(shared_ptr_shared_ptr_symbol);
    py::module_ simple_holder = simple.def_submodule("holder", "holder");

    bindIegenExampleHolder(simple_holder);
    py::module_ simple_path = simple.def_submodule("path", "path");

    bindIegenExamplePath(simple_path);
    py::module_ simple_root = simple.def_submodule("root", "root");

    bindIegenExampleRoot(simple_root);
    py::module_ templates = m.def_submodule("templates", "templates");

    py::module_ templates_addressable = templates.def_submodule("addressable", "addressable");

    bindIegenExampleAddressableRoot(templates_addressable);
    py::module_ templates_component = templates.def_submodule("component", "component");

    bindIegenExampleComponent(templates_component);
    py::module_ templates_container = templates.def_submodule("container", "container");

    bindIegenExampleContainer(templates_container);
    bindIegenExampleContainerHolder(templates_container);
    py::module_ templates_pair = templates.def_submodule("pair", "pair");

    bindIegenExamplePairEmployee(templates_pair);
    bindIegenExamplePairStudent(templates_pair);
    py::module_ templates_stack = templates.def_submodule("stack", "stack");

    bindIegenExampleStackPrj(templates_stack);
    bindIegenExampleStackPyTask(templates_stack);
    bindIegenExampleStackNumInt(templates_stack);
    py::module_ templates_stack_usage = templates.def_submodule("stack_usage", "stack_usage");

    bindIegenExampleStackUsage(templates_stack_usage);
    py::module_ templates_template_methods = templates.def_submodule("template_methods", "template_methods");

    bindIegenExampleTemplateMethods(templates_template_methods);
    py::module_ templates_wrapper = templates.def_submodule("wrapper", "wrapper");

    bindIegenExampleWrapperPairStrings(templates_wrapper);
    bindIegenExampleWrapperPairIntInt(templates_wrapper);
    bindIegenExampleWrapperString(templates_wrapper);
}
