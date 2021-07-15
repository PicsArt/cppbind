#ifndef teacher_hpp
#define teacher_hpp

#include <vector>
#include <memory>

namespace iegen::example {
// [example]
// forward declaration
class Student;
typedef std::shared_ptr<Student> StudentRef;

/**
 * __API__
 * action: gen_class
 * shared_ref: False
 * package: forward_decl
 * kotlin.package: forward_decl.teacher
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
    void addStudent(StudentRef s) {
        _students.push_back(s);
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    const std::vector<StudentRef>& students() const {
        return _students;
    };

private:
    std::vector<StudentRef> _students;
};
// [example]
}
#endif
