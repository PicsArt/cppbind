#include<string>
#include<vector>
#include<map>

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
        Example(int x, std::string name = "XXX");
        /**
         * comments
         * 
         * __API__
         * gen: constructor
         * 
         */
        Example(int x);

        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        double f(float t, int i =10);

        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        std::string get_attribute(const char* test = "XXX");
        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        std::vector<int> get_attribute(std::vector<Example*> test);
        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        std::map<int, int> get_attribute(std::map<int, Example*> test);
    };
    /**
     * comments
     * 
     * __API__
     * gen: class
     * package: utils
     * shared_ref: False
     */
    class Example1 : public Example
    {

        /**
         * comments
         * 
         * __API__
         * gen: constructor
         * 
         */
        Example1(int x, std::string name = "XXX");

        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        std::map<int, int> get_attribute(std::map<int, Example*> test);
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
