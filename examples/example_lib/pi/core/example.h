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
        int set_attribute(const char* test = "XXX");

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
}
