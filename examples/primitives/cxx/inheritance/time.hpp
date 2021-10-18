#ifndef time_hpp
#define time_hpp

#include<string>

#include "cxx/inheritance/base.hpp"

namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_interface
 * shared_ref: True
 * package: inheritance
 */
class Time : public virtual Base {
public:
    /**
     * __API__
     * action: gen_constructor
     */
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        std::string format = "%d:%d:%d";
        int size_s = std::snprintf(nullptr, 0, format.c_str(), hours, minutes, seconds) + 1;
        auto size = static_cast<size_t>(size_s);
        auto buf = std::make_unique<char[]>(size);
        std::snprintf(buf.get(), size, format.c_str(), hours, minutes, seconds);
        _time = std::string(buf.get(), buf.get() + size - 1);
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    const std::string & value() const override {
        return _time;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const std::string & time() const {
        return _time;
    }

    virtual ~Time() = default;

private:
    int hours;
    int minutes;
    int seconds;
    std::string _time;
};
// [example]
}
#endif