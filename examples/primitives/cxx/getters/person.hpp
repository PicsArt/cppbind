#ifndef person_hpp
#define person_hpp
#include <string>

namespace iegen::example {


/**
 * This class contains a private string field and getter/setter methods for it.
 * __API__
 * gen: class
 * shared_ref: true
 * package: getters
 */
class Person {
public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    Person(const std::string& name) : _fullname(name) {}

    //[getter]
    /**
     * fullname setter
     *__API__
     * gen: setter
     */
    void setFullName(const std::string& val) {
        _fullname = val;
    }
    //[getter]
    //[setter]
    /**
     * fullname getter
     * __API__
     * gen: getter
     */
    const std::string& fullName() {
        return _fullname;
    }
    //[setter]

    private:
        std::string _fullname;

};

}
#endif
