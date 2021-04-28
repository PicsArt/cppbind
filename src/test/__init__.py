import os

TEST_DIR = os.path.dirname(os.path.abspath(__file__))
TEST_CXX_DIR = os.path.join(TEST_DIR, "test_cxx_inputs")
TEST_OUT_DIR = os.path.join(TEST_DIR, "test_out")
TEST_RULES_DIR = os.path.join(TEST_DIR, "helper_rules")

os.makedirs(TEST_OUT_DIR, exist_ok=True)
