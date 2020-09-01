/**
 * comments
 * 
 * __API__
 * kotlin.file: utils
 * kotlin.module: pi.xxx 
 * swift.prefix: PI
 */
namespace pi::utils {
    /**
     * commants
     * 
     * __API__
     * gen: class
     * shared_ref: False
     */
    struct Example
    {
        /**
         * commants
         * 
         * __API__
         * gen: enum
         * swift.name: ExampleType
         */
        enum class Type { A, B, C };



        /**
         * commants
         * 
         * __API__
         * gen: constructor
         * 
         */
        Example(int& x, std::shared_ptr<Type> t, std::string name = "XXX");

        /**
         * commants
         * 
         * __API__
         * gen: method
         */
        Type f(Type* t);
    };
}
