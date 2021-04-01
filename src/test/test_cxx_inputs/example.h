/**
 * comments
 *
 * __API__
 * kotlin.module: pi.xxx
 * swift.prefix: PI
 */
namespace pi::utils {
    /**
     * comments
     * 
     * __API__
     * gen: class
     * swift.prefix: PI

     * shared_ref: False
     */
    class Example
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
        Example(int& x, std::shared_ptr<Type> t, std::string name = "XXX");

        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        Type f(Type* t);
    };
}
