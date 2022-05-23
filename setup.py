# Copyright (c) 2022 PicsArt, Inc.
# All rights reserved. Use of this source code is governed by a
# MIT-style license that can be found in the LICENSE file.

import glob
import os
from setuptools import setup, find_packages

entry_point = (
    "cppbind = cppbind.runner:run_package"
)

with open("src/requirements.txt", "r") as f:
    requires = []
    for line in f:
        req = line.split("#", 1)[0].strip()
        if req and not req.startswith("--"):
            requires.append(req)

setup(
    name='cppbind',
    version="0.0.1",
    description="C++ Bindings Generator.",
    packages=find_packages('src/.', exclude=['test*']),
    package_dir={'': 'src'},
    # this is hack need to find proper way
    package_data={'cppbind': [os.path.relpath(f, 'src/cppbind/')
                             for f in glob.glob('src/cppbind/config/**/*', recursive=True)]},
    entry_points={"console_scripts": [entry_point]},
    install_requires=requires,
    python_requires='>=3.6',
)
