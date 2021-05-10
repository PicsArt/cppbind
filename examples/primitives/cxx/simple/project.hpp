#ifndef project_hpp
#define project_hpp

#include <vector>
#include <string>

#include "cxx/simple/task.hpp"

namespace iegen::example {
// [example]
/**
 * Class holding project information.
 * __API__
 * gen: class
 * shared_ref: False
 * package: simple
 * python.include: simple.task_pygen
 * swift.include: CWrapper
 */
class Project {
public:
    /**
     * Project constructor.
     * __API__
     * gen: constructor
     */
    Project(const std::string& title) : _title(title) {};

    /**
     * Get project´s title.
     * __API__
     * gen: getter
     */
    std::string& title() {
        return _title;
    };


    /**
     * Add a task to project.
     * __API__
     * gen: method
     */
    void addTask(Task* task) {
        _tasks.push_back(task);
    }

    /**
     * Get project´s tasks.
     * __API__
     * gen: method
     */
    const std::vector<Task*>& tasks() const {
        return _tasks;
    }
private:
    std::vector<Task*> _tasks;
    std::string _title;
};
// [example]
}
#endif