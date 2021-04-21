import sys
import unittest
import filecmp
import os
import difflib


class TestFilesIdentical(unittest.TestCase):

    def setUp(self) -> None:
        self.gen_root = 'tests/iegen_out/%s/'
        self.examples_root = 'external/examples/%s/'
        self.languages = ['python', 'swift', 'kotlin']

    def test_files_are_identical(self):
        for language in self.languages:
            print(language.upper())
            diff_files = []
            gen_root = self.gen_root % language
            examples_root = self.examples_root % language
            for root, _, files in os.walk(gen_root):
                common_path = root[len(gen_root):]
                for file in files:
                    examples_file = os.path.join(examples_root, common_path, file)
                    gen_file = os.path.join(root, file)
                    print(f'comparing {examples_file}, {gen_file}')
                    identical = filecmp.cmp(gen_file, examples_file)
                    if not identical:
                        diff_files.append((gen_file, examples_file))
            # log first 3 files diff for each language
            for diff_pair in diff_files[:3]:
                with open(diff_pair[0], 'r') as gf:
                    with open(diff_pair[1], 'r') as ef:
                        sys.stderr.write(f'Diff for {diff_pair[0]} - {diff_pair[1]}')
                        sys.stderr.writelines(difflib.unified_diff(gf.readlines(), ef.readlines()))


if __name__ == '__main__':
    unittest.main()
