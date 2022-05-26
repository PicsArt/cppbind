#include <vector>

namespace cppbind {

class Array {
public:
    Array() {}

    int front() const {
        return _elements.front();
    }

    int back() const {
        return _elements.back();
    }

    void push_back(int element) {
        _elements.push_back(element);
    }

    int size() const {
        return _elements.size();
    }

    bool empty() const {
        return _elements.empty();
    }

    int& operator[] (int i) {
        return _elements[i];
    }

    int at(int i) const {
        return _elements.at(i);
    }

private:
    std::vector<int> _elements;
};

}
