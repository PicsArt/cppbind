
namespace iegen::example {

/**
 * comments
 *
 * __API__
 * gen: class
 * package: classes
 */
class Room {
public:
    /**
     * comments
     *
     * __API__
     * gen: method
     */
    double calculateArea(){
        return length * breadth;
    }


    /**
     * comments
     *
     * __API__
     * gen: method
     */
    double calculateVolume(){
        return length * breadth * height;
    }

private:
    double length;
    double breadth;
    double height;

};
}