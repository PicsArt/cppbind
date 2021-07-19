// This is an example of a classes that do not have iegen api but have custom wrappers and iegen converters.
#include <iostream>
#include <string>

namespace iegen::example {

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
