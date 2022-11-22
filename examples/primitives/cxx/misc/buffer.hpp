#ifndef buffer_hpp
#define buffer_hpp
// This is an example of a classes that do not have cppbind api but have custom wrappers and cppbind converters.
#include <iostream>
#include <string>

namespace cppbind::example {

template <typename T>
class Buffer {
    public:
    Buffer() {}

    std::string print() {
        return "buffer print";
    }
};

template <typename T>
struct Size {
    T width;
    T height;

    Size(T w, T h): width(w), height(h) {}
};

}
#endif
