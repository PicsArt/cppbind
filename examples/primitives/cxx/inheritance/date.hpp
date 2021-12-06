#ifndef date_hpp
#define date_hpp

#include<string>

#include "cxx/inheritance/base.hpp"


namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 * swift.name: MyDate
 * swift.descendants:
 *  - iegen::example::DateTime
 */
class Date : public virtual Base {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    Date(int d, int m, int y) : day(d), month(m), year(y) {
        std::string format = "%d:%d:%d";
        int size_s = std::snprintf(nullptr, 0, format.c_str(), day, month, year) + 1;
        auto size = static_cast<size_t>(size_s);
        auto buf = std::make_unique<char[]>(size);
        std::snprintf(buf.get(), size, format.c_str(), day, month, year);
        _date = std::string(buf.get(), buf.get() + size - 1);

    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    const std::string & value() const override {
        return _date;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const std::string & date() const {
        return _date;
    }

    virtual ~Date() = default;

private:
    int day;
    int month;
    int year;
    std::string _date;
};
// [example]
}
#endif