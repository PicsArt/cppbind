/**
 * comments
 * 
 * __API__
 * kotlin_file: utils
 * kotlin_module: pi.xxx 
 * swift_prefix: PI
 */
namespace pi::utils {
    /**
     * commants
     * 
     * __API__
     * gen: class
     * shared_ref: False
     */
    class Example
    {
        /**
         * commants
         * 
         * __API__
         * gen: enum
         * swift_name: ExampleType
         */
        enum class Type { A, B, C };



        /**
         * commants
         * 
         * __API__
         * gen: constuctor
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
