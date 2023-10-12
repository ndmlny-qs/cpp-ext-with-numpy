from pathlib import Path

import numpy
from setuptools import Extension, setup
from setuptools_scm import get_version

setup(
    name="trig",
    version=get_version(),
    ext_modules=[
        Extension(
            name="trig",
            sources=[str(p) for p in (Path(__file__).parent / "src").glob("*.cpp")],
            include_dirs=[numpy.get_include()]
        ),
    ],
)
