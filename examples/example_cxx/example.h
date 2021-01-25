#include<string>

namespace pi::utils {
    /**
     * comments
     * 
     * __API__
     * gen: class
     * package: utils
     * shared_ref: False
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
        Type f(Type t, int i =10, const char* test = "XXX");

        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        int get_attribute(const char* test = "XXX");
    };
    /**
     * comments
     * 
     * __API__
     * gen: enum
     * swift.name: ExampleType
     */
    enum class Type2 { A2, B2, C2 };
}
