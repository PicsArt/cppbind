#include "cxx/factories/school.h"


namespace cppbind::example {

// factory methods
std::shared_ptr<School> School::create() {
    return std::shared_ptr<School>(new School());
}

std::shared_ptr<School> School::create(const std::vector<Teacher*>& teachers) {
    auto s = new School();
    s->_teachers.insert(s->_teachers.end(), teachers.begin(), teachers.end());
    return std::shared_ptr<School>(s);
}

void School::addTeacher(Teacher* teacher) {
    _teachers.push_back(teacher);
}

const std::vector<Teacher*>& School::teachers() {
    return _teachers;
}

}
