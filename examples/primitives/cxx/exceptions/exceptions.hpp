#ifndef exceptions_hpp
#define exceptions_hpp

#include <map>
#include <string>
#include <exception>
#include <stdexcept>

#include "cxx/simple/task.hpp"

namespace cppbind::example {

/**
 * __API__
 * action: gen_class
 * package: exceptions
 * file: custom_std_exceptions
 */
class SystemError : public std::exception {
    public:
    SystemError() {};

    SystemError(const SystemError& e) {
        message = e.message;
    }

    virtual ~SystemError() = default;
    /**
    * comments
    *
    * __API__
    * action: gen_constructor
    * throws: no_throw
    */
    SystemError(const std::string& message) :
        message(message) {};
    /**
    * comments
    *
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    virtual const char* what() const noexcept {
        return message.c_str();
    }

    private:
        std::string message;
};

/**
 * __API__
 * action: gen_class
 * package: exceptions
 * file: custom_std_exceptions
 */
class FileError : public SystemError {
    public:
    FileError() {};
    /**
    * __API__
    * action: gen_constructor
    * throws: no_throw
    */
    FileError(const std::string& message) :
        message(message) {};
    /**
    * comments
    *
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    const char* what() const noexcept {
        return message.c_str();
    }

    private:
        std::string message;
};
/**
 * __API__
 * action: gen_class
 * package: exceptions
 * file: custom_exceptions
 * is_exception: True
 */
class SimpleBaseException {
    public:
    SimpleBaseException() {};

    SimpleBaseException(const SimpleBaseException& e) {
        err_num = e.err_num;
    }

    virtual ~SimpleBaseException() = default;
    /**
    * __API__
    * action: gen_constructor
    * throws: no_throw
    */
    SimpleBaseException(const int err_num) :
        err_num(err_num) {};

    // [no-throw-example-start]
    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    virtual int errNum() {
        return err_num;
    }
    // [no-throw-example-end]

    private:
        int err_num;
};

/**
 * __API__
 * action: gen_class
 * package: exceptions
 * file: custom_exceptions
 */
class SimpleChildException : public SimpleBaseException {
    public:
    SimpleChildException() {};

    SimpleChildException(const SimpleChildException& e) {
        err_num = e.err_num;
    }

    virtual ~SimpleChildException() = default;
    /**
    * comments
    *
    * __API__
    * action: gen_constructor
    * throws: no_throw
    */
    SimpleChildException(const int err_num) :
        err_num(err_num) {};
    /**
    * comments
    *
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    int errNum() {
        return err_num;
    }

    private:
        int err_num;
};
}

namespace cppbind::exceptions {

/**
 * An example of a global function throwing an exception.
 * __API__
 * action: gen_function
 * package: exceptions
 * file: throw_exceptions
 * throws:
 *   - std::invalid_argument
 */
void throwExc(bool do_throw=false);


 /**
 * __API__
 * action: gen_class
 * package: exceptions
 * file: throw_exceptions
 */
class ThrowExc {
    public:
    // [throw-example-start]
    /**
     * __API__
     * action: gen_constructor
     * throws:
     *   - std::invalid_argument
     */
     ThrowExc(bool do_throw=false) {
        if (do_throw) throw std::invalid_argument("inv_arg");
     }

    /**
     * __API__
     * action: gen_method
     * throws:
     *   - std::out_of_range
     *   - cppbind::example::SystemError
     */
    static int getByKey(const std::map<int, int>& m, int key) {
        return m.at(key);
    }

    /**
     * Throws exception with return value of type string.
     * __API__
     * action: gen_method
     * throws: std::invalid_argument
     */
    static std::string throwsWithReturnValueString() {
        throw std::invalid_argument("return value error");
    }

    /**
     * Throws exception with return value of cppbind type.
     * __API__
     * action: gen_method
     * throws: std::invalid_argument
     */
    static cppbind::example::Task* throwsWithReturnValuePtr() {
        throw std::invalid_argument("return value error");
    }
    // [throw-example-end]

