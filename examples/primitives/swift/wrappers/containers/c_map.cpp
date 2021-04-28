#include <string.h>
#include <memory>
#include "swift/wrappers/containers/c_map.h"
#include "cxx/containers/map.hpp"

using namespace iegen::example;
void release_MapItem(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::MapItem*>(static_cast<iegen::example::MapItem*>(cself));
}
int _prop_get_MapItem_value(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::MapItem*>(static_cast<iegen::example::MapItem*>(cself));
    auto result = c_to_cxx_cself->value;
    
    return result;
}
void _prop_set_MapItem_value(void* _Nonnull cself, int value){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::MapItem*>(static_cast<iegen::example::MapItem*>(cself));
    
    c_to_cxx_cself->value = value;
}

void* _Nonnull create_MapItem(int _value){
    
    auto this_object = new iegen::example::MapItem(_value);
    return static_cast<iegen::example::MapItem*>(this_object);
}
using namespace iegen::example;
void release_MapExamples(void* _Nonnull cself) {
    delete dynamic_cast<iegen::example::MapExamples*>(static_cast<iegen::example::MapExamples*>(cself));
}
void* _Nonnull create_MapExamples(){
    auto this_object = new iegen::example::MapExamples();
    return static_cast<iegen::example::MapExamples*>(this_object);
}
void _func_MapExamples_addStringPair(void* _Nonnull cself , CDataPair info){
    auto first_tmp_info = *reinterpret_cast<char* _Nonnull*>(info.first);
    auto second_tmp_info = *reinterpret_cast<char* _Nonnull*>(info.second);
    auto c_to_cxx_first_tmp_info = std::string(first_tmp_info);
        free(first_tmp_info);
    auto c_to_cxx_second_tmp_info = std::string(second_tmp_info);
        free(second_tmp_info);
    std::pair<std::string, std::string> c_to_cxx_info { c_to_cxx_first_tmp_info, c_to_cxx_second_tmp_info };
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::MapExamples*>(static_cast<iegen::example::MapExamples*>(cself));
  c_to_cxx_cself->addStringPair(c_to_cxx_info);
}
void _func_MapExamples_addIntMap(void* _Nonnull cself , CDataMap info){
    std::map<int, int> c_to_cxx_info;

    for (size_t _i = 0; _i < info.size; ++_i) {
        auto ktmp_info = reinterpret_cast<int*>(info.keys)[_i];
        auto vtmp_info = reinterpret_cast<int*>(info.values)[_i];
        
        
        c_to_cxx_info.insert({ ktmp_info, vtmp_info });
    }
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::MapExamples*>(static_cast<iegen::example::MapExamples*>(cself));
  c_to_cxx_cself->addIntMap(c_to_cxx_info);
}
void _func_MapExamples_addStringMap(void* _Nonnull cself , CDataMap info){
    std::map<std::string, std::string> c_to_cxx_info;

    for (size_t _i = 0; _i < info.size; ++_i) {
        auto ktmp_info = reinterpret_cast<char* _Nonnull*>(info.keys)[_i];
        auto vtmp_info = reinterpret_cast<char* _Nonnull*>(info.values)[_i];
        auto c_to_cxx_ktmp_info = std::string(ktmp_info);
        free(ktmp_info);
        auto c_to_cxx_vtmp_info = std::string(vtmp_info);
        free(vtmp_info);
        c_to_cxx_info.insert({ c_to_cxx_ktmp_info, c_to_cxx_vtmp_info });
    }
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::MapExamples*>(static_cast<iegen::example::MapExamples*>(cself));
  c_to_cxx_cself->addStringMap(c_to_cxx_info);
}
CDataMap _func_MapExamples_getStringMap(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::MapExamples*>(static_cast<iegen::example::MapExamples*>(cself));
    const auto& result = c_to_cxx_cself->getStringMap();
    auto _k_data_cxx_to_c_result = new char* _Nonnull [result.size()];
    auto _v_data_cxx_to_c_result = new char* _Nonnull [result.size()];
    CDataMap cxx_to_c_result = { _k_data_cxx_to_c_result, _v_data_cxx_to_c_result, (long long)result.size() };
    size_t _i_result = 0;
    for (auto& value : result) {
        const auto& key = value.first;
        const auto& val = value.second;
        {
          auto cxx_to_c_key = strdup(key.c_str()); 
          auto cxx_to_c_val = strdup(val.c_str()); 
          _k_data_cxx_to_c_result[_i_result] = cxx_to_c_key;
          _v_data_cxx_to_c_result[_i_result] = cxx_to_c_val;
          _i_result += 1;
        }
    }
    return cxx_to_c_result;
}
CDataMap _func_MapExamples_getIntMap(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::MapExamples*>(static_cast<iegen::example::MapExamples*>(cself));
    const auto& result = c_to_cxx_cself->getIntMap();
    auto _k_data_cxx_to_c_result = new int [result.size()];
    auto _v_data_cxx_to_c_result = new int [result.size()];
    CDataMap cxx_to_c_result = { _k_data_cxx_to_c_result, _v_data_cxx_to_c_result, (long long)result.size() };
    size_t _i_result = 0;
    for (auto& value : result) {
        const auto& key = value.first;
        const auto& val = value.second;
        {
          
          
          _k_data_cxx_to_c_result[_i_result] = key;
          _v_data_cxx_to_c_result[_i_result] = val;
          _i_result += 1;
        }
    }
    return cxx_to_c_result;
}
void _func_MapExamples_addMixedMap(void* _Nonnull cself , CDataMap info){
    std::map<std::string, MapItem> c_to_cxx_info;

    for (size_t _i = 0; _i < info.size; ++_i) {
        auto ktmp_info = reinterpret_cast<char* _Nonnull*>(info.keys)[_i];
        auto vtmp_info = reinterpret_cast<void* _Nonnull*>(info.values)[_i];
        auto c_to_cxx_ktmp_info = std::string(ktmp_info);
        free(ktmp_info);
        
        // we might need to avoid dynamic_cast if there is no multiple inheritance
        auto& c_to_cxx_vtmp_info = *dynamic_cast<iegen::example::MapItem*>(static_cast<iegen::example::MapItem*>(vtmp_info));
        c_to_cxx_info.insert({ c_to_cxx_ktmp_info, c_to_cxx_vtmp_info });
    }
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::MapExamples*>(static_cast<iegen::example::MapExamples*>(cself));
  c_to_cxx_cself->addMixedMap(c_to_cxx_info);
}
CDataMap _func_MapExamples_getMixedMap(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::MapExamples*>(static_cast<iegen::example::MapExamples*>(cself));
    const auto& result = c_to_cxx_cself->getMixedMap();
    auto _k_data_cxx_to_c_result = new char* _Nonnull [result.size()];
    auto _v_data_cxx_to_c_result = new void* _Nonnull [result.size()];
    CDataMap cxx_to_c_result = { _k_data_cxx_to_c_result, _v_data_cxx_to_c_result, (long long)result.size() };
    size_t _i_result = 0;
    for (auto& value : result) {
        const auto& key = value.first;
        const auto& val = value.second;
        {
          auto cxx_to_c_key = strdup(key.c_str()); 
          auto value_ptr_val = const_cast<iegen::example::MapItem*>( new iegen::example::MapItem(val) );
        auto cxx_to_c_val = static_cast<iegen::example::MapItem*>(value_ptr_val);
          _k_data_cxx_to_c_result[_i_result] = cxx_to_c_key;
          _v_data_cxx_to_c_result[_i_result] = cxx_to_c_val;
          _i_result += 1;
        }
    }
    return cxx_to_c_result;
}