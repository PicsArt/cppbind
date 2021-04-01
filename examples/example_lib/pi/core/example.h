#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include <string>
#include <vector>
#include <map>
#include <memory>

namespace pi::utils {
    using namespace std;
    /**
     * comments
     * 
     * __API__
     * gen: class
     * kotlin.file: utils
     * package: utils
     * kotlin.include: android.os.Parcel
     * kotlin.include: android.os.Test
     * kotlin.prefix: PI
     * shared_ref: False
     * kotlin.module: pi.xxx.Example
     */
    struct Example
    {
        /**
         * comments
         * 
         * __API__
         * gen: enum
         * swift.name: ExampleType
         */
        enum class Type { A, B, C };
        typedef Type type_t;


        /**
         * comments
         * 
         * __API__
         * gen: constructor
         * 
         */
        Example(int& x, std::string name = "XXX");

        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        Type f(Type* t, const char* t2 = nullptr, size_t i = 10, const string& test = "XXX");

        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        int set_attribute(type_t* test = NULL);

        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        int get_attribute();
    };
    /**
     * comments
     * 
     * __API__
     * gen: enum
     * swift.name: ExampleType
     * kotlin.file: utils
     * package: utils
     * kotlin.include: android.os.Parcel
     * kotlin.include: android.os.Test
     * kotlin.prefix: PI
     */
    enum class Type2 { A2, B2=10, C2 };
}

#endif
