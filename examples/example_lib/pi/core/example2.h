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
    class Example2 : public Example
    {
        using example_t = const Example&;
        //using example_t = std::shared_ptr<Example>;
        using ExampleVec = std::vector<example_t>;
        using ExampleMap = map<string, example_t>;
        using example2_t = long;
        using Example2Vec = std::vector<example2_t>;
        using Example2Map = map<string, example2_t>;
        using Example3Map = map<string, ExampleVec>;
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
        ExampleVec get_examples(){return ExampleVec()}
        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        ExampleMap get_examples_map();
        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        void set_examples_map(const ExampleMap& data_map, const Example2Map& data2_map, const Example3Map& data3_map);
        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        void set_examples(ExampleVec data_vec, Example2Vec data2_vec);
        /**
         * comments
         * 
         * __API__
         * gen: method
         */
        Example2Vec get_examples2_vec();
    };
}
#endif
