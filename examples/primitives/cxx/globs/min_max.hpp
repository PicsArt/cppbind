#ifndef MACROS_MINMAX_HPP
#define MACROS_MINMAX_HPP

#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS extern "C" {
# define __END_DECLS }
#else
# define __BEGIN_DECLS /* empty */
# define __END_DECLS /* empty */
#endif

__BEGIN_DECLS

#include "cxx/globs/min.h"
#include "cxx/globs/max.h"

__END_DECLS

#endif
