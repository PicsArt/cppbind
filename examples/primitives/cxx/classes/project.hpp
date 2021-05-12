#ifndef project_hpp
#define project_hpp

#include <vector>
#include <string>

#include "cxx/classes/task.hpp"

namespace iegen::example {

/**
 * comments
 *
 * __API__
 * gen: class
 * shared_ref: False
 * package: classes
 * python.include: classes.task
 * swift.include: CWrapper
 */
class Project {
public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     *
     */
    Project(const std::string& title) : _title(title) {};

    /**
     * comments
     *
     * __API__
     * gen: getter
     * throws: no_throw
     *
     */
    std::string& title() {
        return _title;
    };


    /**
     * comments
     *
     * __API__
     * gen: method
     * throws: no_throw
     *
     */
    void addTask(Task* task) {
        _tasks.push_back(task);
    }

    /**
     * comments
     *
     * __API__
     * gen: method
     * throws: no_throw
     *
     */
    const std::vector<Task*>& tasks() const {
        return _tasks;
    }
private:
    std::vector<Task*> _tasks;
    std::string _title;
};

}
#endif