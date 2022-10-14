#include <memory>
#include <cmath>

namespace cppbind::example {
// [example-start]
const double PI = 3.14;

/**
 * An example marked with shared_ref=True and directly inherited from std::enable_shared_from_this
 * Contains a method which returns a reference on this.
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 */
class Shape : public std::enable_shared_from_this<Shape> {
public:
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    virtual double area() const = 0;

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Shape& thisObject() {
        return *this;
    }

    virtual ~Shape() = default;
};

/**
 * An example marked with shared_ref=True and indirectly inherited from std::enable_shared_from_this.
 * Contains a method returning a pointer on this.
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 */
class Circle : public Shape {
public:
    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
     static std::shared_ptr<Circle> create(double r) {
        return std::shared_ptr<Circle>(new Circle(r));
     }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    virtual double area() const { return PI * _radius * _radius; }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    Circle* incrementRadius(double value = 1.0) {
        _radius += value;
        return this;
    }


private:
    Circle(double r) : _radius(r) {}
    Circle(const Circle&) = default;
    Circle& operator=(const Circle& other) = default;

    Circle(Circle&& other) = default;
    Circle& operator=(Circle&& other) = default;
    double _radius;
};


/**
 * An example without an API and indirectly inherited from std::enable_shared_from_this.
 * Used as a base type for another type having API and marked with shared_ref=True.
 */
class Triangle : public Shape {
public:
    Triangle(double side1, double side2, double side3)
      : _side1(side1), _side2(side2), _side3(side3) {}

    double area() const override{
        double s = (_side1 + _side2 + _side3) / 2;
        return sqrt(s * (s - _side1) * (s - _side2) * (s - _side3));
    }

protected:
    double _side1;
    double _side2;
    double _side3;
};

/**
 * An example marked with shared_ref=True, indirectly inherited from std::enable_shared_from_this from a base having no API.
 * Contains a method returning reference on this.
 * __API__
 * action: gen_class
 * shared_ref: True
 * package: inheritance
 */
class RegularTriangle : public Triangle {

public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
    RegularTriangle(double side)
      : Triangle(side, side, side) {}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    double area() const override {
        return (sqrt(3) / 4) * (_side1 * _side1);
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    RegularTriangle& incrementSide(double value = 1.0) {
        _side1 = _side2 = _side3 = _side1 + value;
        return *this;
    };

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
    RegularTriangle multiplySide(double value = 1.0) {
        _side1 = _side2 = _side3 = _side1 * value;
        return *this;
    };

};
// [example-end]
} // namespace cppbind::example
