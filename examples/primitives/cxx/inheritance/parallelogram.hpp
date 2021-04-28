#ifndef parallelogram_hpp
#define parallelogram_hpp

#include <string>

namespace iegen::example {

/**
 * comments
 *
 * __API__
 * gen: interface
 * shared_ref: False
 * package: inheritance
 * swift.include: CWrapper
 */
class Parallelogram {
public:

    Parallelogram() {};

    /**
     * __API__
     * gen: getter
     */
    virtual double area() const = 0;

    /**
     * __API__
     * gen: method
     */
    virtual double perimeter() const = 0;

    virtual ~Parallelogram() = default;
};

}
#endif