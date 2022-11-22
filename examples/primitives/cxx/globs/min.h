#ifndef MACRO_MIN_HPP
#define MACRO_MIN_HPP


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
/**
 * __API__
 * action: gen_function
 * throws: no_throw
 * package: globs
 */
int minInt(int a, int b);
__END_DECLS

#endif
