import os

TEST_DIR = os.path.dirname(os.path.abspath(__file__))
TEST_CXX_DIR = os.path.join(TEST_DIR, "test_cxx_examples")
TEST_OUT_DIR = os.path.join(TEST_DIR, "test_out")
TEST_RULES_DIR = os.path.join(TEST_DIR, "test_rules")

os.makedirs(TEST_OUT_DIR, exist_ok=True)
