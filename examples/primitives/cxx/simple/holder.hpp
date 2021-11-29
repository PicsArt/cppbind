#ifndef holder_hpp
#define holder_hpp

#include "cxx/simple/task.hpp"

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * package: simple
 */
class Holder {

public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Holder() : _task(Task("Initial title")){};

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const Task& task() {
        return _task;
    };

private:
    Task _task;

};
// [example]
}
#endif

