load("@io_bazel_rules_kotlin//kotlin:kotlin.bzl", "kt_jvm_test")

kt_jvm_test(
    name = "classes",
    srcs = glob(["src/**/*.kt"]),
    data = ["//kotlin/wrappers:libwrapper_jni.so"],
    jvm_flags = ["-Djava.library.path=kotlin/wrappers"],
    main_class = "com.examples.classes.ClassesApp",
)
