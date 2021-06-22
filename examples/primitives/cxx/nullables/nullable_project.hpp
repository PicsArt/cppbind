#ifndef nullable_project_hpp
#define nullable_project_hpp

#include <vector>
#include <string>

#include "cxx/simple/task.hpp"

namespace iegen::example::nullable {
// [example]
/**
 * Class holding project information.
 * __API__
 * gen: class
 * shared_ref: False
 * package: nullables
 * python.include: simple.task
 * kotlin.include: com.examples.simple.Task
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
     * throws: no_throw
     */
    std::string& title() {
        return _title;
    };

    /**
     * Add a task to project.
     * __API__
     * gen: method
     * throws: no_throw
     * nullable_arg: task
     */
    void addTask(Task* task) {
        if (task != nullptr) {
            _tasks.push_back(task);
        }
    }

    /**
     * Get the first task if it exists or null otherwise.
     * __API__
     * gen: method
     * throws: no_throw
     * nullable_return: True
     */
    Task* getFirstTask() {
        if (_tasks.size() > 0) {
            return _tasks.at(0);
        }
        return nullptr;
    }

    /**
     * Get project´s tasks.
     * __API__
     * gen: method
     * throws: no_throw
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