//[file-doc]

 @file getter.h
 @brief This is an example pf simple getter/setter.

//[file-doc]
#include <string>

namespace iegen::example::getters {



/**
 * This class contains a private string field and getter/setter methods for it.
 * __API__
 * gen: class
 * shared_ref: true
 * package: getters
 */
class GetterSetter {
public:
    /**
     * comments
     *
     * __API__
     * gen: constructor
     */
    GetterSetter() :_value("default value") {}

    //[getter]
    /**
     * value setter
     *__API__
     * gen: setter
     */
    void setValue(const std::string& val) {
        _value = val;
    }
    //[getter]
    //[setter]
    /**
     * value getter
     * __API__
     * gen: getter
     */
    const std::string& value() {
        return _value;
    }
    //[setter]

    private:
        std::string _value;

};

}
#endif