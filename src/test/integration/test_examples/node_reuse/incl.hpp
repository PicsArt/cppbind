// A namespace example to check namespace reuse logic
namespace example {
/**
 * A class example inside namespace have namespace node in IR
 * __API__
 * action: gen_class
 */
class Incl {};
}

/**
 * A class example to check class node reuse logic
 * __API__
 * action: gen_class
 */
class Incl {};

/**
 * A function example to check function node reuse logic
 * __API__
 * action: gen_method
 * throws: no_throw
 */
void Func() {}
