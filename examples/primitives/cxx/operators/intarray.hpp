#ifndef intarray_h
#define intarray_h

#include <string>

namespace iegen::example {

const int SIZE = 10;
// [example]
/**
 * An example for with overloaded operators.
 * __API__
 * action: gen_interface
 * package: operators
 */
class IntArray {
public:
    /**
     * __API__
     * action: gen_constructor
     * throws: no_throw
     */
	IntArray() {
	    for(int i = 0; i < SIZE; i++) {
           arr[i] = i;
        }
	}

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	int& operator[](int i) {
         if( i > SIZE ) {
            return arr[0];
         }
         return arr[i];
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	const int& operator[](std::string i) {
	     int ii = std::stoi(i);
         if( ii > SIZE ) {
            return arr[0];
         }
         return arr[ii];
    }

    /**
     * __API__
     * action: gen_method
     * throws: no_throw
     */
	int operator[](double i) {
	     int ii = static_cast<int>(i);
         if( ii > SIZE ) {
            return arr[0];
         }
         return arr[ii];
    }

private:
	int arr[10];
};
// [example]
}
#endif