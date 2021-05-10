/*
 * This is an example with forward declaration. Currently as we do not have include mechanism based on argument and base
 * types we should manually specify c++ include for wrappers in the API.
 */

#ifndef teacher_hpp
#define teacher_hpp

#include <vector>

namespace iegen::example {
// [example]
// forward declaration
class Student;

/**
 * comments
 *
 * __API__
 * gen: class
 * shared_ref: False
 * package: forward_decl
 * swift.include: CWrapper
 * include_cxx: cxx/forward_decl/student.hpp
 */
class Teacher {
public:
    /**
     * __API__
     * gen: constructor
     */
    Teacher() {};

    /**
     * __API__
     * gen: method
     */
    void addStudent(Student* s) {
        _students.push_back(s);
    }

    /**
     * __API__
     * gen: method
     */
    const std::vector<Student*>& students() const {
        return _students;
    };

private:
    std::vector<Student*> _students;
};
// [example]
}
#endif