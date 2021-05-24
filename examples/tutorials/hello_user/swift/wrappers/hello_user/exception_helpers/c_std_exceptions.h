#ifndef _C_std_exceptions_WRAPPER_
#define _C_std_exceptions_WRAPPER_

#if __cplusplus
extern "C" {
#endif
void release_std_exception(void* _Nonnull cself);
const char * _Nullable _func_std_exception_what(void* _Nonnull cself);
#if __cplusplus
}
#endif
#endif /* ifndef _C_std_exceptions_WRAPPER_ */