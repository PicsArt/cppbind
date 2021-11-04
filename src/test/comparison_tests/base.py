import difflib
import os
import shutil
import sys
import types
import unittest

from iegen.runner import run

SCRIPT_DIR = os.path.dirname(os.path.realpath(__file__))


class ComparisonTestsBaseClass:

    def __init__(self, examples_dir, ctx_descriptor, languages=None):
        self.languages = languages or ['kotlin', 'swift', 'python']
        self.test_dir = os.getcwd()
        self.gen_root = './'
        self.examples_root = examples_dir
        self.ctx_descriptor = ctx_descriptor

    def test_compare(self):

        # run iegen
        run(types.SimpleNamespace(plat_lang_options=self.languages), self.ctx_descriptor)

        # remove source to not compare
        source_path = self.gen_root + 'cxx'
        if os.path.exists(source_path) and os.path.isdir(source_path):
            shutil.rmtree(source_path)

        # compare generated files with golden ones
        diff_files = []
        gen_root = self.gen_root
        examples_root = self.examples_root
        for root, _, files in os.walk(gen_root):
            common_path = root[len(gen_root):]
            for file in files:
                examples_file = os.path.join(examples_root, common_path, file)
                gen_file = os.path.join(root, file)
                print(f'comparing {examples_file}, {gen_file}')
                with open(examples_file, "rt") as f1:
                    with open(gen_file, "rt") as f2:
                        f1 = filter(filter_iegen_date_line, f1)
                        f2 = filter(filter_iegen_date_line, f2)
                        identical = all(x == y for x, y in zip(f1, f2))
                        if not identical:
                            diff_files.append((gen_file, examples_file))
        if diff_files:
            for diff_pair in diff_files[:3]:
                with open(diff_pair[0], 'r') as gf:
                    with open(diff_pair[1], 'r') as ef:
                        sys.stderr.write(f'Diff for {diff_pair[0]} - {diff_pair[1]}')
                        sys.stderr.writelines(difflib.unified_diff(gf.readlines(), ef.readlines()))
            raise AssertionError


def filter_iegen_date_line(line):
    if 'generated by iegen on' in line:
        return False
    return True


if __name__ == '__main__':
    unittest.main()
