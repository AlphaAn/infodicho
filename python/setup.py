from setuptools import setup, Extension
import pybind11
import sys

# Define the C++ extension module
ext_modules = [
    Extension(
        "somim_module",
        sorted([
            "somim_wrapper.cpp",      # The wrapper source
            "../core/libsomim.cpp",   # The core logic source
        ]),
        include_dirs=[
            pybind11.get_include(),   # Path to pybind11 headers
            "../core"                 # Path to libsomim.h
        ],
        language="c++",
        extra_compile_args=["-std=c++11", "-O3"],  # Optimization flags
    ),
]

setup(
    name="somim",
    version="2.0.0",
    description="Python interface for SOMIM (Search for Optimal Measurements by an Iterative Method))",
    ext_modules=ext_modules,
    zip_safe=False,
)