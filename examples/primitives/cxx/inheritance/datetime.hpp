#ifndef calendar_hpp
#define calendar_hpp

#include<string>

#include "cxx/inheritance/date.hpp"
#include "cxx/inheritance/time.hpp"


namespace iegen::example {
// [example]
/**
 * __API__
 * action: gen_class
 * file: datetime
 * shared_ref: True
 * package: inheritance
 */
class DateTime: public Time, public Date {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    DateTime(int d, int mo, int y, int h, int mi, int s) : Time(h, mi, s), Date(d, mo, y) {
        std::string format = "%s %s";
        int size_s = std::snprintf(nullptr, 0, format.c_str(), date().c_str(), time().c_str()) + 1;
        auto size = static_cast<size_t>(size_s);
        auto buf = std::make_unique<char[]>(size);
        std::snprintf(buf.get(), size, format.c_str(), date().c_str(), time().c_str());
        _datetime = std::string(buf.get(), buf.get() + size - 1);

    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    const std::string & value() const override {
        return _datetime;
    }

    /**
     * __API__
     * action: gen_getter
     * throws: no_throw
     */
    const std::string & datetime() const {
        return _datetime;
    }

    std::string _datetime;
};
// [example]
}
#endif