#include <string>
#include <vector>
#include <map>
#include <memory>
/**
 * comments
 * 
 * __API__
 * kotlin.file: utils
 * kotlin.package: utils
 * kotlin.include: android.os.Parcel
 * kotlin.include: android.os.Test
 * kotlin.prefix: PI
 */
namespace pi::utils {
    using namespace std;
    /**
     * comments
     * 
     * __API__
     * gen: class
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
     */
    enum class Type2 { A2, B2=10, C2 };
    /**
     * comments
     * 
     * __API__
     * gen: class
     * shared_ref: False
     * kotlin.module: pi.xxx.Example
     */
    class Example2 : public Example, std::string
    {
        using example_t = std::shared_ptr<Example>;
        using ExampleVec = std::vector<example_t>;
        using ExampleMap = map<string, ExampleVec>;
        /**
         * comments
         * 
         * __API__
         * gen: constructor
         * 
         */
        Example2(Example2* parent);

        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        ExampleVec get_examples();
        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        ExampleMap get_examples_map();
    };
}
