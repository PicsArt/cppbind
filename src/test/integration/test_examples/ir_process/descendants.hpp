#ifndef test_hpp
#define test_hpp

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C1 {};

// for checking node lookup in case of typedef
typedef C1 C1Ref;

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C2 : public C1Ref {};

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

typedef C9 C9Ref;

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C10 : public C9Ref {};

/**
 * __API__
 * kotlin.action: gen_class
 * package: test
 */
class C11 : public C10 {};

/**
 * An example to check the list of descendants for templated classes.
 * __API__
 * action: gen_class
 * package: test
 * template:
 *   T:
 *     - type: int
 *     - type: double
 */
template <typename T>
class C12 {};

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C13 : public C12<int> {};

/**
 * __API__
 * action: gen_class
 * package: test
 */
class C14 : public C12<double> {};

/**
 * __API__
 * action: gen_class
 * package: test
 * template:
 *   Type:
 *     - type: int
 */
template <typename Type>
class C15 : public C12<Type> {};

// examples for checking the case of template types with namespace
namespace example {

/**
 * __API__
 * action: gen_class
 * package: test
 * template:
 *   T:
 *     - type: int
 */
template <typename T>
class C16 {};

/**
 * __API__
 * action: gen_class
 * package: test
 * template:
 *   V:
 *     - type: int
 */
template <typename V>
class C17 : public example::C16<V> {};

/**
 * __API__
 * action: gen_class
 * package: test
 * template:
 *   U:
 *     - type: int
 */
template <typename U>
class C18 : public example::C17<U> {};

}

#endif
