#ifndef school_hpp
#define school_hpp

#include "cxx/forward_decl/teacher.hpp"
#include <memory>
#include <vector>

namespace cppbind::example {

// [example-start]
/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: factories
 */
class School {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     * keep_alive: [1]
     */
    static std::shared_ptr<School> create(const std::vector<Teacher*>& teachers);

    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    static std::shared_ptr<School> create();

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     * keep_alive: [1]
     */
    void addTeacher(Teacher* teacher);


    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const std::vector<Teacher*>& teachers();

private:
    School() {}
    School(const School&) = default;

private:
    std::vector<Teacher*> _teachers;

};
// [example-end]

}

#endif
