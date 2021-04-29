from functions.functional_pygen import FunctionalExamples

# [functional-usage]
f = FunctionalExamples()
assert f.gen_func_to_increment_result(lambda x: x * x)(5) == 26
assert FunctionalExamples.gen_func_to_increment_result(lambda x: x + x)(5) == 11
# [functional-usage]
