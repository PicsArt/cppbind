#include <string.h>
#include <memory>
#include "swift/wrappers/hello_user/exception_helpers/c_std_exceptions.h"

void release_std_exception(void* _Nonnull cself) {
    delete dynamic_cast<std::exception*>(static_cast<std::exception*>(cself));
}

const char * _Nullable _func_std_exception_what(void* _Nonnull cself){
    auto c_to_cxx_cself = dynamic_cast<std::exception*>(static_cast<std::exception*>(cself));
    const auto& result = c_to_cxx_cself->what();
    return result;
}