#ifndef yaml_example_hpp
#define yaml_example_hpp

#include <string>

namespace iegen::example {

class WithExternalAPIComments {
    public:

    WithExternalAPIComments(std::string s) : _str(s) {}

    /**
     * retInt function
     * returns integer passed by argument
     */
    static int retInt(int n) {
        return n;
    }

    const std::string& str() {
        return _str;
    }

    void setStr(const std::string& s) {
        _str = s;
    }

    template <typename T>
    static T const& max(T const& a, T const& b) {
       return a < b ? b : a;
    }

    private:
        std::string _str;
};

template <typename T>
class Adder {
    public:
    static T add(T a, T b) {
        return a + b;
    }
};

enum color {
    RED,
    GREEN,
    BLUE
};

}

#endif
