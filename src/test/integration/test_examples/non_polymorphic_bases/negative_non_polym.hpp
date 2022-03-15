 class NonPolymorphicBase1 {};

 /**
 * __API__
 * action: gen_class
 */
 class NonPolymorphicBase2 {};

 /**
 * Added a class in the middle of the hierarchy to check also that we consider not only classes with API
 */
 class MiddleClassWithoutAPI : public NonPolymorphicBase1, public NonPolymorphicBase2 {};

 /**
 * __API__
 * action: gen_class
 */
 class ChildClass : public MiddleClassWithoutAPI {};
