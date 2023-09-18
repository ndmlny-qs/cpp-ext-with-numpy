from setuptools import Extension, setup
from setuptools_scm import get_version

setup(
    name="hello-lib",
    version=get_version(),
    ext_modules=[Extension(name="_hello", sources=["src/_hello.cpp"])],
)
