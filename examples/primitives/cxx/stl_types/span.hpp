#ifndef span_examples_h
#define span_examples_h

#include <span>
#include <vector>
#include <string>


namespace cppbind::example {

/**
 * comments
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: stl_types
 */
int sumSpan(std::span<int> items){
    int s = 0;
    for (auto& item:items){
        s+=item;
    }
    return s;
}

/**
 * comments
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: stl_types
 */
std::span<int> getSpan(std::span<int> items){
    return items;
}

/**
 * comments
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: stl_types
 */
std::span<int,2> getSpan2(std::span<int,2> items){
    return items;
}


}

#endif