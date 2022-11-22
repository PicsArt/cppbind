#ifndef MACRO_MAX_HPP
#define MACRO_MAX_HPP


#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

/**
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: globs
 * swift.name: maxInteger
 */
int maxInt(int a, int b);

#include "cxx/globs/min.h"


#endif
