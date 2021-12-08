/**
 * ,--.,------. ,----.   ,------.,--.  ,--. 
 * |  ||  .---''  .-.|   |  .---'|  ,'.|  | 
 * |  ||  `--, |  | .---.|  `--, |  |' '  | 
 * |  ||  `---.'  '--'  ||  `---.|  | `   | 
 * `--'`------' `------' `------'`--'  `--' 
 * 
 * This file is generated by iegen on 12/07/2021-16:20.
 * Please do not change it manually.
 */

#include <string.h>
#include <memory>
#include "swift/wrappers/misc/c_size_buffer.h"
#include "cxx/misc/size_buffer.hpp"

using namespace iegen::example;

void release_SizeUsage(void* _Nonnull cself) {
    delete static_cast<iegen::example::SizeUsage*>(cself);
}

CDataPair _func_SizeUsage_multiplyBy(CDataPair size, int n, ErrorObj* _Nonnull err){
    auto first_tmp_size = *reinterpret_cast<float*>(size.first);
    auto second_tmp_size = *reinterpret_cast<float*>(size.second);
    SizeF ctocxxsize { first_tmp_size, second_tmp_size };
  
    
  
    try {
        const auto& result = iegen::example::SizeUsage::multiplyBy(ctocxxsize, n);
        auto _first_data_cxxtocresult = new float;
        auto _second_data_cxxtocresult = new float;
        *_first_data_cxxtocresult = result.width;
        *_second_data_cxxtocresult = result.height;
        CDataPair cxxtocresult = { _first_data_cxxtocresult, _second_data_cxxtocresult };
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CDataPair result;
    return result;
}

CDataPair _func_SizeUsage_doubleSizeF(CDataPair resolution, ErrorObj* _Nonnull err){
    auto first_tmp_resolution = *reinterpret_cast<float*>(resolution.first);
    auto second_tmp_resolution = *reinterpret_cast<float*>(resolution.second);
    const SizeF & ctocxxresolution { first_tmp_resolution, second_tmp_resolution };
  
    try {
        const auto& result = iegen::example::SizeUsage::doubleSizeF(ctocxxresolution);
        auto _first_data_cxxtocresult = new float;
        auto _second_data_cxxtocresult = new float;
        *_first_data_cxxtocresult = result.width;
        *_second_data_cxxtocresult = result.height;
        CDataPair cxxtocresult = { _first_data_cxxtocresult, _second_data_cxxtocresult };
        return cxxtocresult;
    }
    catch (const std::exception& e) {
        err->err_type = 1;
        err->err_ptr = new std::exception(e);
    }
    catch (...) {
        err->err_type = -1;
    }
    CDataPair result;
    return result;
}