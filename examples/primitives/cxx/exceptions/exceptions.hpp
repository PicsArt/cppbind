#ifndef exceptions_hpp
#define exceptions_hpp

#include <map>
#include <string>
#include <exception>
#include <stdexcept>

#include "cxx/simple/task.hpp"

namespace iegen::example {

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

    // [no-throw-example]
    /**
    * __API__
    * action: gen_method
    * throws: no_throw
    */
    virtual int errNum() {
        return err_num;
    }
    // [no-throw-example]

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

namespace iegen::exceptions {
 /**
 * __API__
 * action: gen_class
 * package: exceptions
 * file: throw_exceptions
 */
class ThrowExc {
    public:
    // [throw-example]
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
     *   - iegen::example::SystemError
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
     * Throws exception with return value of iegen type.
     * __API__
     * action: gen_method
     * throws: std::invalid_argument
     */
    static iegen::example::Task* throwsWithReturnValuePtr() {
        throw std::invalid_argument("return value error");
    }
    // [throw-example]

    /**
     * __API__
     * action: gen_getter
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
     * throws:
     *   - std::invalid_argument
     *   - std::out_of_range
     */
     void setProp(std::string s) {
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
     *   - iegen::example::FileError
     *   - iegen::example::SystemError
     *   - iegen::example::SimpleChildException
     *   - iegen::example::SimpleBaseException
     *   - std::exception
     */
    static void raiseErrorByType(const std::string& err_type) {
        if (err_type.compare("system") == 0) {
            throw iegen::example::SystemError("system error");
        } else if (err_type.compare("file") == 0) {
            throw iegen::example::FileError("file error");
        } else if (err_type.compare("runtime") == 0) {
            throw std::runtime_error("runtime error");
        } else if (err_type.compare("simple_child") == 0) {
            throw iegen::example::SimpleChildException(100);
        } else if (err_type.compare("simple_base") == 0) {
            throw iegen::example::SimpleBaseException(200);
        } else {
            throw std::invalid_argument("inv_arg");
        }
    }
};
}

#endif
