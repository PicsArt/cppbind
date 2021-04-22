#include <string.h>
#include <memory>
#include "swift/wrappers/containers/c_containers.h"
#include "cxx/containers/containers.hpp"

void release_Item(void* _Nonnull cself){
        delete dynamic_cast<iegen::example::Item*>(static_cast<iegen::example::Item*>(cself));
}
int _prop_get_Item_value(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Item*>(static_cast<iegen::example::Item*>(cself));
    auto result = c_to_cxx_cself->value;
    
    return result;
}
void _prop_set_Item_value(void* _Nonnull cself, int value){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Item*>(static_cast<iegen::example::Item*>(cself));
    
    c_to_cxx_cself->value = value;
}

void* _Nonnull create_Item(int _value){
    
    auto this_object = new iegen::example::Item(_value);
    return static_cast<iegen::example::Item*>(this_object);
}
void release_Containers(void* _Nonnull cself){
        delete dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
}
void* _Nonnull create_Containers(){
    auto this_object = new iegen::example::Containers();
    return static_cast<iegen::example::Containers*>(this_object);
}
void _func_Containers_addStringPair(void* _Nonnull cself , CDataPair info){
    auto first_tmp_info = *reinterpret_cast<char* _Nonnull*>(info.first);
    auto second_tmp_info = *reinterpret_cast<char* _Nonnull*>(info.second);
    auto c_to_cxx_first_tmp_info = std::string(first_tmp_info);
        free(first_tmp_info);
    auto c_to_cxx_second_tmp_info = std::string(second_tmp_info);
        free(second_tmp_info);
    std::pair<std::string, std::string> c_to_cxx_info { c_to_cxx_first_tmp_info, c_to_cxx_second_tmp_info };
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
  c_to_cxx_cself->addStringPair(c_to_cxx_info);
}
void _func_Containers_addIntMap(void* _Nonnull cself , CDataMap info){
    std::map<int, int> c_to_cxx_info;

    for (size_t _i = 0; _i < info.size; ++_i) {
        auto ktmp_info = reinterpret_cast<int*>(info.keys)[_i];
        auto vtmp_info = reinterpret_cast<int*>(info.values)[_i];
        
        
        c_to_cxx_info.insert({ ktmp_info, vtmp_info });
    }
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
  c_to_cxx_cself->addIntMap(c_to_cxx_info);
}
void _func_Containers_addStringMap(void* _Nonnull cself , CDataMap info){
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
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
  c_to_cxx_cself->addStringMap(c_to_cxx_info);
}
void _func_Containers_addIntPair(void* _Nonnull cself , CDataPair info){
    auto first_tmp_info = *reinterpret_cast<int*>(info.first);
    auto second_tmp_info = *reinterpret_cast<int*>(info.second);


    std::pair<int, int> c_to_cxx_info { first_tmp_info, second_tmp_info };
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
  c_to_cxx_cself->addIntPair(c_to_cxx_info);
}
CDataPair _func_Containers_getStringPair(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
    const auto& result = c_to_cxx_cself->getStringPair();
    auto _first_data_cxx_to_c_result = new char* _Nonnull;
    auto _second_data_cxx_to_c_result = new char* _Nonnull;
    const auto& first_result = result.first;
    const auto& second_result = result.second;
    auto cxx_to_c_first_result = strdup(first_result.c_str()); 
    auto cxx_to_c_second_result = strdup(second_result.c_str()); 
    *_first_data_cxx_to_c_result = cxx_to_c_first_result;
    *_second_data_cxx_to_c_result = cxx_to_c_second_result;
    CDataPair cxx_to_c_result = { _first_data_cxx_to_c_result, _second_data_cxx_to_c_result };
    return cxx_to_c_result;
}
CDataMap _func_Containers_getStringMap(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
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
CDataMap _func_Containers_getIntMap(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
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
CDataMap _func_Containers_getMap(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
    const auto& result = c_to_cxx_cself->getMap();
    auto _k_data_cxx_to_c_result = new char* _Nonnull [result.size()];
    auto _v_data_cxx_to_c_result = new void* _Nonnull [result.size()];
    CDataMap cxx_to_c_result = { _k_data_cxx_to_c_result, _v_data_cxx_to_c_result, (long long)result.size() };
    size_t _i_result = 0;
    for (auto& value : result) {
        const auto& key = value.first;
        const auto& val = value.second;
        {
          auto cxx_to_c_key = strdup(key.c_str()); 
          auto value_ptr_val = const_cast<iegen::example::Item*>( new iegen::example::Item(val) );
        auto cxx_to_c_val = static_cast<iegen::example::Item*>(value_ptr_val);
          _k_data_cxx_to_c_result[_i_result] = cxx_to_c_key;
          _v_data_cxx_to_c_result[_i_result] = cxx_to_c_val;
          _i_result += 1;
        }
    }
    return cxx_to_c_result;
}
void _func_Containers_addIntVector(void* _Nonnull cself , CDataArray v){
    std::vector<int> c_to_cxx_v;

    auto data_v = reinterpret_cast<int*>(v.data);

    for (size_t _i = 0; _i < v.size; ++_i) {
        auto& value_v = data_v[_i];
        
        c_to_cxx_v.emplace_back(value_v);
    }
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
  c_to_cxx_cself->addIntVector(c_to_cxx_v);
}
void _func_Containers_addStringVector(void* _Nonnull cself , CDataArray v){
    std::vector<std::string> c_to_cxx_v;

    auto data_v = reinterpret_cast<char* _Nonnull*>(v.data);

    for (size_t _i = 0; _i < v.size; ++_i) {
        auto& value_v = data_v[_i];
        auto c_to_cxx_value_v = std::string(value_v);
        free(value_v);
        c_to_cxx_v.emplace_back(c_to_cxx_value_v);
    }
  
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
  c_to_cxx_cself->addStringVector(c_to_cxx_v);
}
CDataArray _func_Containers_getStringVector(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
    const auto& result = c_to_cxx_cself->getStringVector();
    auto _data_cxx_to_c_result = new char* _Nonnull [result.size()];
    CDataArray cxx_to_c_result = { _data_cxx_to_c_result, (long long)result.size() };
    for (int _i = 0; _i < result.size(); ++_i) {
      auto& value_result = result[_i];
      auto cxx_to_c_value_result = strdup(value_result.c_str()); 
      _data_cxx_to_c_result[_i] = cxx_to_c_value_result;
    }
    return cxx_to_c_result;
}
CDataArray _func_Containers_getIntVector(void* _Nonnull cself ){
    auto c_to_cxx_cself = dynamic_cast<iegen::example::Containers*>(static_cast<iegen::example::Containers*>(cself));
    const auto& result = c_to_cxx_cself->getIntVector();
    auto _data_cxx_to_c_result = new int [result.size()];
    CDataArray cxx_to_c_result = { _data_cxx_to_c_result, (long long)result.size() };
    for (int _i = 0; _i < result.size(); ++_i) {
      auto& value_result = result[_i];
      
      _data_cxx_to_c_result[_i] = value_result;
    }
    return cxx_to_c_result;
}