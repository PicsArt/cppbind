#ifndef task_hpp
#define task_hpp

#include <string>

namespace iegen::example {
// [example]
/**
 * Class holding task information.
 * __API__
 * gen: class
 * shared_ref: False
 * package: simple
 * swift.include: CWrapper
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
// [example]
}

#endif
