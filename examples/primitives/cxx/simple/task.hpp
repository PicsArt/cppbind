#ifndef task_hpp
#define task_hpp

#include <string>

namespace cppbind::example {
// [example-start]
/**
 * Class holding task information.
 * \internal
 * internal comment should not go to wrappers
 * __API__
 * action: gen_class
 * shared_ref: False
 * package: simple
 * python.package: simple.task
 * python.name: PyTask
 */
class Task {
public:
    Task(){};
    /**
     * Task Constructor.
     * __API__
     * action: gen_constructor
     * throws: no_throw
     *
     */
    Task(const std::string& title) : _title(title) {};

    /**
     * Get objects title.
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    std::string& title() {
        return _title;
    };

     /**
      * Get objects title.
      * __API__
      * action: gen_method
      * throws: no_throw
      */
     void setTitle(const std::string& title) {
        _title = title;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    bool equals(Task* t) const {
        return this == t;
    }

protected:
    std::string _title;
};
// [example-end]
}

#endif
