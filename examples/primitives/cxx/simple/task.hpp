#ifndef task_hpp
#define task_hpp

#include <string>
#include <stdexcept>

namespace iegen::example {
// [example]
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
    /**
     * Task Constructor.
     * __API__
     * action: gen_constructor
     *
     */
    Task(const std::string& title) : _title(title) {};

    /**
     * Get objects title.
     * __API__
     * action: gen_getter
     * throws: no_throw
     *
     */
    std::string& title() {
        return _title;
    };


protected:
    std::string _title;
};
// [example]
}

#endif
