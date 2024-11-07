from setuptools import find_packages
from setuptools import setup

setup(
    name='beginner_tutorials',
    version='0.0.0',
    packages=find_packages(
        include=('beginner_tutorials', 'beginner_tutorials.*')),
)
