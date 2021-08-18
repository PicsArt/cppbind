namespace Example {
/**
 * __API__
 * action: gen_class
 * a: ParentValue
 */
class ExampleClass {
    public:

    /**
     * __API__
     * action: gen_method
     * a: "{{a}}InChild"
     * b: "Used{{a}}"
     * h:
     *  - "{{h[0]}}"
     *  - "NewValue"
     */
    void ExampleMethod() {
    }
};

/**
 * __API__
 * action: gen_class
 */
class AnotherExampleClass {
    public:

    /**
     * __API__
     * action: gen_method
     * b: "{{b}}"
     * c: AnotherValueOfC
     * e: "{{f}}UsedInE"
     * h: "{{h + ['NewValue']}}"
     */
    void AnotherExampleMethod() {
    }
};
}
