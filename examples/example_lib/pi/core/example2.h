#ifndef __EXAMPLE2_H__
#define __EXAMPLE2_H__

#include "example.h"
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
         * wrapper: jet_get_examples
         */
        ExampleVec get_examples(){return ExampleVec()}
        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        ExampleMap get_examples_map();
    };
}
#endif
