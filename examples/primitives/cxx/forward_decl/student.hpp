/*
 * This is an example with forward declaration. Currently as we do not have include mechanism based on argument and base
 * types we should manually specify c++ include for wrappers in the API.
 */

#ifndef student_hpp
#define student_hpp

#include <vector>

namespace iegen::example {
// [example]
// forward declaration
class Teacher;

/**
 * comments
 *
 * __API__
 * gen: class
 * shared_ref: False
 * package: forward_decl
 * swift.include: CWrapper
 * include_cxx: cxx/forward_decl/teacher.hpp
 */
class Student {
public:
    /**
     * __API__
     * gen: constructor
     */
    Student() {};


    /**
     * __API__
     * gen: method
     */
    void addTeacher(Teacher* t) {
        _teachers.push_back(t);
    }

    /**
     * __API__
     * gen: method
     */
    const std::vector<Teacher*>& teachers() const {
        return _teachers;
    };

private:
    std::vector<Teacher*> _teachers;
};
// [example]
}
#endif