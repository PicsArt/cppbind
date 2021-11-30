import glob
import os
from setuptools import setup, find_packages

entry_point = (
    "iegen = iegen.runner:run_package"
)


with open("src/requirements.txt", "r") as f:
    requires = []
    for line in f:
        req = line.split("#", 1)[0].strip()
        if req and not req.startswith("--"):
            requires.append(req)

setup(
    name='iegen',
    version="0.0.1",
    description="Image Engine Wrapper Generator.",
    packages=find_packages('src/.', exclude=['test*']),
    package_dir={'': 'src'},
    # this is hack need to find proper way
    package_data={'iegen': [os.path.relpath(f, 'src/iegen/')
                            for f in glob.glob('src/iegen/config/**/*', recursive=True)]},
    entry_points={"console_scripts": [entry_point]},
    install_requires=requires,
    python_requires='>=3.6',
)
