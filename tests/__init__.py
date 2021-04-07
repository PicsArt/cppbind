import os

TEST_DIR = os.path.dirname(os.path.abspath(__file__))
TEST_OUT_DIR = os.path.join(TEST_DIR, "test_out")

os.makedirs(TEST_OUT_DIR, exist_ok=True)
