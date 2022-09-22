#include "cxx/globs/utils.h"

using namespace cppbind::example;

int mul(int first, int second) {
    return first * second;
}

int mul(int first, int second, int third) {
    return first * second * third;
}

std::string concat(const std::string& str1, const std::string& str2) {
    return str1 + str2;
}

std::string concat(const std::string& str1, const std::string& str2, const std::string& str3) {
    return str1 + str2 + str3;
}

Color optionalColor(cppbind::example::Color c) {
    return c;
}

std::string optionalString(std::string optionalStr) {
    return optionalStr;
}

int optionalInt(int i) {
    return i;
}

Task singleComplexDefaultValue(Task task) {
    return task;
}

std::string multipleMixedDefaultValues(Task task, int i,
                                       Root r) {
    return task.title() + std::to_string(i) + r.path;
}

Project* optionalFDPtr(Project* project) {
    return project;
}

void doNothing() {
}

std::string greet(const std::string& name, const std::string& hometown) {
    return "Hello " + name + " from " + hometown;
}


ArrayInt sum(ArrayInt first, ArrayInt second) {
    ArrayInt res;
    for (int i = 0; i < 4; ++i) {
        res[i] = first[i] + second[i];
    }
    return res;
}

std::array<float, 4> sum(std::array<float, 4> first, std::array<float, 4> second) {
    std::array<float, 4> res;
    for (int i = 0; i < 4; ++i) {
        res[i] = first[i] + second[i];
    }
    return res;
}

namespace cppbind::example {
    std::vector<Color> getVectorColor(std::vector<Color> c) {
        return c;
    }
}