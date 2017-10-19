#!/usr/bin/env python3
from setuptools import setup, Extension, find_packages


extension = Extension(
    name="_memleak",
    sources=["memleak/src/_memleak.c"],
    include_dirs=["memleak/inc/"]
)


setup(
    name='memleak',
    ext_modules=[extension],
    packages=find_packages('memleak'),
    entry_points = {
        'console_scripts': ['memleak=memleak.memleak:main']
    }
)
