#!/usr/bin/env python3
from setuptools import setup, Extension, find_packages


extension = Extension(
    name="_segfault",
    sources=["segfault/src/_segfault.c"],
    include_dirs=["segfault/inc/"],
    #extra_compile_args=['-fsanitize=address']
)


setup(
    name='segfault-demo',
    ext_modules=[extension],
    packages=find_packages('segfault'),
    entry_points = {
        'console_scripts': ['segfault=segfault.segfault:main']
    }
)
