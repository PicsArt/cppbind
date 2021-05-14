#ifndef task_hpp
#define task_hpp

#include <string>

namespace iegen::example {

/**
 * Class holding task information.
 * __API__
 * gen: class
 * shared_ref: True
 * package: simple
 * python.package: simple.task
 * swift.include: CWrapper
 * python.name: PyTask
 */
class Task {
public:
    /**
     * Task Constructor.
     * __API__
     * gen: constructor
     *
     */
    Task(const std::string& title) : _title(title) {};

    /**
     * Get objects title.
     * __API__
     * gen: getter
     *
     */
    std::string& title() {
        return _title;
    };


protected:
    std::string _title;
};

}

#endif
