
namespace test_api{

/**
 * /brief testing enum
 * testing comments
 * __API__
 * gen: enum
 * name: test
 */
enum RoomType{rt_notspecified, rt_leavingroom, rt_bedroom};

/**
 * /brief testing
 * testing comments
 * __API__
 * gen: class
 * name: test
 */
class Person {

    /**
     * /brief testing
     * testing comments
     * __API__
     * gen: method
     * name: test
     * throws: no_throw
     */
    int age() const{
        if(true)
            return 23;
        else
            return 43;
    }
};


class Room {
public:
    void add_person(Person person)
    {
        // do stuff
    }

private:
    Person* people_in_room;
};


template <class T, int N>
class Bag{
};
}

int main()
{
    using namespace test_api;
    Person* p = new Person();
    Bag<Person, 42> bagofpersons;

    return 0;
}