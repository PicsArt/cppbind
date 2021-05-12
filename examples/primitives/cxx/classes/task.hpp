#ifndef task_hpp
#define task_hpp

#include <string>

namespace iegen::example {

/**
 * comments
 *
 * __API__
 * gen: class
 * shared_ref: False
 * package: classes
 * python.package: classes.task
 * swift.include: CWrapper
 * python.name: PyTask
 */
class Task {
public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     *
     */
    Task(const std::string& title) : _title(title) {};

    /**
     * comments
     *
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
