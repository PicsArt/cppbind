#ifndef test_hpp
#define test_hpp

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C1 {};

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C2 : public C1 {};

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C3 : public C1 {};

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C4 : public C2 {};

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C5 : public C2 {};

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C6 : public C3 {};

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C7 : public C6 {};

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C8 : public C6 {};

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C9 : public C7, public C8 {};

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C10 : public C9 {};


#endif