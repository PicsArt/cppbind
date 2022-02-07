#ifndef student_hpp
#define student_hpp

#include <vector>
#include <string>

namespace iegen::example {
// [example]
// forward declaration
class Teacher;

/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: forward_decl
 * kotlin.package: forward_decl.student
 */
class Student {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Student(const std::string& st_name) : name(st_name) {};

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Student(const std::vector<Teacher*>& teachers) : _teachers(teachers) {};


    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void addTeacher(Teacher* t) {
        _teachers.push_back(t);
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * return_value_policy: reference
     */
    const std::vector<Teacher*>& teachers() const {
        return _teachers;
    };

    /**
     * __API__
     * action: gen_property_setter
     */
    std::string name;


private:
    std::vector<Teacher*> _teachers;
};
// [example]
}
#endif
