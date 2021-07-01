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
 * action: gen_class
 * shared_ref: False
 * package: forward_decl
 * kotlin.package: forward_decl.teacher
 * swift.include: CWrapper
 */
class Teacher {
public:
    /**
     * __API__
     * action: gen_constructor
     */
    Teacher() {};

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    void addStudent(Student* s) {
        _students.push_back(s);
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
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