    /**
     * __API__
     * action: gen_getter
     * swift.action:
     * throws:
     *   - std::invalid_argument
     */
    std::string prop() {
        throw std::invalid_argument("inv_arg");
        return _prop;
    }

    /**
     * __API__
     * action: gen_setter
     * swift.action:
     * throws:
     *   - std::invalid_argument
     *   - std::out_of_range
     */
     void setProp(std::string s) {
        throw std::out_of_range("out_of_range");
        _prop = s;
     }

    /**
     * An example to check swift throwing property getter
     * __API__
     * action: gen_getter
     * kotlin.action:
     * python.action:
     * throws: no_throw
     */
    std::string prop1() {
        throw std::invalid_argument("inv_arg");
        return _prop;
    }

    /**
     * An example to check swift throwing property setter
     * __API__
     * action: gen_setter
     * kotlin.action:
     * python.action:
     * throws: no_throw
     */
     void setProp1(std::string s) {
        throw std::out_of_range("out_of_range");
        _prop = s;
     }

    /**
     * An example of a getter/setter pair with the different 'throws' lists (for checking Kotlin getter/setter exception handling).
     * __API__
     * action: gen_getter
     * swift.action:
     * python.action:
     * throws: no_throw
     */
    std::string prop2() {
        throw std::invalid_argument("inv_arg");
        return _prop;
    }

    /**
     * An example of a getter/setter pair with the different 'throws' lists (for checking Kotlin getter/setter exception handling).
     * __API__
     * action: gen_setter
     * swift.action:
     * python.action:
     * throws:
     *   - std::invalid_argument
     *   - std::out_of_range
     */
     void setProp2(std::string s) {
        throw std::out_of_range("out_of_range");
        _prop = s;
     }

     private:
     std::string _prop = "prop";
};

 /**
 * __API__
 * action: gen_class
 * package: exceptions
 * file: no_throw_exceptions
 */
class NoThrowExc {
    public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
     NoThrowExc(bool do_throw=false) {
        if (do_throw) throw std::invalid_argument("inv_arg");
     }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    static void noop() {
        throw(1);
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    std::string prop() {
        return _prop;
    }

    /**
     * __API__
     * action: gen_setter
     * throws: no_throw
     */
     void setProp(std::string s) {
        _prop = s;
     }

    private:
    std::string _prop = "prop";
};

/**
 * __API__
 * action: gen_class
 * package: exceptions
 * file: misc_exceptions
 */
class Integer {
    public:
    /**
    * __API__
    * action: gen_constructor
    * throws: no_throw
    */
    Integer(int n) : _n(n) {}
    /**
    * value getter
    *__API__
    * action: gen_getter
    * throws: no_throw
    */
    int value() {
        return _n;
    }

    private:
        int _n;
};

/**
 * __API__
 * action: gen_class
 * package: exceptions
 * file: misc_exceptions
 */
class MiscExc {
    public:
     /**
     * __API__
     * action: gen_method
     * throws:
     *   - std::out_of_range
     */
     static Integer* returnInteger(bool do_throw) {
        if (do_throw) {
            throw std::out_of_range("error");
        } else {
            Integer* i = new Integer(1);
            return i;
        }
     }
    /**
     *
     * __API__
     * action: gen_method
     * throws:
     *   - std::runtime_error
     *   - cppbind::example::FileError
     *   - cppbind::example::SystemError
     *   - cppbind::example::SimpleChildException
     *   - cppbind::example::SimpleBaseException
     *   - std::exception
     */
    static void raiseErrorByType(const std::string& err_type) {
        if (err_type.compare("system") == 0) {
            throw cppbind::example::SystemError("system error");
        } else if (err_type.compare("file") == 0) {
            throw cppbind::example::FileError("file error");
        } else if (err_type.compare("runtime") == 0) {
            throw std::runtime_error("runtime error");
        } else if (err_type.compare("simple_child") == 0) {
            throw cppbind::example::SimpleChildException(100);
        } else if (err_type.compare("simple_base") == 0) {
            throw cppbind::example::SimpleBaseException(200);
        } else {
            throw std::invalid_argument("inv_arg");
        }
    }
};
}

#endif
